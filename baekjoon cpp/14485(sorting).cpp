#include <bits/stdc++.h>
using namespace std;

int t, n, x;
map<int, int>m;

bool c(pair<int, int>a, pair<int, int>b) {
    if (a.first > b.first)
        return true;
    else if (a.first == b.first) {
        if (a.second == 7)
            return true;
        else if (b.second == 7)
            return false;
        else if (a.second < b.second)
            return true;
        else return false;
    }
    else return false;
}

void input() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                cin >> x;
                m[x]++;
            }
        }
        vector<pair<int, int>>v;
        vector<int>res;
        for (int i = 1; i <= 49; i++) 
            v.push_back({ m[i],i });
        sort(v.begin(), v.end(), c);  // 문제 정렬 기준에 맞춰 정렬
        for (int i = 0; i < 6; i++)
            res.push_back(v[i].second);
        sort(res.begin(), res.end());  // 정답 리스트 정렬
        for (int i = 0; i < 6; i++)
            cout << res[i] << ' ';
        cout << '\n';
        m.clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}