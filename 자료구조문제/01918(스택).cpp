#include <bits/stdc++.h>
using namespace std;

// 중위표기식을 후위표기식으로
// 1. 피연산자는 그대로 출력, 연산자는 스택에
// 2. 연산자를 스택에 넣을 때, 스택의 top에 높거나 같은 우선순위가 있다면 그 연산자를 뽑아서 출력
// 3. 여는 괄호는 스택에 넣고, 닿는 괄호를 만나면 여는 괄호가 나올 때 까지 출력

string p;
void input() {
    cin >> p;
}

int power(char t) {
    if (t == '+' || t == '-')
        return 1;
    else if (t == '*' || t == '/')
        return 2;
    else
        return 0;
}

void solve() {
    int len = p.size();
    stack<char>s;
    for (int i = 0; i < len; i++) {
        if (p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/') {
            if (s.empty())
                s.push(p[i]);
            else {
                if (power(s.top()) >= power(p[i])) {
                    while (1) {
                        cout << s.top();
                        s.pop();
                        if (s.empty())
                            break;
                        if (power(s.top()) < power(p[i]))
                            break;
                    }
                }
                s.push(p[i]);
            }
        }
        else if (p[i] == '(') 
            s.push(p[i]);
        else if (p[i] == ')') {
            while (1) {
                if (s.top() == '(') {
                    s.pop();
                    break;
                }
                cout << s.top();
                s.pop();
            }
        }
        else
            cout << p[i];
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}