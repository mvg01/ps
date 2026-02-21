#include <bits/stdc++.h>
using namespace std;

int n;
string s;
void input()
{
    cin >> n;
    int pre = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "/")
        {
            int temp = pre;
            pre += 10;
            if (pre % 10 != 0)
                pre -= pre % 10;
            cout << pre << '\n';
            pre = temp;
            continue;
        }
        int x = stoi(s);
        pre = max(pre, x);
        cout << x << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}