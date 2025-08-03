#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int top;
	char data[2001];
}Stack;

char pop(Stack *s) {
	return s->data[s->top--];
}
void push(Stack* s,char n) {
	s->data[++s->top] = n;
}
char peek(Stack* s) {
	return s->data[s->top];
}

int main()
{
	int p = 1;
	while (1) {
		Stack s;
		s.top = -1;
		char str[2001];
		scanf("%s", str);
		if (str[0] == '-')
			break;
		
		int len = strlen(str), res = 0;
		//문자열에 {} <-이런식으로 주어져 있는경우 제거하기 (연산 필요 X)
		for (int i = 0; i < len; i++)
		{
			if (str[i] == '}' && peek(&s) == '{')
				pop(&s);
			else
				push(&s, str[i]);
		}

		while (s.top != -1)
		{
			char a, b;
			a = pop(&s);
			b = pop(&s);
			if (a == b)  //  {{ 혹은 }} 의 경우, 1번의 연산으로 가능
				res += 1;
			else         //  }{ 인 경우, 2번 연산 해줘야함.
				res += 2;
		}

		printf("%d. %d\n", p++, res);
	}
}