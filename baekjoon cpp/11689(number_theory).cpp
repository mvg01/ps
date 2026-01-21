#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 오일러 피 함수: 서로소인 자연수의 개수를 구함

ll n;
void solve()
{
    ll ans = n;
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {                      // i가 n의 소인수인 경우
            ans -= ans / i;    // 오일러 피 값을 갱신하는 핵심 연산
            while (n % i == 0) // 거듭제곱 모두 처리
                n /= i;
        }
    }
    // sqrt(n)보다 큰 소인수가 남아있는 경우 ex) 99인 경우 11이 소인수
    if (n > 1)
        ans -= ans / n;
    cout << ans;
}

void input()
{
    cin >> n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}