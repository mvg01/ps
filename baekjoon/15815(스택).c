#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int top;
	int data[101];
}Stack;

void init(Stack* s) {
	s->top = -1;
}
void push(Stack* s, int item) {
	s->data[++s->top] = item;
}
int pop(Stack* s) {
	return s->data[s->top--];
}

int main()
{
	Stack s;
	init(&s);
	char str[101];
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++)
	{
		int temp = 0;
		if (str[i] >= '0' && str[i] <= '9')
			push(&s, str[i] - '0');

		else {
			if (str[i] == '+') {
				temp = pop(&s) + pop(&s);
				push(&s, temp);
			}
			else if (str[i] == '-') {
				int first = pop(&s);
				int second = pop(&s);
				temp = second - first;
				push(&s, temp);
			}
			else if (str[i] == '*') {
				temp = pop(&s) * pop(&s);
				push(&s, temp);
			}
			else if (str[i] == '/') {
				int first = pop(&s);
				int second = pop(&s);
				temp = second / first;
				push(&s, temp);
			}
		}
	}
	printf("%d", pop(&s));
}

