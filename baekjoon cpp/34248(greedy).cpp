#include <bits/stdc++.h>
using namespace std;

int n, a[200005];
vector<int> v;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
        while (1)
        {
            int size = v.size();
            bool chk = 0;
            if (size >= 2 && v[size - 1] + v[size - 2] == 3)
            {
                v.pop_back();
                v.pop_back();
                chk = 1;
            }
            if (!chk)
                break;
        }
    }
    while (v.size())
    {
        int size = v.size();
        bool chk = 0;
        if (size >= 2 && v[size - 1] + v[size - 2] == 3)
        {
            v.pop_back();
            v.pop_back();
            chk = 1;
        }
        else if (size >= 3 && v[size - 1] + v[size - 2] + v[size - 3] == 3)
        {
            v.pop_back();
            v.pop_back();
            v.pop_back();
            chk = 1;
        }
        if (!chk)
        {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}