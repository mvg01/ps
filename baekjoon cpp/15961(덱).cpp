#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

deque<int>de;
vector<int>v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d, k, c, x;
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> x;
		de.push_back(x);
	}
	int num[3001] = { 0 };

	int cnt = k, max = 0;
	for (int i = 0; i < k; i++) { 
		num[de.at(i)]++;
		if (num[de.at(i)] >=2)
			cnt--;
	}
	//보너스 초밥의 경우 체크
	if (num[c] == 0) 
		cnt++;
	if (max < cnt)
		max = cnt;
	if (num[c] == 0)
		cnt--;

	for (int j = 0; j < n; j++) {
		//1. 맨 앞 초밥 나갔을 때 종류 수 체크
		if (num[de.front()] == 1)  
			cnt--;
		num[de.front()]--;

		//2. 컨테이너 식으로 맨 앞 초밥 바꾸기
		de.push_back(de.front());
		de.pop_front();

		//3. 들어온 초밥이 새로운 종류였다면
		if (num[de.at(k - 1)] == 0) 
				cnt++;
		num[de.at(k - 1)]++;

		//4. 보너스 초밥의 유무에 따라 종류 추가 여부 결정
		if (num[c] == 0)
			cnt++;
		if (max < cnt) 
			max = cnt;
		if (num[c] == 0)
			cnt--;
	}
	cout << max;
}