#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<pair<double, double>>v;
double res = 0;
void input() {
    double a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({ a,b });
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        double dis = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) 
                dis += sqrt(pow((v[i].first - v[j].first), 2) + pow((v[i].second - v[j].second), 2));  
        }
        res += dis;
    }
    cout << res / n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(8);
    input();
    solve();
}