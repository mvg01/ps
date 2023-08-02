#include <iostream>
#include <deque>
using namespace std; 
int n;
deque<int> d;

int left(int l,int idx) {
	int cnt = 0;
	l *= -1;
	while (cnt != l) {
		if (d.at((idx - 1 + n) % n) != 0) {
			idx = (idx - 1 + n) % n;
			cnt++;
		}
		else
			idx = (idx - 1 + n) % n;
	}
	return idx;
}

int right(int r,int idx) {
	int cnt = 0;
	while (cnt != r) {
		if (d.at((idx + 1 + n) % n) != 0) {
			idx = (idx + 1 + n) % n;
			cnt++;
		}
		else
			idx = (idx + 1 + n) % n;
	}
	return idx;
}

int main()
{
	int res[1001], e, idx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> e;
		d.push_back(e);
	}

	int move = d.front();
	for (int i = 0; i < n - 1; i++) {
		res[i] = idx + 1;
		d.at(idx) = 0;
		if (move > 0)
			idx=right(move,idx);
		else
			idx=left(move,idx);

		move = d.at(idx);
	}
	for (int i = 0; i < n - 1; i++)
		cout << res[i] << ' ';
	cout << idx + 1;
}