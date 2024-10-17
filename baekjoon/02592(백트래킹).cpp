#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
long long ma = 0;
long long mi = 9999999999;
char k[10];
int visited[10] = { 0 };

void bt(int cnt,int prev, long long temp) {
	if (cnt == n) {
		ma = max(ma, temp);
		mi = min(mi, temp);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (k[cnt] == '<') {
			if (!visited[i] && prev < i) {
				visited[i] = 1;
				bt(cnt + 1, i, temp + i * (long long)pow(10, n - cnt - 1));
				visited[i] = 0;
			}
		}
		else {
			if (!visited[i] && prev > i) {
				visited[i] = 1;
				bt(cnt + 1, i, temp + i * (long long)pow(10, n - cnt - 1));
				visited[i] = 0;
			}
		}
	}
}


int main()
{	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> k[i];
	for (int i = 0; i <= 9; i++) {
		visited[i] = 1;
		bt(0, i, i * (long long)pow(10, n));
		visited[i] = 0;
	}
	if(mi<(long long)pow(10,n))
		printf("%lld\n0%lld", ma, mi);
	else
		printf("%lld\n%lld", ma, mi);
}