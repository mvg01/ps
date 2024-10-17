#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string s;
string temp;
unordered_map<string, bool> m;
int len;
int res = 0;
int visited[11] = { 0 };

void bt(int cnt, char bef) {
	if (cnt == len) {
		res++;
		return;
	}

	for (int i = 0; i < len; i++) {
		if (!visited[i]) {
			if (bef != s[i]) {
				temp[cnt] = s[i];
				visited[i] = 1;
				bt(cnt + 1, s[i]);
				visited[i] = 0;
			}
		}
	}
}

int main()
{
	cin >> s;
	len = s.size();
	int a[26] = { 0 };
	for (int i = 0; i < len; i++) 
		a[s[i] - 'a']++;
	
	temp.resize(len);

	bt(0, ' ');
	for (int i = 0; i < 26; i++) {
		if (a[i] > 1) {
			for (int j = 2; j <= a[i]; j++) //팩토리얼 갯수만큼 나누기
				res /= j;
		}
	}
	cout << res;
}

/*
ex) aba
같은 케이스에 기존 백트래킹 과정을 거치면 aba,aba 2개가 세진다.
(알파벳 개수)! 만큼 나눠줘야 한다.
*/


//두번째 풀이 next_permutation 사용
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<char> v;

int main()
{
	cin >> s;
	int res = 0;
	int len = s.size();
	for (int i = 0; i < len; i++)
		v.push_back(s[i]);

	sort(v.begin(), v.end());  //다음 순열 사용하기위해서 ex) dcba

	do {
		bool k = 0;
		for (int i = 1; i < len; i++) {
			if (v[i - 1] == v[i]) 
				k = 1;
		}
		if (!k)
			res++;
	} while (next_permutation(v.begin(), v.end()));

	cout << res;
}