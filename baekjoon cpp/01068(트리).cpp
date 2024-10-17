#include <iostream>
#include <vector>
using namespace std;

int n, e, root;
vector<int>v[51];
int p[51];
bool visited[51];

void input() {
	int x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x != -1) 
			v[x].push_back(i);
		else
			root = i;
		p[i] = x;
	}
	cin >> e;
}

void erase_node(int ver) { //자식 트리로 내려가서 리프노드 찾아서 -1 넣어주기
	if (v[ver].empty()) {  
		v[ver].push_back(-1);
		return;
	}
	for (int i = 0; i < v[ver].size(); i++) {
		if (!visited[v[ver][i]]) {
			visited[v[ver][i]] = 1;
			erase_node(v[ver][i]);
		}
	}
}

void solve() {
	int cnt = 0;
	erase_node(e);
	if (v[p[e]].size() == 1) //삭제할 노드의 부모 노드 개수가 1개 였다면 리프노드가 된다.
		v[p[e]].clear();
	
	for (int i = 0; i < n; i++) {
		if (v[i].empty())
			cnt++;
	}

	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}