#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 1501

typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];

	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
			child++;

		if (temp.key <= h->heap[child].key)
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main(void) 
{
	int n, x;
	HeapType* heap;
	heap = create();
	init(heap);
	scanf("%d", &n);
	for (int i = 0; i < n * n; i++) {
		scanf("%d", &x);
		element data, compare;
		data.key = x;
		if (heap->heap_size < n) {
			insert_min_heap(heap, data);
		}
		else {
			compare = delete_min_heap(heap);
			if (x > compare.key) {
				insert_min_heap(heap, data);
			}
			else
				insert_min_heap(heap, compare);
		}
	}
	
	element temp;
	temp = delete_min_heap(heap);
	printf("%d", temp.key);
	free(heap);
	return 0;
}