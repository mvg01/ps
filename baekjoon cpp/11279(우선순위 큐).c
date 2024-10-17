#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
}element;

typedef struct {
	element heap[100001];
	int heap_size;
}HeapType;

HeapType* create(void)
{
	HeapType* p;
	p = (HeapType*)malloc(sizeof(HeapType));
	return p;
}

void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, int item)
{
	int i;
	i = ++(h->heap_size);
	//가장 끝 노드에서 부터 트리를 거슬러 올라가면서 부모노드와 비교
	while ((i != 1) && (item > h->heap[i / 2].key)) { 
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i].key = item;
}

int delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;
	item = h->heap[1];  //루트노드 (삭제될 노드)
	temp = h->heap[(h->heap_size)--]; //가장 끝 노드
	
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		//현재 노드의 자식노드 둘 중 하나에서 더 큰 자식 노드를 찾는다
		if ((child < h->heap_size) && h->heap[child].key < h->heap[child + 1].key)
			child++; //오른쪽이 더 크면 오른쪽 자식을 가리키게 함

		if (temp.key >= h->heap[child].key)
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item.key;
}

void heap_sort(int n)
{
	int i, x;
	HeapType* h;
	h = create();
	init(h);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x == 0) {
			if (h->heap_size == 0)
				printf("0\n");
			else {
				printf("%d\n", delete_max_heap(h));
			}
		}
		else {
			insert_max_heap(h, x);
		}
	}
	free(h);
}

int main()
{
	int n;
	scanf("%d", &n);
	heap_sort(n);
}
