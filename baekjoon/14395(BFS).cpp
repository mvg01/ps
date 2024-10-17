#include <iostream>
#include <queue>
#include <set>
using namespace std;

set<long long>se;
long long s, t;
bool over = 0;

void bfs() {
	queue<pair<long long, string>>q;
	q.push({ s,"0" });

	while (!q.empty()) {
		long long num = q.front().first;
		string str = q.front().second;
		q.pop();

		if (num > 1000000000)
			continue;

		if (num == t) {
			if (str != "0") {
				str.erase(0, 1);
				cout << str;
			}
			else  //처음부터 s와 t가 같은 경우
				cout << 0;

			over = 1;
			break;
		}
		
		if (se.find(num) == se.end()) {
			q.push({ num * num,str + "*" });
			q.push({ num * 2,str + "+" });
			q.push({ 1,str + "/" });
			se.insert(num);
		}
	}
}

int main()
{
	cin >> s >> t;
	bfs();
	if(!over)
		cout << -1;
}
