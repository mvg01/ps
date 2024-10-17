#include <iostream>
#include <vector>
using namespace std;
using std::cout;

string s;

bool O_tic_chk() {  // O 틱택토가 있다면 true
	bool chk = 0;
	if (s[0] == 'O' && s[4] == 'O' && s[8] == 'O')
		chk = 1;
	if (s[2] == 'O' && s[4] == 'O' && s[6] == 'O')
		chk = 1;
	if (chk) 
		return 1;
	
	for (int i = 0; i < 3; i++) {
		//O가 3줄 완성되었는데 계속 진행했던 경우 찾기
		chk = 0;
		for (int j = i * 3; j < i * 3 + 3; j++) {  //가로
			if (s[j] == 'X' || s[j] == '.')
				chk = 1;
		}
		if (!chk) 
			return 1;
		
		chk = 0;
		for (int j = i; j < 9; j += 3) {  //세로
			if (s[j] == 'X' || s[j] == '.')
				chk = 1;
		}
		if (!chk) 
			return 1;
	}
	return 0;
}

bool X_tic_chk() {  // X 틱택토가 있다면 true
	bool chk = 0;
	if (s[0] == 'X' && s[4] == 'X' && s[8] == 'X')
		chk = 1;
	if (s[2] == 'X' && s[4] == 'X' && s[6] == 'X')
		chk = 1;
	if (chk)
		return 1;

	for (int i = 0; i < 3; i++) {
		chk = 0;
		for (int j = i * 3; j < i * 3 + 3; j++) {  //가로
			if (s[j] == 'O' || s[j] == '.')
				chk = 1;
		}
		if (!chk)
			return 1;

		chk = 0;
		for (int j = i; j < 9; j += 3) {  //세로
			if (s[j] == 'O' || s[j] == '.')
				chk = 1;
		}
		if (!chk)
			return 1;
	}
	return 0;
}

int main()
{
	while (1) {
		cin >> s;
		if (s == "end")
			break;

		int x = 0, o = 0;
		for (int i = 0; i < 9; i++) {
			if (s[i] == 'X')
				x++;
			else if (s[i] == 'O')
				o++;
		}
		if (!(x-1==o||x==o)) {  //처음부터 잘못 만들어진
			cout << "invalid\n";
			continue;
		}

		if (x - 1 == o) {  //O 틱택토가 있거나 X 틱택토가 없다면 invalid
			if (x == 5) {  //꽉 찬 상태
				if (O_tic_chk()) {
					cout << "invalid\n";
					continue;
				}
				else {
					cout << "valid\n";
					continue;
				}
			}

			if (O_tic_chk()) {
				cout << "invalid\n";
				continue;
			}
			
			if (X_tic_chk())
				cout << "valid\n";
			else
				cout << "invalid\n";
			
		}
		
		if (x == o) {  //x==o 일 땐, O의 승리로 게임이 끝난 상태여야만함
			if (O_tic_chk() && !X_tic_chk())  //대신 X도 틱택토면 안됨
				cout << "valid\n";
			else
				cout << "invalid\n";
		}
	}
}