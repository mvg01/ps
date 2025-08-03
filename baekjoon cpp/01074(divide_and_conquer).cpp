#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int res = 0;
int go[4][2] = { {0,0},{0,1},{1,0},{1,1} };
int s = 0;
void bt(int idx, int y, int x) {
	if (idx == 1) {
		for (int i = 0; i < 4; i++) {
			if (y + go[i][0] == r && x + go[i][1] == c)
				res = s;
			else
				s++;
		}
		return;
	}

	//사분면으로 생각하자
	if (r < y + pow(2, idx - 1) && c < x + pow(2, idx - 1)) //1사분면 범위에 찾는 좌표가 있을 때
		bt(idx - 1, y, x);
	s += pow(2, idx) * pow(2, idx) / 4;

	if (r < y + pow(2, idx - 1) && c <= x + pow(2, idx - 1) * 2 && c >= x + pow(2, idx - 1)) //2사분면 범위에 찾는 좌표가 있을 때
		bt(idx - 1, y, x + pow(2, idx - 1));
	s += pow(2, idx) * pow(2, idx) / 4;

	if (r <= y + pow(2, idx - 1) * 2 && c < x + pow(2, idx - 1)&& r >= y + pow(2, idx - 1)) //3사분면 범위에 찾는 좌표가 있을 때
		bt(idx - 1, y + pow(2, idx - 1), x);
	s += pow(2, idx) * pow(2, idx) / 4;

	if (r <= y + pow(2, idx - 1) * 2 && c <= x + pow(2, idx - 1) * 2&& c >= x + pow(2, idx - 1) && r >= y + pow(2, idx - 1)) //4사분면 범위에 찾는 좌표가 있을 때
		bt(idx - 1, y + pow(2, idx - 1), x + pow(2, idx - 1));

}

int main()
{
	cin >> n >> r >> c;
	bt(n, 0, 0);
	cout << res;
}