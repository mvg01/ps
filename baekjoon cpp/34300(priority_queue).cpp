#include <bits/stdc++.h>
using namespace std;

int c, n[501], ans;
priority_queue<int> q;
void solve()
{
    while (q.size())
    {
        if (q.size() < 5)
        {
            ans += q.size();
            break;
        }
        ans += 5;
        vector<int> v;
        for (int i = 0; i < 5; i++)
        {
            int x = q.top() - 1;
            q.pop();
            v.push_back(x);
        }
        for (auto i : v)
        {
            if (i != 0)
                q.push(i);
        }
    }
    cout << ans;
}

void input()
{
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> n[i];
        q.push(n[i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}