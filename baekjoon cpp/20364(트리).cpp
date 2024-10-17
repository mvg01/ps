#include <iostream>
#include <vector>
using namespace std;

int n, q;
vector<int>v;
int tree[1048577] = { 0 };
void input() {
	int x;
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		cin >> x;
		v.push_back(x);
	}
}

void solve() {
	for (int i = 0; i < q; i++) {
		int res = 0, temp = v[i];
		while (v[i] != 0) {
			if (tree[v[i]] == 1)
				res = v[i];  //res 값은 가장 위에 있는 부모노드
			v[i] /= 2;  //부모 노드로 올라가기
		}
		if (res == 0)  //오리가 원하는 땅을 얻음
			tree[temp] = 1;
		cout << res << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}