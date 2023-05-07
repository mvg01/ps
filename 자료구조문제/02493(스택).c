// 풀이:


#include <stdio.h>
#include <stdlib.h>

int h[500001];
typedef struct stack{
	int *tower;
	int* idx;
	int top;
}S;

void init(S* s)
{
	s->top = -1;
	s->tower = (int*)malloc(sizeof(int) * 500001);
	s->idx = (int*)malloc(sizeof(int) * 500001);
}

void push(S* s, int n, int i)
{
	s->top++;
	s->tower[s->top] = n;
	s->idx[s->top] = i + 1;  //i가 0일때 1번째 탑이란 뜻이므로 +1 
}

int pop(S* s)
{
	return s->tower[s->top--];
}

int peek(S* s)  //스택 내에서 가장 위에있는 수 return
{
	return s->tower[s->top];
}

int empty(S* s)
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}

int main()
{
	S s;
	init(&s);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &h[i]);

	for (int i = 0; i < n; i++)
	{
		if (empty(&s) == 1) {  //스택이 비어있었다면
			printf("0 ");
			push(&s, h[i], i);  //탑의 높이와 인덱스 push
			continue;
		}
		
		if (peek(&s) <= h[i]) {  //현재 스택 내의 가장 높은 탑보다 새로 들어온 탑이 크거나 같을 때
			while(1)  //스택 내에서 h[i] 보다 높은 탑이 있는지 찾아준다. pop, peek을 사용
			{
				if (empty(&s)) //비어있다면 탈출 후 0 출력
					break;

				if (h[i] < peek(&s))  //h[i]보다 높은 타워가 있다면 break 
					break;

				pop(&s);  //h[i]보다 높은 타워가 나올 때까지 pop
			}

			if (empty(&s)) 
				printf("0 ");
			else
				printf("%d ", s.idx[s.top]);  //현재 스택에는 h[i]보다 높은 타워가 top에 저장되어 있다. 그 top의 idx 출력

			push(&s, h[i], i);  
		}

		else {  //바로 왼쪽 타워가 h[i] 보다 큰 경우 
			printf("%d ", s.idx[s.top]);
			push(&s, h[i], i);
		}
	}
    free(s.tower);
	free(s.idx);
}	