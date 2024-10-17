#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> m;
vector <string> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string x;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		m.insert({ x,i });    //들어온 순서
	}
	int front_car[1005];
	for (int i = 0; i < n; i++) {
		cin >> x;
		front_car[i] = m[x];  //나간 순서에 들어온 순서를 저장
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (front_car[i] > front_car[j]) {
				res++;
				break;
			}
		}
	}
	cout << res;
}