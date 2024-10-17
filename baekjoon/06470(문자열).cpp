#include <iostream>
#include <vector>
#include <string>
using namespace std;

int k, e;
vector<string>w;
vector<string>res;
vector<string> stringTokenizer(string& str) {
    vector<string> tokens;
    string token;
    for (char ch : str) {
        if (ch >= 'a' && ch <= 'z') 
            token += ch;    
        else if (ch >= 'A' && ch <= 'Z') {
            ch += 32;
            token += ch;
        }
        else {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}

void input() {
    string s;
    for (int t = 1; ; t++) {
        cin >> k >> e;
        if (cin.eof()) break;
        for (int i = 0; i < k; i++) {
            cin >> s;
            w.push_back(s);
        }
        cin.ignore();

        int m = 0;
        for (int i = 0; i < e; i++) {
            getline(cin, s);
            vector<string>v = stringTokenizer(s);
            int cnt = 0;
            for (int j = 0; j < v.size(); j++) {
                for (int k = 0; k < w.size(); k++) {
                    if (w[k] == v[j])
                        cnt++;
                }
            }
            if (m < cnt) {
                res.clear();
                res.push_back(s);
                m = cnt;
            }
            else if (m == cnt) {
                res.push_back(s);
            }
        }
        cout << "Excuse Set #" << t << '\n';
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << '\n';

        cout << '\n';
        w.clear();
        res.clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}