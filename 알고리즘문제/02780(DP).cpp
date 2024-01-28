#include <iostream>
#include <vector>
using namespace std;

int dp[1001][10];
vector<vector<int>> dir = { {1,3},{0,2,4},{1,5},{0,4,6},{1,3,5,7},{2,4,8},{3,7,9},{4,6,8},{5,7},{6} };
void solve() {
    for (int i = 0; i < 10; i++) 
        dp[1][i] = 1;
    for (int i = 2; i <= 1000; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < dir[j].size(); k++) {
                dp[i][j] += dp[i - 1][dir[j][k]];
                dp[i][j] %= 1234567;
            }
        }
    }
}

void input() {
    solve();
    int x, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        int sum = 0;
        for (int j = 0; j < 10; j++) {
            sum += dp[x][j];
            sum %= 1234567;
        }
        cout << sum << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}