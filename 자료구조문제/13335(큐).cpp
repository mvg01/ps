#include <iostream>
#include <queue>
using namespace std;

int n, w, l;
int a[1001];
void input() {
    cin >> n >> w >> l;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void solve() {
    int i, cur = 0, idx = 0;
    int res = 0;
    queue<int>q;
    for (i = 1; ; i++) {
        if (q.empty()) {  // 다리위에 아무것도 없는 경우 (처음)
            q.push(a[idx]);
            cur += a[idx++];
        }
        else {
            if (q.size() == w) { // 다리위가 꽉 찬 경우 가장 앞의 트럭을 빼줌
                cur -= q.front();
                q.pop();
            }
            if (cur + a[idx] <= l) { // 다른 트럭이 새로 들어올 수 있음
                q.push(a[idx]);
                cur += a[idx++];
            }
            else  // 다른트럭이 새로 들어올 하중이 안된다면 빈 공간 
                q.push(0);
        }
        if (idx == n) {
            res += w;  //마지막 트럭이 다리위로 올라오면 다리 길이 더하고 종료
            break;
        }
    }
    cout << i + res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}