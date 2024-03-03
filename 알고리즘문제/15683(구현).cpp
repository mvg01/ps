#include <iostream>
#include <vector>
using namespace std;

int n, m, ans = 64;
int dx1[4] = { 1,0,-1,0 };  // CCTV 1 기준 동,남,서,북
int dy1[4] = { 0,1,0,-1 };
int dx2[2][2] = { {-1,1},{0,0} }; // CCTV 2
int dy2[2][2] = { {0,0},{-1,1} };
int dx3[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };  // CCTV 3
int dy3[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int dx4[4][3] = { {-1,0,1},{0,1,0},{1,0,-1},{0,-1,0} };  // CCTV 4
int dy4[4][3] = { {0,-1,0},{-1,0,1},{0,1,0},{1,0,-1} };
int d5[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };  // CCTV 5

vector<pair<int, int>>v;
vector<pair<int, int>>five;  //CCTV 5번일 때 그냥 따로 처리함

void solve(int cnt, int mat[][8]) {
    if (cnt == v.size()) {
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] < 1)
                    c++;
            }
        }
        ans = min(ans, c);
        return;
    }
    int y = v[cnt].first;
    int x = v[cnt].second;
    int kind = mat[v[cnt].first][v[cnt].second];
    int temp[8][8];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            temp[i][j] = mat[i][j];
    }
    if (kind == 1) {
        for (int i = 0; i < 4; i++) {
            int yy = y + dy1[i];
            int xx = x + dx1[i];
            while (1) {
                if (temp[yy][xx] == 6 || yy >= n || yy < 0 || xx >= m || xx < 0) {
                    solve(cnt + 1, temp);
                    break;
                }
                else if (temp[yy][xx] == 0 || temp[yy][xx] == 9) {
                    temp[yy][xx] = 9;
                    yy += dy1[i];
                    xx += dx1[i];
                }
                else {
                    yy += dy1[i];
                    xx += dx1[i];
                }
            }
            for (int l = 0; l < n; l++) {
                for (int j = 0; j < m; j++)
                    temp[l][j] = mat[l][j];
            }
        }
    }
    if (kind == 2) {
        for (int p = 0; p < 2; p++) {
            for (int i = 0; i < 2; i++) {
                int yy = y + dy2[p][i];
                int xx = x + dx2[p][i];
                while (1) {
                    if (temp[yy][xx] == 6 || yy >= n || yy < 0 || xx >= m || xx < 0) {
                        if (i == 1)
                            solve(cnt + 1, temp);
                        break;
                    }
                    else if (temp[yy][xx] == 0 || temp[yy][xx] == 9) {
                        temp[yy][xx] = 9;
                        yy += dy2[p][i];
                        xx += dx2[p][i];
                    }
                    else {
                        yy += dy2[p][i];
                        xx += dx2[p][i];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++)
                    temp[i][j] = mat[i][j];
            }
        }
    }
    if (kind == 3) {
        for (int p = 0; p < 4; p++) {
            for (int i = 0; i < 2; i++) {
                int yy = y + dy3[p][i];
                int xx = x + dx3[p][i];
                while (1) {
                    if (temp[yy][xx] == 6 || yy >= n || yy < 0 || xx >= m || xx < 0) {
                        if (i == 1)
                            solve(cnt + 1, temp);
                        break;
                    }
                    else if (temp[yy][xx] == 0 || temp[yy][xx] == 9) {
                        temp[yy][xx] = 9;
                        yy += dy3[p][i];
                        xx += dx3[p][i];
                    }
                    else {
                        yy += dy3[p][i];
                        xx += dx3[p][i];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++)
                    temp[i][j] = mat[i][j];
            }
        }
    }
    if (kind == 4) {
        for (int p = 0; p < 4; p++) {
            for (int i = 0; i < 3; i++) {
                int yy = y + dy4[p][i];
                int xx = x + dx4[p][i];
                while (1) {
                    if (temp[yy][xx] == 6 || yy >= n || yy < 0 || xx >= m || xx < 0) {
                        if (i == 2)
                            solve(cnt + 1, temp);
                        break;
                    }
                    else if (temp[yy][xx] == 0 || temp[yy][xx] == 9) {
                        temp[yy][xx] = 9;
                        yy += dy4[p][i];
                        xx += dx4[p][i];
                    }
                    else {
                        yy += dy4[p][i];
                        xx += dx4[p][i];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++)
                    temp[i][j] = mat[i][j];
            }
        }
    }
}

void input() {
    cin >> n >> m;
    int mat[8][8];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] > 0 && mat[i][j] < 5)
                v.push_back({ i,j });
            else if (mat[i][j] == 5)
                five.push_back({ i,j });
        }
    }
    for (int z = 0; z < five.size(); z++) {  // 5번 CCTV는 미리 처리
        int i = five[z].first;
        int j = five[z].second;
        for (int l = 0; l < 4; l++) {
            int yy = i + d5[l][0];
            int xx = j + d5[l][1];
            while (1) {
                if (mat[yy][xx] == 6 || yy >= n || yy < 0 || xx >= m || xx < 0) {
                    break;
                }
                if (mat[yy][xx] == 0)
                    mat[yy][xx] = 9;
                yy += d5[l][0];
                xx += d5[l][1];
            }
        }
    }
    solve(0, mat);
    cout << ans;
}
    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}