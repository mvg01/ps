#include <bits/stdc++.h>
using namespace std;

// OTP 알고리즘 (최적 교체 알고리즘)
// 가까운 미래에 사용될 가능성이 가장 낮은 것 제거
int n, k, res = 0;
int a[101], cnt[101];
vector<int>r;

void input() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) 
        cin >> a[i];
}

void solve() {
    for (int i = 0; i < k; i++) {
        bool skip = 0;
        for (int j = 0; j < r.size(); j++) {
            if (r[j] == a[i]) {  // 이미 꽂힌 전기용품
                skip = 1;
                break;
            }
        }
        if (skip) continue;
        if (r.size() < n) { // 멀티탭에 자리가 있으니 전기용품 꽂는다.
            r.push_back(a[i]);
        }   
        else {
            for (int j = 0; j < 101; j++)
                cnt[j] = 0;

            int mx = 0, mxidx = 0;  // 가장 나중에 사용하는 전기용품과 꽂힌 멀티탭 인덱스
            int x = 0;  // 전기용품이 몇 시간 후 또 사용되는지
            for (int j = i; j < k; j++) {
                for (int t = 0; t < r.size(); t++) {
                    if (a[j] == r[t] && cnt[r[t]] == 0) { // 가장 늦게 사용된 시간 기록
                        cnt[r[t]] = x;
                        break;
                    }
                }
                x++;
            }
            for (int j = 0; j < r.size(); j++) {  // 뽑아버릴 전기용품 고르기
                if (cnt[r[j]] == 0) {  // 앞으로 사용하지 않는다면 그 전기용품 뽑으면 된다.
                    mxidx = j;
                    break;
                }
                else if (cnt[r[j]] > mx) {  // 미래에 가장 나중에 사용하게 될 전기용품 뽑는다.
                    mx = cnt[r[j]];
                    mxidx = j;
                }
            }
            r.erase(r.begin() + mxidx); // 뽑아야 할 전기용품 인덱스로 제거
            res++;  
            r.push_back(a[i]);  // 멀티탭에 자리가 생겼으니 전기용품 꽂는다.
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}