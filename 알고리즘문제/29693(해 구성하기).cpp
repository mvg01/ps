#include <iostream>
using namespace std;

int y, x;
char mat[101][1001];
void input() {
    cin >> y >> x;
    for (int i = 0; i < y; i++)
        cin >> mat[i];
}

void solve() {
    bool chk = 0;
    for (int i = 0; i < y; i++) {
        if (chk)
            break;
        if (x % 2 == 1) {
            if (mat[i][x / 2 - 1] == 'X' && mat[i][x / 2] == 'X' && mat[i][x / 2 + 1] == 'X') {
                chk = 1;
                mat[i][x / 2 - 1] = 'W';
                mat[i][x / 2] = 'Y';
                mat[i][x / 2 + 1] = 'W';
            }
        }
        else {
            if (mat[i][x / 2 - 2] == 'X' && mat[i][x / 2 - 1] == 'X' && mat[i][x / 2] == 'X'&& mat[i][x / 2 + 1] == 'X') {
                chk = 1;
                mat[i][x / 2 - 2] = 'W';
                mat[i][x / 2 - 1] = 'Y';
                mat[i][x / 2] = 'Y';
                mat[i][x / 2 + 1] = 'W';
            }
        }
    }
    if (chk) {
        cout << "YES\n";
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (mat[i][j] == 'X')
                    cout << 'B';
                else
                    cout << mat[i][j];
            }
            cout << '\n';
        }
    }
    else
        cout << "NO";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}