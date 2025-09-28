#include <bits/stdc++.h>
using namespace std;

int n, a[1000001];
vector<int> lis;

void solve()
{
    lis.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (lis.back() < a[i])
            lis.push_back(a[i]);
        else
        {
            int start = 0, end = lis.size() - 1, lisidx = 0;
            while (start <= end)
            {
                int mid = (start + end) / 2;
                if (lis[mid] < a[i])
                {
                    start = mid + 1;
                    lisidx = mid + 1;
                }
                else
                    end = mid - 1;
            }
            lis[lisidx] = a[i];
        }
    }
    cout << lis.size();
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}