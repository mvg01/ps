#include <bits/stdc++.h>
using namespace std;

int n, p, x;
void solve()
{
    // 자신의 턴에 xor의 결과가 0인 것은 진 것을 의미
    // xor은 한 번의 연산으로 결과를 0으로 바꿀 수 있음
    if (x == 0)
        cout << "cubelover";
    else
        cout << "koosaga";
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        x ^= p;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}