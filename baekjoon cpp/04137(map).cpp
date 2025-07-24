#include <bits/stdc++.h>
using namespace std;

int t;
unordered_map<string, int> m;
vector<pair<string, int>> v;

int change(char c)
{
    switch (c)
    {
    case 'A':
    case 'B':
    case 'C':
        return 2;
    case 'D':
    case 'E':
    case 'F':
        return 3;
    case 'G':
    case 'H':
    case 'I':
        return 4;
    case 'J':
    case 'K':
    case 'L':
        return 5;
    case 'M':
    case 'N':
    case 'O':
        return 6;
    case 'P':
    case 'R':
    case 'S':
        return 7;
    case 'T':
    case 'U':
    case 'V':
        return 8;
    case 'W':
    case 'X':
    case 'Y':
        return 9;
    default:
        return 0;
    }
}

void solve()
{
    for (auto i : m)
    {
        if (i.second > 1)
            v.push_back({i.first, i.second});
    }
    if (v.size() == 0)
    {
        cout << "No duplicates.\n";
        return;
    }
    sort(v.begin(), v.end());
    for (auto i : v)
        cout << i.first << ' ' << i.second << '\n';
}

void input()
{
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int len = s.length();
        string k = "";
        for (int i = 0; i < len; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                k += s[i];
            else if (s[i] >= 'A' && s[i] <= 'Z')
                k += '0' + change(s[i]);
        }
        k.insert(k.begin() + 3, '-');
        m[k]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}