#include <bits/stdc++.h>
using namespace std;

int n;
map<string, bool> m;
void solve()
{
}

void input()
{
    string s;
    while (1)
    {
        cin >> s;
        m.insert({s, 1});
        if (s == "XXXXXX")
        {
            while (1)
            {
                cin >> s;
                if (s == "XXXXXX")
                    return;
                sort(s.begin(), s.end());
                bool chk = 0;
                do
                {
                    if (m[s] == 1)
                    {
                        cout << s << '\n';
                        chk = 1;
                    }
                } while (next_permutation(s.begin(), s.end()));
                if (!chk)
                    cout << "NOT A VALID WORD\n";
                cout << "******\n";
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}