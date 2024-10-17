#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int visited[1001] = { 0 };
int temp[1001] = { 0 };
void prime() {
	int number = 1000;
	for (int i = 2; i <= number; i++)
		arr[i] = i;
	for (int i = 2; i <= number; i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= number; j += i)
			arr[j] = 0;
	}
}

int main()
{
	int a, b, c, d;
	int yt = 0, yj = 0, cnt = 0;
	prime();
	cin >> a >> b >> c >> d;
	for (int i = min(a, c); i <= max(b, d); i++) {
		if (arr[i] != 0) {
			if (i >= a && i <= b)
				temp[i]++;
			if (i >= c && i <= d)
				temp[i] += 2;

			if (temp[i] == 1)  //용태만 부를 수 있는 소수
				yt++;
			if (temp[i] == 2)  //유진이만 부를 수 있는 소수
				yj++;
			if (temp[i] == 3)  //둘 다 부를 수 있는 소수
				cnt++;
		}
	}

	if (cnt % 2 == 0) {
		if (yt > yj)
			cout << "yt";
		else
			cout << "yj";
	}
	else {
		if (yt >= yj)
			cout << "yt";
		else
			cout << "yj";
	}
}