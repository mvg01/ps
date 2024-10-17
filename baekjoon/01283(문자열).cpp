#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string>res;
void addres(int idx, int len, string s) {
	string temp;
	int index = 0;
	temp.resize(len + 2);
	idx++;
	temp[idx - 1] = '['; temp[idx + 1] = ']';
	for (int i = 0; i < len + 2; i++) {
		if (temp[i] != '[' && temp[i] != ']')
			temp[i] = s[index++];
	}
	temp[len + 2] = '\0';
	cout << temp << '\n';
}

int main()
{
	string s;
	int n, alpha[26] = { 0 };
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		vector<string> words;
		int len = s.length(), idx = 0, maxlen = 0;

		for (int j = 0; j < len; j++) {
			if (s[j] == ' ') {
				words.push_back(s.substr(idx, j - idx));  //문자열 파싱
				maxlen = max(maxlen, j - idx);
				idx = j + 1;
			}
			if (j == len-1) {
				if (idx == 0) { //공백이 없는 단어
					words.push_back(s);
					maxlen = s.length();
				}
				else {
					words.push_back(s.substr(idx, j - idx + 1));  //문자열 파싱
					maxlen = max(maxlen, j - idx + 1);
				}
			}
		}

		bool brk = 0;
		int sum = 0;

		for (int j = 0; j < words.size(); j++) {  //단어의 첫글자 지정되어있는지 확인
			words[j][0] = tolower(words[j][0]);  //일단 소문자로

			if (alpha[words[j][0] - 'a'] == 0) {
				alpha[words[j][0] - 'a'] = 1;
				addres(sum, len, s);
				brk = 1;
				break;
			}
			sum += words[j].length() + 1;
		}
		if (brk)
			continue;

		sum = 0;
		for (int j = 0; j < words.size(); j++) {  //각 단어를 왼쪽부터 살피면서 확인
			for (int idx = 1; idx < words[j].length(); idx++) {
				words[j][idx] = tolower(words[j][idx]);  //일단 소문자로

				if (alpha[words[j][idx] - 'a'] == 0) {
					alpha[words[j][idx] - 'a'] = 1;
					addres(sum+idx, len, s);
					brk = 1;
					break;
				}
			}
			sum += words[j].length() + 1;
			if (brk)
				break;
		}

		if (!brk)   //단축키 지정 불가능한 경우
			cout << s << '\n';
		
	}
}
