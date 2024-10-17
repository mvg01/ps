#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, s, res = 0;
int arr[21];

void bt(int cnt,int sum, bool chk) {
	if (sum == s && chk) //chk true의 의미: 부분수열의 크기가 1이상이다.
		res++;
	if (cnt == n) 
		return;
	
	bt(cnt + 1, sum + arr[cnt], true);  //더하는 경우
	bt(cnt + 1, sum, false);   //더하지 않는 경우
}

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	bt(0, 0, false);
	cout << res;
}