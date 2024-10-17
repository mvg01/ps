#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int top;
	char d[51];
}Stack;

void init(Stack* s)
{
	s->top = -1;
}

void push(Stack* s, char it)
{
	s->d[++s->top] = it;
}

void pop(Stack* s)
{
	s->top--;
}

int main()
{
	Stack stack;
	init(&stack);
	char s[51];
	int cnt = 0;
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++)
	{
		if (stack.top == -1) { //스택 비어있을 땐
			if (s[i] == ')')
				cnt++;
			else if (s[i] == '(')
				push(&stack, '(');
		}
		else {  // '(' 가 하나라도 있을 때
			if (s[i] == '(')
				push(&stack, '(');
			else if (s[i] == ')')
				pop(&stack);
		}
	}

	while (stack.top > -1) { //스택 빌 때까지 '(' 에 맞는 ')' 추가 개수 더하기
		pop(&stack);
		cnt++;
	}
	printf("%d", cnt);
}