#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[300001];
void init() {
	for (int i = 0; i < 300001; i++)
		parent[i] = i;
}

int getparent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = getparent(parent[x]);
}

void set_union(int a, int b) {
	a = getparent(a);
	b = getparent(b);
	if (a != b)
		parent[b] = a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n - 2; i++) {
		cin >> a >> b;
		set_union(a, b);
	}

	//1번부터 비교해서 부모가 다른 섬이 나타나면 각각의 부모 끼리 연결하면 되므로 출력
	int chk = getparent(1);
	for (int i = 2; i <= n; i++) {
		int temp = getparent(i);
		if (chk != temp) {
			cout << chk << ' ' << temp;
			return 0;
		}
		chk = temp;
	}
}