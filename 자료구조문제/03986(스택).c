#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int top;
	char data[100001];
}Stack;

void init(Stack* s) {
	s->top = -1;
}
void push(Stack* s, char item) {
	s->data[++s->top] = item;
}
char pop(Stack* s) {
	return s->data[s->top--];
}
char peek(Stack* s) {
	return s->data[s->top];
}
int empty(Stack* s) {
	return (s->top == -1);
}

char str[100001];
int main()
{
	int n,len, res = 0;
	scanf("%d", &n);
	Stack s;
	for (int i = 0; i < n; i++)
	{
		init(&s);
		scanf("%s", str);
		len = strlen(str);

		for (int j = 0; j < len; j++) 
		{
			if (empty(&s))
				push(&s, str[j]);

			else {
				if (peek(&s) == str[j])
					pop(&s);
				else
					push(&s, str[j]);
			}
		}
		if (empty(&s))
			res++;
	}
	printf("%d", res);
}