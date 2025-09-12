#include <bits/stdc++.h>
using namespace std;

int n, m, k, r, c, res;
int mat[101][11][11], ans[41][41];

void rotate(int idx)
{ // idx 스티커 90도 회전
    // 1. 회전한 스티커를 temp에 임시 저장
    int temp[11][11];
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            temp[i][j] = mat[idx][r - j - 1][i];
        }
    }
    swap(r, c);
    // 2. 회전 하기 전 스티커 지우기
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            mat[idx][i][j] = 0;
    }
    // 3. 임시저장한 회전한 스티커 적용
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mat[idx][i][j] = temp[i][j];
            // cout << mat[idx][i][j] << ' ';
        }
        // cout << '\n';
    }
}

void input()
{
    cin >> n >> m >> k;
    while (k--)
    {
        int idx = 0;
        cin >> r >> c;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cin >> mat[idx][i][j];
        }
        bool ok = 0;
        for (int z = 0; z < 4; z++)
        { // 회전 필요하다면 최대 4번
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    bool brk = 0;
                    for (int a = 0; a < r; a++)
                    {
                        for (int b = 0; b < c; b++)
                        {
                            if (i + a >= n || j + b >= m)
                            { // 혜윤의 노트북 크기 범위 벗어난 스티커
                                brk = 1;
                                break;
                            }
                            if (mat[idx][a][b] == 1 && ans[i + a][j + b] == 1)
                            { // 이미 스티커가 붙어있어서 안된다.
                                brk = 1;
                                break;
                            }
                        }
                        if (brk)
                            break;
                    }
                    if (!brk)
                    {           // 혜윤 노트북에 스티커를 붙일 수 있는 상황
                        ok = 1; // 유연한 반복문 탈출을 위해 필요한 변수
                        for (int a = 0; a < r; a++)
                        {
                            for (int b = 0; b < c; b++)
                            {
                                if (mat[idx][a][b] == 1)
                                    ans[i + a][j + b] = 1;
                            }
                        }
                    }
                    if (ok)
                        break;
                }
                if (ok)
                    break;
            }
            if (ok)
                break;
            else
                rotate(idx);
        }
        idx++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // cout << ans[i][j] << ' ';
            }
            // cout << '\n';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res += ans[i][j];
        }
    }
    cout << res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}