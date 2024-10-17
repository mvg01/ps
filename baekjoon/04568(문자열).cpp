#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;

// LRU 알고리즘 -> 가장 오래전에 참조된 페이지를 희생페이지로 선택해 제거한다.
int n;
string s;
unordered_map<char, int>m; 
priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>>pq;

void LRU() {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == '!') {
            for (auto iter : m)
                pq.push({ iter.second,iter.first });
            while (!pq.empty()) {
                cout << pq.top().second;
                pq.pop();
            }
            cout << '\n';
            continue;
        }
        bool hit = 0;
        if (m.find(s[i]) != m.end()) {
            hit = 1;
           m[s[i]] = i;
        }
        if (hit) continue;

        if (m.size() < n) 
            m.insert({ s[i],i });
        else {
            int p = 0, ref = INF;
            for (auto iter : m) {
                int idx = iter.second;
                if (ref > idx) {  // 참조시간이 이른(작은) 페이지
                    ref = idx;
                    p = iter.first;
                }
            }
            m.erase(p);  
            m.insert({ s[i],i }); 
        }
    }
}

void input() {
    int t = 1;
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        cin >> s;
        cout << "Simulation " << t++ << '\n';
        LRU();
        m.clear();
    }
}

int main() {
    input();
}