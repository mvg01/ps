#include <iostream>
#include <vector>
using namespace std;

int n, k;
int res[4244] = { 0 };
void input() {
	cin >> n >> k;
}
void solve() {
	int idx = 0, p = n - 1, i = 1;
	while (k!=0) {
		if (k >= p) {
			res[idx++] = p + 1;
			k -= p;
			p--;
		}
		else {
			int point = idx;
			int start = 1;
			res[n - start] = p + 1;
			start++;
			idx++;
			while (k != 0) {
				p--;
				if (k >= p) {
					res[point] = p + 1;
					break;
				}
				else
					res[n - start] = p + 1;

				start++;
				idx++;
			}
			break;
		}
	}
	int pp = 1;
	for (int i = 0; i < n; i++) {
		if (res[i] == 0) {
			res[i] = pp++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << ' ';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}

//res배열을 앞에서 혹은 뒤에서부터 n-i값으로 채워준다.
//예제 2의 5 7은 5 4 1 2 3 도 가능
//10 36
//10 9 8 7 6 2 1 3 4 5
