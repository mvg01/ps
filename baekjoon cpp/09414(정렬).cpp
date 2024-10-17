#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int t;
vector<int>v;
bool c(int i, int j) {
    return i > j;
}
void input() {
    cin >> t;
    while (t--) {
        int x;
        while (1) {
            cin >> x;
            if (x == 0)
                break;
            v.push_back(x);
        }
        sort(v.begin(), v.end(), c);
        long long sum = 0;
        bool chk = 0;
        for (int i = 0; i < v.size(); i++) {
            if (pow(v[i], i + 1) >= 5000000)
                chk = 1;
            sum += (2 * pow(v[i], i + 1));
        }
        if (chk || sum > 5000000)
            cout << "Too expensive\n";
        else
            cout << sum << '\n';
        v.clear();
    }
}
    
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}