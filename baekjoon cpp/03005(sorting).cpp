#include <bits/stdc++.h>
using namespace std;

vector<string> v;
char mat[21][21];
int r, c;

void solve()
{
    for (int i = 0; i < r; i++)
    {
        string s;
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] != '#')
                s += mat[i][j];
            else
            {
                if (s.length() > 1)
                    v.push_back(s);
                else
                    s.clear();
            }
        }
        if (s.length() > 1)
            v.push_back(s);
    }
    for (int i = 0; i < c; i++)
    {
        string s;
        for (int j = 0; j < r; j++)
        {
            if (mat[j][i] != '#')
                s += mat[j][i];
            else
            {
                if (s.length() > 1)
                    v.push_back(s);
                else
                    s.clear();
            }
        }
        if (s.length() > 1)
            v.push_back(s);
    }
    sort(v.begin(), v.end());
    cout << v[0];
}

void input()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        cin >> mat[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}