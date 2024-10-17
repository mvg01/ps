#include <bits/stdc++.h>
using namespace std;

int t, n;
int visited[121];
int dir[5] = { 60,10,-10,1,-1 };

typedef struct {
    int a[5];
}cnt;
cnt c;

void bfs(cnt c) {
    queue<pair<int, cnt>>q;
    c.a[0] = n / 60;  // n이 터무니없이 큰 경우
    q.push({ 0,c });  // 0분에서 시작해서 목표 분수를 도달하는 것을 목적으로
    visited[0] = 1;
    n %= 60;
    int chk = 0;
    vector<cnt>v;
    while (!q.empty()) {
        int x = q.front().first;
        cnt temp = q.front().second;
        q.pop();
        if (x == n) {
            for (int i = 0; i < 5; i++)
                cout << temp.a[i] << ' ';
            cout << '\n';
            return;
        }
        for (int i = 4; i >=0; i--) {  // 정렬 기준에 맞추기 위함
            cnt te = temp;
            int y = x + dir[i];
            te.a[i]++;
            if (y > 120 || y < 0) 
                continue;
            if (visited[y])
                continue;
            q.push({ y,te });
            visited[y] = 1;
        }
    }
}

void input() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        bfs(c);
        for (int j = 0; j < 5; j++)
            c.a[j] = 0;
        for (int j = 0; j < 121; j++)
            visited[j] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}