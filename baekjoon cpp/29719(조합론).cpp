#include <iostream>
using namespace std;

//m^n - (m-1)^n
int main()
{
	long long n, m, a = 1, b = 1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		a = (a * m) % 1000000007;
		b = (b * (m - 1)) % 1000000007;
	}
	cout << (a - b + 1000000007) % 1000000007; 
}