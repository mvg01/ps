#include <iostream>
#include <string>
using namespace std;

string a[5];
string turn_r(string s) {     //시계 방향 회전
	string res;
	res.push_back(s.back());
	for (int i = 0; i < 7; i++)
		res.push_back(s.at(i));

	return res;
}
string turn_l(string s) {
	string res = s;
	res.push_back(s.front());
	res.erase(0, 1);

	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x, y, res = 0;
	cin >> a[1] >> a[2] >> a[3] >> a[4];
	cin >> n;
	while (n--) {
		string temp;
		cin >> x >> y;
		if (x == 1) {
			temp = a[1];
			if (y == 1) 
				a[1] = turn_r(a[1]);
			else if (y == -1)
				a[1] = turn_l(a[1]);
			y *= -1;

			for (int i = 1; i < 4; i++) {
				if (temp[2] != a[i + 1][6]) {
					temp = a[i + 1];
					if (y == 1)
						a[i + 1] = turn_r(a[i + 1]);
					else if (y == -1)
						a[i + 1] = turn_l(a[i + 1]);
					y *= -1;
				}
				else    //2번이 회전하지 않는다면 3,4번도 회전 X
					break;
			}
		}
		else if (x == 2) {
			temp = a[2];
			if (y == 1)
				a[2] = turn_r(a[2]);
			else if (y == -1)
				a[2] = turn_l(a[2]);
			y *= -1;

			if (temp[6] != a[1][2]) {
				if (y == 1)
					a[1] = turn_r(a[1]);
				else if (y == -1)
					a[1] = turn_l(a[1]);
			}

			for (int i = 2; i < 4; i++) {
				if (temp[2] != a[i + 1][6]) {
					temp = a[i + 1];
					if (y == 1)
						a[i + 1] = turn_r(a[i + 1]);
					else if (y == -1)
						a[i + 1] = turn_l(a[i + 1]);
					y *= -1;
				}
				else    
					break;
			}
		}
		else if (x == 3) {	
			temp = a[3];
			if (y == 1)
				a[3] = turn_r(a[3]);
			else if (y == -1)
				a[3] = turn_l(a[3]);
			y *= -1;

			if (temp[2] != a[4][6]) {
				if (y == 1)
					a[4] = turn_r(a[4]);
				else if (y == -1)
					a[4] = turn_l(a[4]);
			}
			

			for (int i = 3; i > 1; i--) {
				if (temp[6] != a[i - 1][2]) {
					temp = a[i - 1];
					if (y == 1)
						a[i - 1] = turn_r(a[i - 1]);
					else if (y == -1)
						a[i - 1] = turn_l(a[i - 1]);
					y *= -1;
				}
				else
					break;
			}
		}
		if (x == 4) {
			temp = a[4];
			if (y == 1)
				a[4] = turn_r(a[4]);
			else if (y == -1)
				a[4] = turn_l(a[4]);
			y *= -1;

			for (int i = 4; i > 1; i--) {
				if (temp[6] != a[i - 1][2]) {
					temp = a[i - 1];
					if (y == 1)
						a[i - 1] = turn_r(a[i - 1]);
					else if (y == -1)
						a[i - 1] = turn_l(a[i - 1]);
					y *= -1;
				}
				else   
					break;
			}
		}
		/*for (int i = 1; i <= 4; i++) {
			cout << a[i] << '\n';
		}*/
	}
	int score = 1;
	for (int i = 1; i <= 4; i++) {
		if (a[i][0] == '1')
			res += score;
		score *= 2;
	}
	cout << res;
}