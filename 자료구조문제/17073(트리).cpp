#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//틀렸던 이유: 부모의 노드가 자식 노드보다 클 수 있다.
int n;
double w;
vector<int>mat[500001];
bool visited[500001];

void input() {
	int a, b;
	cin >> n >> w;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
}

int leaf_node_count() {
	int cnt = 0;
	queue<int>q;
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int p = q.front();
		int len = mat[p].size(), temp = 0;
		q.pop();
		for (int i = 0; i < len; i++) {
			if (!visited[mat[p][i]]) {
				q.push(mat[p][i]);
				visited[mat[p][i]] = 1;
				temp++;
			}
		}
		if (temp == 0)  //리프노드 카운터
			cnt++;
	}
	return cnt;
}

void solve() {  
	int cnt = leaf_node_count();
	printf("%lf", w / cnt);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}