#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int top;
	double data[101];
}Stack;

void init(Stack* s) {
	s->top = -1;
}
void push(Stack* s,double item) {
	s->data[++s->top] = item;
}
double pop(Stack* s) {
	return s->data[s->top--];
}

int main()
{
	Stack s;
	init(&s);
	int n;
	double num[101];
	char str[101];
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 0; i < n; i++)
		scanf("%lf", &num[i]);

	for (int i = 0; i < strlen(str); i++)
	{
		double temp = 0;
		if (str[i] >= 'A' && str[i] <= 'Z')
			push(&s, num[str[i] - 'A']);

		else {
			if (str[i] == '+') {
				temp = pop(&s) + pop(&s);
				push(&s, temp);
			}
			if (str[i] == '-') {
				temp = (pop(&s) - pop(&s)) * -1;
				push(&s, temp);
			}
			if (str[i] == '*') {
				temp = pop(&s) * pop(&s);
				push(&s, temp);
			}
			if (str[i] == '/') {
				double first = pop(&s);
				double second = pop(&s);
				temp = second / first;
				push(&s, temp);
			}
		}
	}
	printf("%.2lf", pop(&s));
}