#include <iostream>
#include <algorithm>
using namespace std;

int n, a[101];
void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
bool c(int i, int j) {
    return i > j;
}

void solve() {
    int ans = 0;
    for (int i = 0; i <= 1440; i++) {
        int x = -1, y = -1;
        sort(a, a + n, c);  //가장 큰 값 2개 빼기
        for (int j = 0; j < n; j++) {
            if (x == -1 && a[j] > 0) 
                x = j;
            else if (x != -1 && y == -1 && a[j] > 0) {
                y = j;
                a[x]--;
                a[y]--;
                break;
            }
        }
        if (x == -1 && y == -1) {
            cout << i;
            return;
        }
        else if (y == -1) 
            a[x]--;  
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}