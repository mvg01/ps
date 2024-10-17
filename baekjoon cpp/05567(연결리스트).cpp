#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node {
	bool Friend;
	node* next;
}node;

int n;
int* chkFriend;
node* list;

vector<pair<int, int >> v;
int main() 
{
	int m, a, b, res = 0;
	cin >> n >> m;
	chkFriend = new int[n + 1];
	list = new node[n + 1];
	for (int i = 1; i <= n; i++) {
		list[i].Friend = 0;
		chkFriend[i] = 0;  //결혼식에 오는 사람이면
		list[i].next = NULL;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		if (v[i].first == 1) {
			if (!chkFriend[v[i].second]) {
				chkFriend[v[i].second] = 1;
				list[v[i].second].Friend = 1;
				res++;
			}
		}
		else if (v[i].second == 1) {
			if (!chkFriend[v[i].first]) {
				chkFriend[v[i].first] = 1;
				list[v[i].first].Friend = 1;
				res++;
			}
		}
		else if (list[v[i].first].Friend&&!chkFriend[v[i].second]) {
			res++;
			chkFriend[v[i].second] = 1;
		}
		else if (list[v[i].second].Friend && !chkFriend[v[i].first]) {
			res++;
			chkFriend[v[i].first] = 1;
		}
	}

	cout << res;
	free(chkFriend);
	free(list);
}