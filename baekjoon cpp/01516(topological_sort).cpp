#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

int n, m;
vector<int>v[501];
int res[501] = { 0 };
int in[501], t[501];

void input() {
    int b;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> b;
        if (b != -1) {
            while (1) {
                v[b].push_back(i);
                in[i]++;  //진입 차수
                cin >> b;
                if (b == -1)
                    break;
            }
        }
    }
}

void solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //first값 기준 min heap
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            pq.push({ t[i],i });
            res[i] = t[i];
        }
    }
    while (!pq.empty()) {
        int s = pq.top().second;
        int tt = pq.top().first;
        pq.pop();
        for (int i = 0; i < v[s].size(); i++) {
            int x = v[s][i];
            in[x]--;
            if (in[x] == 0) {
                pq.push({ tt + t[x],x });
                res[x] = tt + t[x];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}

/*  유용했던 반례 -> 두 번째의 결과값이 19가 나오지 않게 해야한다.
6
10 -1
10 1 6 -1
4 1 -1
4 3 1 -1
3 3 -1
9 -1

ans:
10
20
14
18
17
9
*/