//첫 번째 풀이: 삼각형의 위에서 아래로 내려가면서 나올 수 있는 모든 값을 저장한다.
//마지막에 가장 큰 dp 결과값을 찾아서 출력한다.
#include <iostream>
using namespace std;

int n, res = 0;
int tri[501][501];
int dp[501][501] = { 0 };  //삼각형의 가장 왼쪽, 오른쪽 부분만 따로 생각하자
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++)
			cin >> tri[i][j];
	}

	dp[0][0] = tri[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)  //삼각형의 가장 왼쪽 dp
				dp[i][j] = dp[i - 1][j] + tri[i][j];
			else if (i == j)  //삼각형의 가장 오른쪽 dp
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			else { 
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) 
		res = max(dp[n - 1][i], res);
	
	cout << res;	
}

//두 번째 풀이: 삼각형의 아래에서부터 나올 수 있는 큰 값을 더해가면서 올라간다.
//그렇게되면 꼭대기에는 가장 큰 값이 저장된다.
#include <iostream>
using namespace std;

int n, res = 0;
int tri[501][501];
int dp[501][501] = { 0 }; 
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++)
			cin >> tri[i][j];
	}
	for (int i = n - 1; i >= 0; i--) {  //아래에서 위로 큰 값 저장해가면서 올라가기
		for (int j = 0; j <= i; j++) {
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + tri[i][j];
		}
	}
	cout << dp[0][0];	
}