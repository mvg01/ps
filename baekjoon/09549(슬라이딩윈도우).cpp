#include <iostream>
using namespace std;

int t;
string a, b;
void input() {
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int len1 = a.length();
        int len2 = b.length();
        int alpha1[26]={0}, alpha2[26]={0}, idx = 0;
        for (int i = 0; i < len2; i++) {
            alpha1[a[i] - 'a']++;
            alpha2[b[i] - 'a']++;
        }
        bool chk = 0;
        for (int i = 0; i < 26; i++) {
            if (alpha1[i] != alpha2[i]) 
                chk = 1;
        }
        if (!chk) {
            cout << "YES\n";
            continue;
        }
        
        for (int i = len2; i < len1; i++) {
            alpha1[a[idx++]-'a']--;
            alpha1[a[i] - 'a']++;
            chk = 0;
            for (int j = 0; j < 26; j++) {
                if (alpha1[j] != alpha2[j]) 
                    chk = 1;
            }
            if (!chk)
                break;
        }
        cout << ((!chk) ? "YES\n" : "NO\n");
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}