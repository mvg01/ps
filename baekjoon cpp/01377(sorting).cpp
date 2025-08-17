#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> a[500001];

// 핵심원리: 버블 정렬에서 원소가 왼쪽으로 가는 건 최대 1번
// 따라서 더이상 원소를 swap하지 않으려면, 가장 많이 왼쪽으로 이동해야하는 원소의 왼쪽으로 가는 횟수를 찾야아 한다.

void solve()
{
    sort(a, a + n);
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i].second - i > mx)
        {
            mx = max(mx, a[i].second - i);
        }
    }
    cout << mx + 1;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}