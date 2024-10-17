#include <iostream>
using namespace std;

int n;
int maxres = -2000000001;
int minres = 2000000001;
int a[12];
int b[4];

void bt(int cnt,int t) {
	if (cnt == n - 1) {
		maxres = max(maxres, t);
		minres = min(minres, t);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (b[i] != 0) {
			b[i]--;
			if (i == 0) 
				bt(cnt + 1, t + a[cnt + 1]);
			else if (i == 1)
				bt(cnt + 1, t - a[cnt + 1]);
			else if (i == 2)
				bt(cnt + 1, t * a[cnt + 1]);
			else if (i == 3)
				bt(cnt + 1, t / a[cnt + 1]);

			b[i]++;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < 4; i++)
		cin >> b[i];

	bt(0, a[0]);

	cout << maxres << '\n' << minres;
}	