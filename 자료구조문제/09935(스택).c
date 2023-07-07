#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[1000001];
char res[1000001];
char bomb[40];
typedef struct {
	int top;
	char *data;
}Stack;
void push(Stack *s, char e) {
	s->data[++(s->top)] = e;
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

int main()
{	
	scanf("%s", str);
	scanf("%s", bomb);
	Stack s;
	s.top = -1;
	int len = strlen(str), blen = strlen(bomb);
	s.data = (char*)malloc(sizeof(char) * (len + 1));
	int bomb_cur = 0, chk = 1;

	for (int i = 0; i < len; i++) {

		push(&s, str[i]);  //일단 push
 		chk = 1;

		for (int j = 0; j < blen; j++) {  //스택 내에 폭발문자열이 있는지 chk
			if (bomb[blen - j - 1] != s.data[s.top - j]) {
				chk = 0;
				break;
			}
		}
		if (chk) {  //폭발 문자열이 스택에 있다면 blen 개수만큼 pop
			int cnt = blen;
			while (cnt--) {
				pop(&s);
			}
		}
	}

	if (empty(&s))
		printf("FRULA");
	else {
		res[s.top + 1] = '\0';
		for (int i = s.top; i >= 0; i--) {
			res[i] = pop(&s);
		}
		printf("%s", res);
	}
    free(s.data);
}

/*  도움이 되었던 반례
in:
AABCBABCBABCCABCC
ABC

out:
ABBCC
*/