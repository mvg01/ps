#include <iostream>
#include <string>
using namespace std;

string dp[10001];
string string_sum(string a, string b) {  //문자열 큰 수 연산
    int alen = a.length();
    int blen = b.length();
    int pass = 0, plus = 0;
    string c;
    while (blen > 0) {
        int sum = 0;
        if (alen > 0) {
            sum = a[alen - 1] - '0' + b[blen - 1] - '0' + pass;
        }
        else {
            sum = b[blen - 1] - '0' + pass;
        }
        pass = sum / 10;
        plus = sum % 10;
        c.push_back(plus + '0');
        alen--; blen--;
    }

    if (pass) //올림수
        c.push_back(pass + '0');
    

    int clen = c.length();
    string temp;
    temp.resize(clen);
    for (int i = 0; i < clen; i++) {
        temp[i] = c[clen - i - 1];
    }
    temp[clen] = '\n';
    return temp;
}

int main()
{
    int n;
    cin >> n;
    dp[0] = "0";
    dp[1] = "1";
    for (int i = 2; i <= n; i++) {
        dp[i] = string_sum(dp[i - 2], dp[i - 1]);
        //cout << dp[i] << '\n';
    }
    cout << dp[n];
}
