#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
stack<int> s;
int main()
{
	int n, num, idx = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		if (v[i] != idx) 
			s.push(v[i]);
		
		else {
			idx++;
			while (!s.empty()) {
				if (s.top() == idx) {
					s.pop();
					idx++;
				}
				else
					break;
			}
		}
	}
	if (s.empty())
		cout << "Nice";
	else
		cout << "Sad";
}