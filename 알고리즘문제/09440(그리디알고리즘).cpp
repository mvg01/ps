#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(int i, int j) {
	return i > j;
}

int main()
{
	int n, zero, idx;
	string a, b;
	while (1) {
		int arr[15];
		zero = 0, idx = 0;
		a.clear();
		b.clear();

		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr, arr + n);  //오름차순 정렬

		if (arr[0] == 0) {  //0이 하나라도 있다면 순서를 바꿔줘야함
			for (int i = 0; i < n; i++) {
				if (arr[i] != 0) {
					idx = i;
					break;
				}
				else
					zero++;
			}

			if (idx == 1) {  //idx가 1인경우 0이 첫번째 자리수에 들어가게 되는 것 방지
				sort(arr, arr + zero + 1, compare);  //내림차순 정렬
				int temp = arr[idx];
				arr[idx] = arr[idx + 1];
				arr[idx + 1] = temp;
			}
			else  //0이 2개 이상 있을 경우 a와 b의 맨 앞은 0이 될 수 없다.
				sort(arr, arr + zero + 2, compare);  //내림차순 정렬

			//이 과정이 필요한 이유는 맨 앞의 두 정수는 현재 내림차순 정렬 되어있는데 오름차순으로 바꿔줄 필요가 있다.
			sort(arr, arr + 2);
		}

		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';

		if (n % 2 == 1) {
			for (int i = 0; i < n; i++) {
				if (i % 2 == 0)
					a.push_back(arr[i] + '0');
				else
					b.push_back(arr[i] + '0');
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				if (i % 2 == 0)
					a.push_back(arr[i] + '0');
				else
					b.push_back(arr[i] + '0');
			}
		}
		cout << a << ' ' << b << ' ';
		cout << stoi(a) + stoi(b) << '\n';
	}
}