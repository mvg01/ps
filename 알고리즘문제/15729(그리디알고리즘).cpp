#include <iostream>
using namespace std;

bool arr[1000001];
bool btn[1000001]; //처음의 버튼 모두 0
int main()
{
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		if (btn[i] != arr[i]) {
			res++;
			btn[i + 1] = !btn[i + 1];
			btn[i + 2] = !btn[i + 2];
		}
	}
	cout << res;
}