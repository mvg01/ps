#include <iostream>
#include <vector>
using namespace std;

int x, y, t, dir, dis;
vector<pair<int, int>>v;
void input() {
    int a, b;
    cin >> x >> y >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        v.push_back({ a,b });
    }
    cin >> dir >> dis;
}

void solve() {  //dir 북 남 서 동
    int res = 0;
    for (int i = 0; i < t; i++) {
        int d = v[i].first;
        int e = v[i].second;
        if (dir == d) {
            res += abs(dis - e);
            continue;
        }
        if (dir == 1) {
            if (d == 2)
                res += min(dis + y + e, x - dis + y + x - e);
            else if (d == 3)
                res += dis + e;
            else
                res += x - dis + e;
        }
        else if (dir == 2) {
            if (d == 1)
                res += min(dis + y + e, x - dis + y + x - e);
            else if (d == 3)
                res += dis + y - e;
            else
                res += x - dis + y - e;
        }
        else if (dir == 3) {
            if (d == 1)
                res += e + dis;
            else if (d == 2)
                res += y - dis + e;
            else
                res += min(dis + x + e, y - dis + x + y - e);
        }
        else if (dir == 4) {
            if (d == 1)
                res += dis + x - e;
            else if (d == 2)
                res += y - dis + x - e;
            else
                res += min(dis + x + e, y - dis + x + y - dis - e);
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}