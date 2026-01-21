#include <bits/stdc++.h>
#define MAX 5000000
using namespace std;

int n, e[MAX + 1];
void solve()
{
    // Smallest Prime Factor, 가장 작은 소인수 저장
    for (int i = 0; i <= MAX; i++)
        e[i] = i;
    for (int i = 2; i <= sqrt(MAX); i++)
    {
        if (e[i] < i)
            continue;
        for (int j = i + i; j <= MAX; j += i)
        {
            if (e[j] == j)
                e[j] = i;
        }
    }
}

void input()
{
    cin >> n;
    solve();
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vector<int> v;
        while (k > 1)
        { // 소인수분해
            v.push_back(e[k]);
            k /= e[k];
        }
        sort(v.begin(), v.end());
        for (int j : v)
            cout << j << ' ';
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}