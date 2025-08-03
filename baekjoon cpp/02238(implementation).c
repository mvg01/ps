#include <stdio.h>
#include <string.h>
char name[100001][11];
int m[100001];
int chk[10001] = { 0 }; //idx의 가격으로 참여한 사람들의 수
char chkname[10001][11]; //idx의 가격으로 참여한 사람들의 이름들
int main()
{
	int u, n;
	scanf("%d %d", &u, &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d", name[i], &m[i]);
		if (chk[m[i]] == 0)        //m[i]의 가격으로 입찰한 첫번째 사람이면
			strcpy(chkname[m[i]], name[i]);   //이름 저장

		chk[m[i]]++;  //m[i]의 가격으로 입찰한 사람의 수 체크
	}
	for (int i = 1; i <= u; i++) //낮은가격부터
	{
		if (chk[i] == 1) {  //만약 한명이면 바로 낙찰임
			printf("%s %d", chkname[i], i);
			return 0;
		}
	}
    //같은 가격의 사람이 2명 이상씩 있었을 때
	int minchk = 100000, min_i = 0;
	for (int i = 1; i <= u; i++)
	{
		if (minchk > chk[i] && chk[i] > 1) { //가장 적은 사람의 구매 가격을 찾는다
			minchk = chk[i];
			min_i = i;
		}
	}
	printf("%s %d", chkname[min_i], min_i);
}
