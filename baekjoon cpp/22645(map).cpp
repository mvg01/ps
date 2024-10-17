#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;

// LRU 알고리즘 -> 가장 오래전에 참조된 페이지를 희생페이지로 선택해 제거한다. 
int n, k;
int page[100001];
unordered_map<int, int>m; 
priority_queue<pair<int, int>>pq;

void LRU() {
    for (int i = 0; i < n; i++) {
        bool hit = 0;
        if (m.find(page[i]) != m.end()) {
            hit = 1;
            m[page[i]] = i;
        }
        if (hit) continue;

        if (m.size() < k) 
            m.insert({ page[i],i });
        else {
            int p = 0, ref = INF;
            for (auto iter : m) {
                int idx = iter.second;
                if (ref > idx) {  
                    ref = idx;
                    p = iter.first;
                }
            }
            m.erase(p);  
            m.insert({ page[i],i }); 
        }
    }
}

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> page[i];
    LRU();
    for (auto iter : m)
        pq.push({ iter.second,iter.first });
    while (!pq.empty()) {
        cout << pq.top().second << '\n';
        pq.pop();
    }
}

int main() {
    input();
}