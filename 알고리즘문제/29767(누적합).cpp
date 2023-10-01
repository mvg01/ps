#include <iostream>
#include <algorithm>
using namespace std;

//자료형 때문에 계속 틀린 문제. 자료형 신경쓰자
long long a[300001]; 
long long sum[300001] = { 0 };
bool compare(long long i, long long j) {
	return i > j;
}

int main()
{
	int n, k;
	long long res = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0)
			sum[i] = a[i];
		else
			sum[i] = sum[i - 1] + a[i];
	}
	sort(sum, sum + n, compare);

	for (int i = 0; i < k; i++) {
		res += sum[i];
		cout << sum[i] << ' ';
	}

	cout << res;
}