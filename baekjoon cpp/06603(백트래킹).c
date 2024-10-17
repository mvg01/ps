#include <stdio.h>
#include <stdlib.h>

int k;
int s[14];
int visited[14] = { 0 };
int temp[6];
void bt(int cnt, int a) {
    if (cnt == 6) {
        for (int i = 0; i < 6; i++)
            printf("%d ", temp[i]);
        printf("\n");
        return;
    }

    for (int i = a; i < k; i++) {
        if (!visited[i] && cnt <= i) {
            temp[cnt] = s[i];
            visited[i] = 1;
            bt(cnt + 1, i + 1);
            visited[i] = 0;
        }
    }
}

int main()
{
    while (1) {
        scanf("%d", &k);
        if (k == 0)
            return 0;

        for (int i = 0; i < k; i++)
            scanf("%d", &s[i]);

        bt(0, 0);
   
        printf("\n");
    }
}