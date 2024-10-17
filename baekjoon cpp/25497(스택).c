#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int top;
	char data[101];
}Stack;

void init(Stack* s) {
	s->top = -1;
}
void push(Stack* s,char item) {
	s->data[++s->top] = item;
}
char pop(Stack* s) {
	return s->data[s->top--];
}
char peek(Stack* s) {
	return s->data[s->top];
}

int main()
{
	Stack s;
	Stack l;
	init(&s);
	init(&l);
	char skill[200001];
	int n, len, cnt = 0;
	scanf("%d", &n);
	scanf("%s", skill);
	len = strlen(skill);
	for (int i = 0; i < len; i++)
	{
		if (skill[i] == 'S')
			push(&s, 'S');
		else if (skill[i] == 'L')
			push(&l, 'L');

		else if (skill[i] == 'K') {
			if (s.top != -1) {
				cnt++;
				pop(&s);
			}
			else {  //스택에 S가 없다면 즉시 종료
				break;
			}
		}
		else if (skill[i] == 'R') {
			if (l.top != -1) {
				cnt++;
				pop(&l);
			}
			else {  //스택에 L이 없다면 즉시 종료
				break;
			}
		}
		else
			cnt++;
	}
	printf("%d", cnt);
}