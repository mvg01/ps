#include <iostream>
using namespace std;

string s;
int q, ar[26][200001];
void input() {
    cin >> s >> q;
}

void solve() {
    ar[s[0] - 97][0] = 1;
    int l = s.length();
    for (int i = 1; i < l; i++) {
        for (int j = 0; j < 26; j++) {
            if (s[i] - 97 == j)
                ar[j][i] = ar[j][i - 1] + 1;
            else
                ar[j][i] = ar[j][i - 1];
        }
    }
    char c;
    int a, b;
    while (q--) {
        cin >> c >> a >> b;
        if (a == 0)
            cout << ar[c - 97][b] << '\n';
        else
            cout << ar[c - 97][b] - ar[c - 97][a - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}