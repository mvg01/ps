#include <iostream>
using namespace std;

int dp[100001];
int main() 
{
	int n;
	cin >> n;
	dp[1] = 1; dp[2] = 1;
	dp[3] = 2; dp[4] = 2;
	dp[5] = 1; dp[6] = 2;
	dp[7] = 1; 
	for (int i = 8; i <= 100000; i++) {
		dp[i] = min(min(dp[i - 1] + 1, dp[i - 2] + 1), min(dp[i - 5] + 1, dp[i - 7] + 1));
	}
	cout << dp[n];
}