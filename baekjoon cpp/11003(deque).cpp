#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<int> a;

// 덱을 활용한 정렬효과 & 슬라이딩 윈도우
// 덱에 정렬된 원소가 저장되는 효과

void solve()
{
    deque<pair<int, int>> d;
    for (int i = 0; i < n; i++)
    {
        if (d.empty())
        {
            d.push_front({i, a[i]});
        }
        else
        {
            while (d.size())
            {
                if (d.back().second >= a[i])
                { // 덱의 back 원소는 가장 큰 원소가 되도록
                    d.pop_back();
                    if (d.empty())
                    { // a[i]가 지금까지 덱의 원소들보다 작은 경우
                        d.push_back({i, a[i]});
                        break;
                    }
                }
                else
                {
                    d.push_back({i, a[i]});
                    break;
                }
            }
            if (d.front().first <= i - l) // 윈도우 값 범위(l 값)을 벗어난 원소는 제거
                d.pop_front();
        }
        cout << d.front().second << ' '; // 덱의 front 원소는 가장 작은 원소
    }
}

void input()
{
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}