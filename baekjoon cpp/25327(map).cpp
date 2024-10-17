#include <iostream>
#include <map>
using namespace std;

map <string, map<string, map<string, int>>> ma;  //3차원 맵 활용
string sub[3] = { "kor","math","eng" };
string fruit[3] = { "apple", "pear", "orange" };
string color[3] = { "red", "blue", "green" };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	string a, b, c;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		ma[a][b][c]++;
	}
	for (int i = 0; i < m; i++) {
		int res = 0;
		cin >> a >> b >> c;
		if (a == "-" && b == "-" && c == "-")
			res = n;

		else if (a == "-" && b == "-") {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) 
					res += ma[sub[i]][fruit[j]][c];
			}
		}
		else if (a == "-" && c == "-") {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					res += ma[sub[i]][b][color[j]];
			}
		}
		else if (b == "-" && c == "-") {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					res += ma[a][fruit[i]][color[j]];
			}
		}
		else if (c=="-") {
			res += ma[a][b]["red"];
			res += ma[a][b]["green"];
			res += ma[a][b]["blue"];
		}
		else if (b=="-") {
			res += ma[a]["apple"][c];
			res += ma[a]["pear"][c];
			res += ma[a]["orange"][c];
		}
		else if (a=="-") {
			res += ma["math"][b][c];
			res += ma["eng"][b][c];
			res += ma["kor"][b][c];
		}
		else {
			res += ma[a][b][c];
		}

		cout << res << '\n';
	}
}