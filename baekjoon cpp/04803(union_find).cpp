#include <iostream>
#include <vector>
using namespace std;

int n, m;
int parent[501];

void init() {
    for (int i = 1; i < 501; i++)
        parent[i] = i;
}

int getparent(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = getparent(parent[x]);
}

void setunion(int a, int b) {
    int a1 = getparent(a);
    int b1 = getparent(b);
    if (a1 > b1)
        parent[a1] = b1;
    else
        parent[b1] = a1;
}

bool sameparent(int a, int b) {
    int a1 = getparent(a);
    int b1 = getparent(b);
    if (a1 == b1)
        return true;
    else
        return false;
}

void input() {
    int j = 1;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        init();
        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            if (!sameparent(a, b))
                setunion(a, b);
            else {  // 사이클이기 때문에 트리 X
                int ver = parent[a];  // 사이클을 포함한 정점은 트리가 아니다. -> 0으로
                for (int i = 1; i <= n; i++) {
                    if (ver == i) {
                        parent[i] = 0;
                        break;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
            if (parent[i] == i) res++;
        cout << "Case " << j++ << ": ";
        if (res == 0)
            cout << "No trees.\n";
        else if (res == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << res << " trees.\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}