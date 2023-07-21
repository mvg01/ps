#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int top;
	int *data;
}Stack;
void push(Stack* s, int n) {
	s->data[++s->top] = n;
}
int pop(Stack* s) {
	return s->data[s->top--];
}

int main()
{
	char str[51];
	Stack s;
	s.data = (int*)calloc(50, sizeof(int));
	s.top = 0;
	scanf("%s", str);
	int len = strlen(str);
	int res[51] = { 0 };
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			s.data[s.top] -= 1;
			res[++s.top] = str[i - 1] - '0';
		}
		else if (str[i] == ')') {
			s.data[s.top - 1] += s.data[s.top] * res[s.top];
			s.data[s.top--] = 0;
		}
		else {
			s.data[s.top]++;
		}
	}
	printf("%d", s.data[0]);
}