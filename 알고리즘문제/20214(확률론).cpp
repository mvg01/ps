// 방을 2개로 나누고 학생을 보내거나 보내지 않거나
// 학생들 중 가장 큰 시간이 시험이 종료되는 시간일 것
/*
3
2 3 4
위 케이스의 경우 한 시험장에 (2,3,4) (2,3) (3,4) (2,4) (2) (3) (4) (0) 의 학생이 들어올 수 있다.
가장 오랫동안 시험 본 사람 기준으로 평균치를 내야하므로 4*4 + 3*2 + 2*1 를 2^3으로 나눈 결과가 정답
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
double a[41];
void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void solve() {
    double res = 0;
    sort(a, a + n);
    for (int i = n - 1; i >= 0; i--) 
        res += a[i] * pow(2, i);
    cout << res / pow(2, n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(8);
    input();
    solve();
}