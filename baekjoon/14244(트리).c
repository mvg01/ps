#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m - 2; i++)  //리프노드를 미리 1에 연결시킨다.
		printf("1 %d\n", n - i);      //n-i로 해야 밑의 간선과 중복되지 않으면서 노드의 범위를 벗어나지 않는다.

	for (int i = 0; i < n - m + 1; i++) { 
		printf("%d %d\n", i, i + 1);
	}
}

//그림판으로 그리면서 해보면 쉬운 문제

/*
input : 6 3
ans: 
1 5
0 1
1 2
2 3
3 4 
*/