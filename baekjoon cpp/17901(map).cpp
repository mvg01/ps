#include <bits/stdc++.h>
using namespace std;

int n, x;
unordered_map<int, int>m;

// 같은 숫자 중에 가장 거리가 가까운 사람의 거리 출력하는 문제입니다.  
void input() {
    cin >> n;
    int res = n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (m.find(x) != m.end()) {
            int dis = i - m[x];
            res = min(res, dis);
        }
        m[x] = i;
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}