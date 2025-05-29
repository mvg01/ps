#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> l;
unordered_map<string, vector<pair<int, string>>> um; // 키는 접두사 value는 인덱스와 원본 문자열

void solve()
{
    int mx = 0, idx = 20000;
    string s;
    for (auto i : um)
    {
        if (i.second.size() >= 2 && mx < i.first.length())
        {
            mx = i.first.length();
            s = i.first;
            idx = i.second[0].first;
        }
        else if (i.second.size() >= 2 && mx == i.first.length())
        {
            if (idx > i.second[0].first)
            {
                idx = i.second[0].first;
                mx = i.first.length();
                s = i.first;
            }
        }
    }

    if (mx == 0)
    { // 한 개라도 접두사가 같은 단어가 없다면
        cout << l[0] << '\n'
             << l[1];
        return;
    }
    sort(um[s].begin(), um[s].end()); // 앞 인덱스의 단어부터
    vector<pair<int, string>> v = um[s];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[0].second != v[i].second)
        {
            cout << v[0].second << '\n'
                 << v[i].second;
            return;
        }
    }
    // 같은 접두사가 겹칠 경우 ex) 3 a b a
    cout << l[0] << '\n'
         << l[1];
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string m;
        cin >> m;
        int len = m.length();
        l.push_back(m);
        for (int j = 1; j < len; j++)
        {
            string t = m.substr(0, j);
            um[t].push_back({i, m});
        }
        um[m].push_back({i, m});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}