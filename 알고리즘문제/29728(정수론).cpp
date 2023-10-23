#include <iostream>
using namespace std;

int number = 5000000;
int a[5000001];
void prime() {
	for (int i = 2; i <= number; i++)
		a[i] = i;
	for (int i = 2; i <= number; i++)
	{
		if (a[i] == 0)
			continue;
		for (int j = i + i; j <= number; j += i)
			a[j] = 0;
	}
}

int main()
{
	prime(); //에라토스테네스 체
	int n, s = 0, b = 0;
	bool prev = 0;  //이전이 소수아니면 0
	cin >> n;
	a[1] = 0; //1은 소수 아님
	for (int i = 1; i <= n; i++) {
		
		if (a[i] == 0) { //소수 아니면
			b++;
			prev = 0;
		}
		else {  //소수면
			if (!prev) {
				b--;
				s += 2;
			}
			else
				s++;
			prev = 1;
		}
	}
	cout << b << ' ' << s;
}