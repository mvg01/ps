#include <iostream>
#include <algorithm>
using namespace std;
int l, c;
char a[16];
char res[16];
int visited[26] = { 0 };

void bt(int cnt, int start, char prev) {
	if (cnt == l) {
		int chk = 0, chk2 = 0;
		for (int i = 0; i < l; i++) {
			if (res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u')
				chk++;  //모음
			else
				chk2++;  //자음
		}
		if (chk < 1 || chk2 < 2)
			return;

		for (int i = 0; i < l; i++)
			cout << res[i];
		cout << '\n';
		return;
	}
	for (int i = start; i < c; i++) {
		if (!visited[a[i] - 97] && prev < a[i]) {
			visited[a[i] - 97] = 1;
			res[cnt] = a[i];
			bt(cnt + 1, start + 1, a[i]);
			visited[a[i] - 97] = 0;
		}
	}
}


int main() 
{
	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> a[i];
	sort(a, a + c);
	bt(0, 0, 'A');
}