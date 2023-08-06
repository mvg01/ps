#include <iostream>
#include <string>
#include <vector>
using namespace std;

int chk(string s, int len)
{
	string rev;
	for (int i = 0; i < len; i++)
		rev.push_back(s[len - i - 1]);

	if (s == rev)  //팰린드롬 이면 1 return
		return 1;
	else
		return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s, res, plus;
	cin >> s;
	int len = s.size();

	if (chk(s, len)) {  //첨부터 팰린드롬
		cout << len;
		return 0;
	}
	res = s;

	//res의 앞에서부터 문자를 지워가면서 팰린드롬인지 확인한다.
	//지워가다가 팰린드롬이 된다면 원래 문자열에 지운 문자만큼 더해주면 팰린드롬이 된다.
	for (int i = 1; i <= len; i++)
	{
		res.erase(0, 1);  //문자 맨 앞 지우기
		if (chk(res, len - i)) {
			cout << len + i;
			return 0;
		}
	}
}