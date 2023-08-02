#include <iostream>
#include <deque>
using namespace std; 
int n;
deque<int> d;

int main()
{
	int m, x, cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		d.push_back(i);

	for (int i = 0; i < m; i++)
	{
		if (d.size() == 1)
			continue;

		cin >> x;
		int idx = 0;
		for (int j = 0; j < d.size(); j++) {
			if (d.at(j) == x) {
				idx = j;
				break;
			}
		}
        
		int temp;
		if (idx <= d.size() / 2) {  //찾고자 하는 번호 인덱스가 가운데 기준 왼쪽
			for (int i = 0; i < idx; i++) {
				temp = d.front();
				d.pop_front();
				d.push_back(temp);
				cnt++;
			}
			d.pop_front();
		}
		else {
			for (int i = 0; i < d.size()-idx; i++) {
				temp = d.back();
				d.pop_back();
				d.push_front(temp);
				cnt++;
			}
			d.pop_front();
		}
	}
	cout << cnt;
}