#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100001];  //처음 문자열 받을 배열
typedef struct DlistNode {
	char data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
}DlistNode;

void init(DlistNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

DlistNode* dinsert(DlistNode* before, char value)
{
	DlistNode* newnode = (DlistNode*)malloc(sizeof(DlistNode));
	newnode->data = value;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DlistNode* head, DlistNode* removed)
{
	if (removed == head)
		return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

//현재 커서의 위치까지 구현해 놓은 print list 함수. 
void print_dlist(DlistNode* phead,DlistNode* cur) 
{
	DlistNode* p;
	if (phead == cur)
		printf("|");
	for (p = phead->rlink; p != phead; p = p->rlink)
	{
		printf("%c", p->data);
		if (cur == p)
			printf("|");
	}
	printf("\n");
}

void print(DlistNode* phead)
{
	DlistNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
		printf("%c", p->data);
}

int main(void)
{
	DlistNode* head = (DlistNode*)malloc(sizeof(DlistNode));
	init(head);
	int len, i;
	scanf("%s", str);
	len = strlen(str);
	for (i = len - 1; i >= 0; i--)  //insert가 맨 앞 헤드의 왼쪽 부터 되므로 거꾸로 해줌
		dinsert(head, str[i]);

    //ex)  head->a->b->c 
	DlistNode* cur = head->llink;  //현재 커서위치는 head의 llink -> 문장의 가장 끝
	//print_dlist(head,cur);       //확인을 위한 커서포함한 print 함수

	int m;
	char point, key;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf(" %c", &point);  

		if (point == 'P') {
			scanf(" %c", &key);
			dinsert(cur, key);  //cur의 오른쪽 링크에 key 삽입
			cur = cur->rlink;   //cur의 오른쪽 링크에 문자가 들어왔으니 커서를 오른쪽으로 옮겨준다.
		}

		else if (point == 'L') {
			if(cur!=head)   //커서가 가장 앞에 있는 것이 아니라면
				cur = cur->llink;
		}
		else if (point == 'D') {  
			if (cur->rlink != head)  //커서가 가장 끝에 있는 것이 아니라면
				cur = cur->rlink;
		}

		else if (point == 'B')
		{
			if (cur!= head) {
				DlistNode* temp = cur;  //임시 포인터 변수 temp에 받아두고 커서를 커서를 왼쪽으로 옮긴다.
				cur = cur->llink;       //커서를 왼쪽으로 옮겨준다.
				ddelete(head, temp);    //임시 포인터 변수를 참조해서 제거한다.
			}
		}
		//print_dlist(head,cur);
	}
	print(head);
}
