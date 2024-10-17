#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int top;
	int* d;
}S;
int pop(S* s) {
	if (s->top == -1)
		return -1;
	else
		return s->d[s->top--];
}
int peek(S* s) {
	if (s->top == -1)
		return -1;
	else
		return s->d[s->top];
}
void push(S* s,int i) {
	s->d[++s->top] = i;
}
int n(S* s) {
	return s->top + 1;
}

int main()
{
	S s;
	s.top = -1;
	s.d = (int*)malloc(sizeof(int) * 1000001);
	int t, m, x;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &m);
		if (m == 1) {
			scanf("%d", &x);
			push(&s, x);
		}
		else if (m == 2)
			printf("%d\n", pop(&s));
		else if (m == 3)
			printf("%d\n", n(&s));
		else if (m == 4) {
			if (peek(&s) == -1)
				printf("1\n");
			else
				printf("0\n");
		}
		else
			printf("%d\n", peek(&s));
	}
	free(s.d);
}