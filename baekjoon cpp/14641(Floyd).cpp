#include <bits/stdc++.h>
#define INF 9999
using namespace std;

int m, n;
int mat[27][27];
void input() {
    char a, b;
    cin >> m >> n;
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 27; j++)
            mat[i][j] = INF;
    }
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 27; j++)
            if (i == j) mat[i][j] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        mat[a - 'a'][b - 'a'] = 1;
    }
}

void solve() {
    for (int k = 0; k <= 26; k++) {
        for (int i = 0; i <= 26; i++) {
            for (int j = 0; j <= 26; j++)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
        }
    }
    string s1, s2;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        if (s1.length() != s2.length()) 
            cout << "no\n";
        else {
            bool chk = 0;
            for (int j = 0; j < s1.length(); j++) {
                if (mat[s1[j] - 'a'][s2[j] - 'a'] == INF)
                    chk = 1;
            }
            if (chk)
                cout << "no\n";
            else
                cout << "yes\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}