#include <iostream>
#include <vector>
using namespace std;

int dp[41];
vector<int>v;
int main()
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 40; i++) 
		dp[i] = dp[i - 1] + dp[i - 2];
	

	long res = 1;
	int n, m, x;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		v.push_back(x);
	}
	v.push_back(-1);

	int cnt = 0, idx = 0, temp;
	bool nochk = 0;
	if (m == 0)
		nochk = 1;  //고정석이 없는 경우

	for (int i = 1; i <= n; i++) {
		if (!nochk) {  //고정석이 아직 있을 수 있다.
			if (v[idx] != i) {
				cnt++;
				continue;
			}
		}

		if (v[idx] == i) {
			if (cnt != 0) {
				temp = dp[cnt];  //temp값은 자유롭게 배치 가능한 일반 좌석 경우의 수
				res *= temp;     //경우의 수 곱해주기
			}
			cnt = 0;  
			idx++;   //다음 고정석 나올 때 까지
			if (idx >= m)
				nochk = 1;  //더이상 고정석이 나오지 않음.
		}
		else  //고정석 끝, 나머진 자유석이므로 자유석 경우의 수 추출을 위한 cnt 증가
			cnt++;
	}

	if (cnt != 0) { //끝자석이 고정석이면 0 곱해지는 불상사
		temp = dp[cnt];
		res *= temp;
	}

	cout << res;
}
