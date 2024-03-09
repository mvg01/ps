#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char mat[9][9];
char mat2[9][9][9];
int dir[9][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1} };
queue<tuple<int, int, int>>q;

void input() {
    for (int i = 0; i < 8; i++)
        cin >> mat[i];
}

void solve() {
    for (int t = 0; t < 8; t++) {  // t초 동안 미로의 상황
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (i - t >= 0)
                    mat2[t][i][j] = mat[i - t][j];  
                else
                    mat2[t][i][j] = '.';
            }
        }  
    }
    bool chk = 0;
    q.push({ 7, 0, 0 });
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int t = get<2>(q.front());
        q.pop();
        if (y == 0) {  // y가 0이 되면 언제든 (0,7)로 이동 가능해짐
            chk = 1;
            break;
        }
        for (int i = 0; i < 9; i++) {
            int yy = y + dir[i][0];
            int xx = x + dir[i][1];
            if (yy >= 8 || yy < 0 || xx >= 8 || xx < 0)
                continue;
            if (t < 8) {  // 시간 상 내려올 벽이 남아있다.
                if (mat2[t + 1][yy][xx] == '#') // 다음에 벽이 내려올 예정이면 continue.
                    continue;
                if (mat2[t][yy][xx] == '.') {  // 현재 빈칸인 경우 이동
                    q.push({ yy,xx,t + 1 });
                }
            }
            else {  // 벽이 모두 내려갔기에 (7,0)으로 갈 수 있다.
                chk = 1;
                break;
            }
        }
        if (chk)
            break;
    }
    if (chk)
        cout << 1;
    else
        cout << 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}