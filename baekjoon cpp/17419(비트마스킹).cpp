#include <iostream>
using namespace std;

//K = K-(K&((~K)+1))
//이 식의 연산대로 하면 가장 오른쪽 비트(최하위 비트)가 1인 것을 지운다.
//따라서 1의 개수를 세어주면 연산횟수가 된다.
int main()
{
	int n, res = 0;
	string k;
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		if (k[i] == '1')
			res++;
	}
	cout << res;
}