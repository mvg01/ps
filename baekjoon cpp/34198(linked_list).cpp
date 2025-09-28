#include <bits/stdc++.h>
using namespace std;

int n, q, a[300001];
vector<int> ans;
list<int> l;
// 이터레이터는 불변, value마다 이터레이터 고정하여 find, remove 사용 X
unordered_map<int, list<int>::iterator> pos;

// list::splice(pos, other, first, last)
// 노드포인터 first, last구간을 other에서 pos의 앞쪽으로 옮긴다.

void solve()
{
    for (auto it = l.begin(); it != l.end(); it++)
        pos[*it] = it;
    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        if (l.empty())
            continue;
        if (s == "SF")
        {
            int temp = l.front();
            l.pop_front();
            l.push_back(temp);
        }
        else if (s == "SL")
        {
            int temp = l.back();
            l.pop_back();
            l.push_front(temp);
        }
        else if (s == "SM")
        {
            int x;
            cin >> x;
            auto it = pos[x];
            if (it == l.end())
                continue;
            auto nx = next(it);
            if (nx == l.end())
                l.splice(l.begin(), l, it); // it가 가리키는 원소를 l.begin 으로 옮김
            else
            {
                auto first = l.begin();
                l.splice(l.begin(), l, nx, l.end()); // nx부터 end까지 리스트의 맨 앞으로 옮김
                l.splice(first, l, it);              // x(찾은 원소)를 원래 맨 앞의 원소의 앞으로 옮김
            }
        }
        else if (s == "PF")
        {
            ans.push_back(l.front());
            l.pop_front();
        }
        else if (s == "PL")
        {
            ans.push_back(l.back());
            l.pop_back();
        }
        else if (s == "PM")
        {
            int x;
            cin >> x;
            ans.push_back(x);
            l.erase(pos[x]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            cout << ans[i] << ' ';
        else
            cout << ans[i];
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        l.push_back(a[i]);
    }
    cin >> q;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}