#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
typedef struct STACK {
	char data[100001];
}S;

void push(S* s,char ele)
{
	s->data[++top] = ele;
}

void pop(S* s)
{
	top--;
}

char peek(S* s)
{
	return s->data[top];
}

char str[100001];
int main()
{
	int i, len, cnt = 0;
	S s;
	scanf("%s", str);
	len = strlen(str);

	int chk = 0;  //언제 레이저인지 판별하기 위한 bool 변수
	for (i = 0; i < len; i++)
	{
		if (str[i] == '(') {
			push(&s, '(');
			chk = 0;
		}
		else if (str[i] == ')' && chk==0) { //레이저인 경우
			pop(&s);
			cnt += (top + 1);  //top개수 +1 만큼 조각 생김
			chk = 1;
		}

		else if (str[i] == ')') {
			if (top > -1) {  //스택에 있을때 pop 해야함
				pop(&s);
				cnt++;       //자른 후 꼬다리가 하나씩 남음
			}
		}
	}
	if (top > -1)  //남은 조각이 있을 수 있다.
		cnt += (top + 1);

	printf("%d", cnt);
}

/* 생각해본 반례 모음 이것들만 통과되도 정답일 겁니다.

(((()   -> 6
()()()  -> 0
((()))  -> 4

*/

