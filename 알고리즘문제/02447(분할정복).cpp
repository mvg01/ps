#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int top;
	int* data;
}Stack;
void init(Stack* s, int n) {
	s->data = (int*)malloc(sizeof(int) * n);
	s->top = -1;
}
void push(Stack* s, int d) {
	s->data[++s->top] = d;
}
void pop(Stack* s) {
	s->top--;
}
int top(Stack* s) {
	if (s->top == -1)
		return -1;
	return s->data[s->top];
}

int main()
{
	int n, p, num, fret, res = 0;
	Stack s[6];   //기타줄 개수 만큼 스택이 필요
	scanf("%d %d", &n, &p);
	for (int i = 0; i < 6; i++)
		init(&s[i], p);  //각 스택에 최대 p개 까지 담을 수 있어야 함

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &num, &fret);
		if (top(&s[num - 1]) < fret) {
			push(&s[num - 1], fret);
			res++;
		}
		else if (top(&s[num - 1]) > fret) {
			while (1) {
				if (top(&s[num - 1]) <= fret || s[num - 1].top == -1)
					break;
				else
					pop(&s[num - 1]);

				res++;
			}

			if (top(&s[num - 1]) != fret) {  //이미 프렛위에 손이 있다면 손가락을 움직이지 않고 넘어감
				push(&s[num - 1], fret);
				res++;
			}
		}
		else  //이미 프렛위에 손이 있다면 손가락을 움직이지 않고 넘어감
			continue;
	}
	printf("%d", res);
	for (int i = 0; i < 6; i++)
		free(s[i].data);
}