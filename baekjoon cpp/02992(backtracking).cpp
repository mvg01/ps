#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int a[7], visited[7] = { 0 };
int len, num, temp = 0, res = 1000000;

void bt(int n) {
	if (n == len) {
		if (temp > num) //일단 원본숫자 num보다 커야함
			res = min(res, temp);  //그러면서 가장 작은 수 = res
		
		return;
	}
	for (int i = 0; i < len; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			temp += pow(10, n) * a[i];  //temp에 자릿수별로 더해준다.
			bt(n + 1);
			visited[i] = 0;
			temp -= pow(10, n) * a[i];
		}
	}
}

int main()
{
	string x;
	cin >> x;  //문자열로 입력받음
	len = x.size();
	num = stoi(x);  //원본 숫자 저장
	for (int i = 0; i < len; i++)
		a[i] = x[i] - '0';   //숫자 자릿수별로 저장

	bt(0);
	if (res == 1000000)
		cout << 0;
	else
		cout << res;
}