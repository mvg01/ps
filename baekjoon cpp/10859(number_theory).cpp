#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
bool f(ll x) {
	if (x <= 1)
		return 0;
	for (ll  i = 2; i * i <= x; i++) {
		if (x % i == 0) 
			return 0;	
	}
	return 1;
}

void solve() {
	string s = to_string(n), r;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '5' || s[i] == '8')
			r += s[i];
		else if (s[i] == '6')
			r += '9';
		else if (s[i] == '9')
			r += '6';
		else {
			cout << "no";
			return;
		}
	}
	if(f(n)&&f(stoll(r)))
		cout<<"yes";
	else
		cout<<"no";
}

void input() {
	cin >> n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}