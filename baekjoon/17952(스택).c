#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int top;
	int* score;
	int* time;
}Stack;

void init(Stack* s,int n)
{
	s->top = -1;
	s->score = (int*)malloc(sizeof(int) * n + 1);
	s->time = (int*)malloc(sizeof(int) * n + 1);
}

void push(Stack* s, int sc,int ti)
{
	s->score[++s->top] = sc;
	s->time[s->top] = ti;
}

void pop(Stack* s)
{
	s->top--;
}

int main()
{
	Stack stack;
	int n, x, a, t, res = 0;
	scanf("%d", &n);
	init(&stack, n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&x);
		if (x == 1) {
			scanf("%d %d", &a, &t);
			push(&stack, a, t);


			stack.time[stack.top]--;
			if (stack.time[stack.top] == 0)
				res += stack.score[stack.top--];
		}
		else {
			if (stack.top == -1)
				continue;

			stack.time[stack.top]--;
			if (stack.time[stack.top] == 0)
				res += stack.score[stack.top--];
		}
	}
	printf("%d", res);
	
}