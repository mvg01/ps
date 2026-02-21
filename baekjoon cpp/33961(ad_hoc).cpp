#include <bits/stdc++.h>
using namespace std;

int n;
void solve()
{
    if (n < 3)
    {
        cout << "NO";
        return;
    }
    int idx = 1;
    cout << "YES\n";
    if (n == 5)
    {
        cout << "2 4\n1 5\n2 3\n1 1\n2 2\n";
        cout << "1 4\n2 5\n1 3\n2 1\n1 2\n";
        return;
    }
    while (n > 0)
    { // n이 6이상인 수는 3과 4의 합으로 표현 가능
        if (n % 4 == 0)
        {
            int temp = idx;
            cout << "1 " << idx++ << '\n';
            cout << "2 " << idx++ << '\n';
            idx++;
            cout << "1 " << idx-- << '\n';
            cout << "2 " << idx-- << '\n';
            cout << "1 " << idx-- << '\n';
            cout << "2 " << idx++ << '\n';
            idx++;
            cout << "1 " << idx++ << '\n';
            cout << "2 " << idx++ << '\n';
            n -= 4;
        }
        else
        {
            int temp = idx;
            cout << "1 " << idx++ << '\n';
            cout << "2 " << idx++ << '\n';
            cout << "1 " << idx << '\n';
            idx = temp;
            cout << "2 " << idx++ << '\n';
            cout << "1 " << idx++ << '\n';
            cout << "2 " << idx++ << '\n';
            n -= 3;
        }
    }
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