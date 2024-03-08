#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, ans = 0;
deque<int>d;
vector<int>v;
void input() {
    int x;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 10)
            ans++;
        else if (x % 10 == 0)
            v.push_back(x);
        else if (x > 10)
            d.push_back(x);
    }
}
void solve() {
    if (!v.empty()) {
        sort(v.begin(), v.end());  //오름차순
        for (int i = v.size() - 1; i >= 0; i--)
            d.push_front(v[i]);
    }
    for (int i = 0; i < m; i++) {
        if (d.empty())  //더이상 자를 수 있는 케이크 없음
            break;
        int x = d.front();
        d.pop_front();
        if (x % 10 == 0) {
            x -= 10;
            if (x >= 20) {
                d.push_front(x);
                ans++;
            }
            else  // q.front가 20이었을 때
                ans += 2;
        }
        else {
            x -= 10;
            ans++;
            if (x > 10)
                d.push_back(x);
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}