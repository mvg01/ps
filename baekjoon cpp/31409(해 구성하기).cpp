#include <iostream>
using namespace std;

int n;
int a[100001];
int res[100001] = { 0 };

void input() {
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == i) 
            cnt++;
        else
            res[i] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (res[i] == 0) {
            if (i != n)
                res[i] = i + 1;
            else
                res[i] = i - 1;
        }
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}