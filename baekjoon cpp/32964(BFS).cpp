#include <bits/stdc++.h>
using namespace std;

int n;
char mat[2][200001];
void solve()
{
    mat[1][n - 1] = 'L';
    queue<tuple<int, int, int>> q;
    if (mat[1][0] == 'L')
        q.push({1, 0, 2});
    if (mat[0][1] == 'I')
        q.push({0, 1, 0});
    else
        q.push({0, 1, 4});
    while (q.size())
    {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int t = get<2>(q.front());
        q.pop();
        if (x == n - 1)
        {
            if (y == 0 && mat[y][x] != 'I')
            {
                cout << "YES";
                return;
            }
            if (y == 1)
            {
                cout << "YES";
                return;
            }
            continue;
        }
        if (y == 0 && t == 4)
        {
            if (mat[1][x] == 'L')
                q.push({1, x, 2});
        }
        if (y == 0 && t == 0)
        {
            if (mat[0][x + 1] == 'L')
                q.push({0, x + 1, 4});
            if (mat[0][x + 1] == 'I')
                q.push({0, x + 1, 0});
        }
        if (y == 0 && t == 3)
        {
            if (mat[0][x] == 'L')
            {
                if (mat[0][x + 1] == 'L')
                    q.push({0, x + 1, 4});
                if (mat[0][x + 1] == 'I')
                    q.push({0, x + 1, 0});
            }
        }
        if (y == 1 && t == 5)
        {
            if (mat[1][x] == 'L')
                q.push({0, x, 3});
        }
        if (y == 1 && t == 2)
        {
            if (mat[1][x] == 'L')
            {
                if (mat[1][x + 1] == 'L')
                    q.push({1, x + 1, 5});
                if (mat[1][x + 1] == 'I')
                    q.push({1, x + 1, 0});
            }
        }
        if (y == 1 && t == 0)
        {
            if (mat[1][x + 1] == 'L')
                q.push({1, x + 1, 5});
            if (mat[1][x + 1] == 'I')
                q.push({1, x + 1, 0});
        }
    }
    cout << "NO";
}

void input()
{
    cin >> n >> mat[0] >> mat[1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}