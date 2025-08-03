#include <bits/stdc++.h>
using namespace std;

int q;
vector<int> v;

void solve()
{
}

void input()
{
    cin >> q;
    while (q--)
    {
        int a, b, c;
        cin >> a >> b;
        if (a == 1)
        {
            if (b == 1)
                sort(v.begin(), v.end());
            else
                sort(v.begin(), v.end(), greater<int>());
        }
        else
        {
            cin >> c;
            if (v.size() <= b)
                v.push_back(c);
            else
                v.insert(v.begin() + b, c);
        }
    }
    cout << v.size() << '\n';
    for (auto i : v)
        cout << i << ' ';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}