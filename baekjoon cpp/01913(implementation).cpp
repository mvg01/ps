#include <iostream>
using namespace std;

int map[1000][1000] = { 0 };

int main()
{
	int n, k;
	cin >> n >> k;
	int x = 0, y = 0;
	int xmove = 0, ymove = 1;
	int resy, resx;
	for (int i = 0; i < n * n; i++) {
		map[y][x] = n * n - i;
		if (n * n - i == k) 
			resy = y + 1, resx = x + 1;
		
		if (ymove == 1) {
			if (y < n - 1 && map[y + 1][x] == 0)
				y++;
			else {
				ymove = 0;
				xmove = 1;
				x++;
			}
		}
		else if (xmove == 1) {
			if (x < n-1 && map[y][x + 1] == 0)
				x++;
			else {
				ymove = -1;
				xmove = 0;
				y--;
			}
		}
		else if (ymove == -1) {
			if (y > 0 && map[y - 1][x] == 0)
				y--;
			else {
				ymove = 0;
				xmove = -1;
				x--;
			}
		}
		else if (xmove == -1) {
			if (x > 0 && map[y][x - 1] == 0)
				x--;
			else {
				ymove = 1;
				xmove = 0;
				y++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cout << map[i][j] << ' ';

		cout << '\n';
	}
	cout << resy << ' ' << resx;
}