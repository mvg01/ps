#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
typedef struct {
    string name;
    int score;
    bool h;
}player;
player list[1001];

void input() {
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int len = s.length(), cnt = 0;
        for (int j = 0; j < len; j++) {
            if (s[j] == '"')
                cnt++;
            if (cnt == 3) {
                j++;
                for (; ; j++) {
                    if (s[j] == '"') {
                        cnt++;
                        break;
                    }
                    list[i].name.push_back(s[j]);
                }
            }
            if (cnt == 6) {
                string sc;
                j+=2;
                for (; ; j++) {
                    if (s[j] == ',') 
                        break;     
                    sc.push_back(s[j]);
                }
                list[i].score = stoi(sc);
            }
            if (cnt == 8) {
                j += 2;
                if (s[j] == '1')
                    list[i].h = true;
                else
                    list[i].h = false;
                break;
            }
        }
    }
}

bool c(player a, player b) {
    if (a.score > b.score)
        return true;
    else if (a.score < b.score)
        return false;
    else {
        if (a.name < b.name)
            return true;
        else
            return false;
    }
}

void solve() {
    sort(list, list + n, c);
    int pre = 0, g = 1;
    for (int i = 0; i < n; i++) {
        if (pre != list[i].score)
            g = i + 1;
        if (list[i].h != true) {
            cout << g << ' ' << list[i].name << ' ' << list[i].score << '\n';
        }
        pre = list[i].score;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}