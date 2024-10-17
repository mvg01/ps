#include <iostream>
#include <stack>
using namespace std;

string str;
stack<char>s;
int ans = 0;

void input() {
    cin >> str;
}

void solve() {
    bool no = 0;
    int len = str.length();
    int num = 1;
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            s.push(str[i]);
            num *= 2;
        }
        else if (str[i] == '[') {
            s.push(str[i]);
            num *= 3;
        }
        else if (str[i] == ')') {
            if (s.empty() || s.top()=='[') {
                no = 1;
                break;
            }
            else if (str[i - 1] == '(') {
                ans += num;
                num /= 2;
                s.pop();
            }
            else {
                num /= 2;
                s.pop();
            }
        }
        else if (str[i] == ']') {
            if (s.empty() || s.top() == '(') {
                no = 1;
                break;
            }
            else if (str[i - 1] == '[') {
                ans += num;
                num /= 3;
                s.pop();
            }
            else {
                num /= 3;
                s.pop();
            }
        }
    }
    if (no||!s.empty()) 
        cout << 0;
    else
        cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}