#include <stdio.h>
#include <string.h>

int queue[10001];
int idx = 0;
int front_queue = 0;

void push(void) {
	scanf("%d", &queue[idx]);
	idx++;
}
void pop(void) {
	if (idx - front_queue > 0) {
		printf("%d\n", queue[front_queue]);
		front_queue++;
	}
	else
		printf("-1\n");
}
void size(void) {
	printf("%d\n", idx - front_queue);
}
void empty(void) {
	if (idx - front_queue > 0)
		printf("0\n");
	else
		printf("1\n");
}
void front(void) {
	if (idx - front_queue > 0) 
		printf("%d\n", queue[front_queue]);
	else
		printf("-1\n");
}
void back(void) {
	if (idx - front_queue > 0)
		printf("%d\n", queue[idx-1]);
	else
		printf("-1\n");
}

int main()
{
	int n;
	char s[15];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		if (strcmp(s, "push") == 0)
			push();
		else if (strcmp(s, "pop") == 0)
			pop();
		else if (strcmp(s, "size") == 0)
			size();
		else if (strcmp(s, "empty") == 0)
			empty();
		else if (strcmp(s, "front") == 0)
			front();
		else if (strcmp(s, "back") == 0)
			back();
	}
}