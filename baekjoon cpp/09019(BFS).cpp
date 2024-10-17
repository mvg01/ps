#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t, a, b;
int visited[10001];

string bfs(int s, int e) {
    queue<pair<int,string>>q;
    q.push({ s,"" });
    visited[s] = 1;
    while (!q.empty()) {
        int num = q.front().first;
        string r = q.front().second;
        q.pop();
        if (num == e) 
            return r;
        int temp = (num * 2) % 10000;
        if (!visited[temp]) {
            q.push({ temp,r + "D" });
            visited[temp] = 1;
        }
        temp = num - 1;
        if (temp == -1)
            temp = 9999;
        if (!visited[temp]) {
            q.push({ temp,r + "S" });
            visited[temp] = 1;
        }
        int le = num * 10 / 10000 + num * 10 % 10000;
        if (!visited[le]) {
            q.push({ le,r + "L" });
            visited[le] = 1;
        }
        int ri = num % 10 * 1000 + num / 10;
        if (!visited[ri]) {
            q.push({ ri,r + "R" });
            visited[ri] = 1;
        }
    }
}

void input() {
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << bfs(a, b) << '\n';
        for (int i = 0; i < 10000; i++) visited[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}