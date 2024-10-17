#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

string s;
vector<char> v;
stack<char> stk;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	getline(cin, s);
	int len = s.size();
	bool chk = 0;
	string basic; //->기본 자료형
	for (int i = 0; i < len; i++) {
		if (s[i] == ' ' && !chk) { //처음 나온 공백
			chk = 1;
			basic = s.substr(0, i);  //기본 자료형 저장
		}
		else if (s[i] == ',' || s[i] == ';') {
			cout << basic;
			for (int i = v.size() - 1; i >= 0; i--) {
				if (v[i] == '&' || v[i] == '*')
					cout << v[i];
				else if (v[i] == ']') {
					cout << "[]";
					i--;
				}
				else
					stk.push(v[i]);  //변수명은 뒤집어야 하므로 스택에
			}
			cout << ' ';
			while (stk.size()) {
				cout << stk.top();
				stk.pop();
			}
			cout << ';' << '\n';
			v.clear();
		}
		else if (chk && s[i] != ' ')  //기본 자료형 이후 변수들에 대해서
			v.push_back(s[i]);
	}
}