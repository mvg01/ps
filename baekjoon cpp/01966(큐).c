#include <stdio.h>

int main()
{
	int t, n, m;
	scanf("%d", &t);
	while (t--)
	{
		int q[101];
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d", &q[i]);

		int front = 0, cnt = 1, max = 0;
		while (1)
		{
			for (int i = 0; i < n; i++)
			{
				if (max < q[i]) //중요도가 가장 큰 문서
					max = q[i];
			}
			while (1)
			{
				if (q[front] == max) //중요도가 가장 큰 문서가 나올 때 까지
					break;
				else 
					front = (front + 1) % n;  //원형큐의 dequeue의 과정으로 찾는다.
			}

			if (front == m) //찾는 인덱스가 dequeue된 종이였다면 큰 while문 탈출
				break;

			q[front] = 0;  //dequeue 
			front = (front + 1) % n; //원형큐의 front값 1 증가
			max = 0;  //max 값 초기화
			cnt++;  //출력 순서 증가
		}
		printf("%d\n", cnt);
	}
}