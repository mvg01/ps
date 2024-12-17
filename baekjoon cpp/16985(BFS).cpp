#include <bits/stdc++.h>
using namespace std;

int mat[5][5][5], vis[5][5][5];
int d[6][3] = { {0,-1,0}, {0,1,0},{0,0,1},{0,0,-1},{-1,0,0},{1,0,0} };
int ans = 1e8;
vector<int> v = { 0, 1, 2, 3, 4 };

void rotate(int(&a)[5][5]) {
    int temp[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            temp[j][4 - i] = a[i][j];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            a[i][j] = temp[i][j];
    }
}


void bfs(int temp[5][5][5]) {
    queue<tuple<int, int, int>>q;
    if (temp[0][0][0])
        q.push({ 0,0,0 });
    vis[0][0][0] = 1;
    while (q.size()) {
        auto [z, y, x] = q.front();
        if (z == 4 && y == 4 && x == 4) {
            ans = min(ans, vis[z][y][x] - 1);
            break;
        }
        q.pop();
        for (int i = 0; i < 6; i++) {
            int zz = z + d[i][0];
            int yy = y + d[i][1];
            int xx = x + d[i][2];
            if (zz < 0 || zz >= 5 || yy < 0 || yy >= 5 || xx < 0 || xx >= 5)
                continue;
            if (vis[zz][yy][xx])
                continue;
            if (temp[zz][yy][xx]) {
                q.push({ zz,yy,xx });
                vis[zz][yy][xx] = vis[z][y][x] + 1;
            }
        }
    }
}

void solve() {
    do {
        int temp[5][5][5];
        for (int r1 = 0; r1 < 4; r1++) {
            rotate(mat[v[0]]);
            for (int r2 = 0; r2 < 4; r2++) {
                rotate(mat[v[1]]);
                for (int r3 = 0; r3 < 4; r3++) {
                    rotate(mat[v[2]]);
                    for (int r4 = 0; r4 < 4; r4++) {
                        rotate(mat[v[3]]);
                        for (int r5 = 0; r5 < 4; r5++) {
                            rotate(mat[v[4]]);

                            for (int i = 0; i < 5; i++) {
                                for (int j = 0; j < 5; j++) {
                                    for (int k = 0; k < 5; k++) {
                                        vis[i][j][k] = 0;
                                        temp[i][j][k] = mat[v[i]][j][k];
                                    }
                                }
                            }
                            for (int i : v)
                                bfs(temp);
                        }
                    }
                }
            }
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << (ans == 1e8 ? -1 : ans);
}

void input() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) 
                cin >> mat[i][j][k];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}