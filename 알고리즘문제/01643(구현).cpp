#include <iostream>
#include <algorithm>
#include <cmath>
using ll = long long;
using namespace std;

ll gcd(ll x, ll y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

void input() {
    int n;
    while (1) {
        cin >> n;
        if (cin.eof()) break;
        if (n == 1) cout << 1 << '\n';
        else if (n == 2)cout << 3 << '\n';
        else {
            ll a = 0, b = 2, c;   // c*a/b 
            for (ll i = 3; i <= n; i++) {
                b = lcm(i, b);
            }
            for (ll i = 1; i <= n; i++)
                a += b / i;
            b /= n;
            c = a / b;
            a = a % b;
            ll g = gcd(a, b);
            a /= g;
            b /= g;
            //cout << c << ' ' << a << ' ' << b << ' ' << '\n';
            int b1 = 0, c1 = 0;  // 분모 자릿수, 자연수 자릿수
            ll temp = c;
            while (temp) {
                temp /= 10;
                c1++;
            }
            temp = b;
            while (temp) {
                temp /= 10;
                b1++;
            }
            for (int i = 0; i <= c1; i++)
                cout << ' ';
            cout << a << '\n' << c << ' ';
            for (int i = 0; i < b1; i++)
                cout << '-';
            cout << '\n';
            for (int i = 0; i <= c1; i++)
                cout << ' ';
            cout << b << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}