#include <iostream>
#include <stack>
using namespace std;

string s;
void input() {
    cin >> s;
}

void solve() {
    int len = s.length();
    int res = 0;
    stack<int>st;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(')
            st.push(0);
        else if (s[i] == 'H')
            st.push(1);
        else if (s[i] == 'C')
            st.push(12);
        else if (s[i] == 'O')
            st.push(16);
        else if (s[i] == ')') {
            int n = 0;
            while (1) {
                n += st.top();
                if (st.top() == 0) {
                    st.pop();
                    st.push(n);
                    break;
                }
                st.pop();
            }
        }
        else {
            if (!st.empty()) {
                int temp = st.top();
                st.pop();
                st.push(temp * (s[i] - '0'));
            }
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}