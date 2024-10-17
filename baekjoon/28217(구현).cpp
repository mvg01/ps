#include <iostream>
using namespace std;

int n, res = 100;
int mat[11][11];
int x[11][11];
int temp[11][11];
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++)
            cin >> mat[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++)
            cin >> x[i][j];
    }
}

void rotate() {  // 120도 회전
    int idx = n - 1;
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = i; j < n; j++) {
            temp[idx][k++] = mat[j][i];
        }
        idx--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++)
            mat[i][j] = temp[i][j];
    }
}

void symmetry() {  // 대칭
    for (int i = 0; i < n; i++) {
        int k = 1;
        for (int j = 0; j < i + 1; j++) {
            temp[i][i + 1 - k] = mat[i][j];
            k++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++)
            mat[i][j] = temp[i][j];
    }
}

void dif() {   // 차이나는 점 개수
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (mat[i][j] != x[i][j])
                cnt++;
        }
    }
    res = min(res, cnt);
}

void solve() {
    dif();  
    symmetry();
    dif();
    symmetry();
    rotate();

    dif();
    symmetry();
    dif();
    symmetry();
    rotate();

    dif();
    symmetry();
    dif();

    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}