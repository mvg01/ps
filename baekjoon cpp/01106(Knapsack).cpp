#include <bits/stdc++.h>
using namespace std;

/*
1. 0-1 Knapsack
특징: 각 아이템을 최대 1번만 선택 가능
예시: 도시 홍보를 한 번만 할 수 있는 경우

2. Bounded Knapsack
특징: 각 아이템을 최대 k번 선택 가능 (k > 1)
예시: 도시 홍보를 최대 3번까지 할 수 있는 경우

3. Unbounded Knapsack
특징: 각 아이템을 무제한으로 선택 가능
예시: 도시 홍보를 원하는 만큼 반복할 수 있는 경우
*/

int c, n, w[21], v[21], dp[100001];

void solve()
{
    for (int i = 0; i <= 100000; i++)
        dp[i] = -1;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = w[i]; j <= 100000; j++) // unbounded knapsack
        {
            if (dp[j - w[i]] != -1)
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    for (int i = 0; i <= 100000; i++)
    {
        if (dp[i] >= c)
        {
            cout << i;
            return;
        }
    }
}

void input()
{
    cin >> c >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}