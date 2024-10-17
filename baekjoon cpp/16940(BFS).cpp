#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int>v[100001];
int c[100001];
queue<int>order;

void input() {
    int a, b;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a;
        c[a] = i;   // 우선적으로 pop되어야 하는 a 순위 i
        order.push(a);
    }
}

bool com(int i,int j) {
    return c[i] < c[j];
}

void solve() {
    for (int i = 1; i <= n; i++)  //우선순위 높은 순(순서 번호 낮은 순)
        sort(v[i].begin(), v[i].end(), com);

    queue<int>q;
    q.push(1);
    if (order.front() != 1) {
        cout << 0;
        return;
    }
    order.pop();
    while (!q.empty()) {
        int ver = q.front();
        q.pop();
        for (int i = 0; i < v[ver].size(); i++) {
            int next = v[ver][i];
            if (order.empty())  // bfs 종료
                break;
            else if (next == order.front()) {
                order.pop();
                q.push(next);
            }
        }
    }
    if (order.empty())
        cout << 1;
    else
        cout << 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}