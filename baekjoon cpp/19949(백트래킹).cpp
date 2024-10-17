#include <iostream>
#include <algorithm>
using namespace std;

int a[10];
int temp[10];
int n[5] = { 0 };
int res = 0;

void bt(int cnt,int cor) {
	if (cnt == 10) {
		if (cor >= 5) {  //맞은 개수가 5개 이상이고
			bool no = 0;
			int prev = temp[0], ct = 1;
			for (int i = 1; i < 10; i++) { //연속 3개 같은 숫자인 것이 없다면 res++
				if (prev == temp[i])
					ct++;
				else
					ct = 1;

				prev = temp[i];
				if (ct >= 3)
					no = 1;
			}
			if(!no)
				res++;
		}
		return;
	}

	for (int i = 0; i < 5; i++) {
		n[i]++;
		if (a[cnt] == i + 1)  //정답과 같다면 cor++
			cor++;
		temp[cnt] = i;  //찍은 숫자들 저장
		bt(cnt + 1, cor);
		if (a[cnt] == i + 1)
			cor--;
		n[i]--;
	}
}

int main()
{
	for (int i = 0; i < 10; i++)
		cin >> a[i];
	bt(0, 0);
	cout << res;
}