#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct
{
	void* p;
	int num;
}leaf;

typedef struct
{
	leaf* arr;
	int br;
}heap;

heap* create()
{
	heap* arr = (heap*)malloc(sizeof(heap));
	arr->arr = (leaf*)malloc(10000 * sizeof(leaf));
	arr->br = 0;
	return arr;
}
void destroy(heap* s)
{
	free(s->arr);
	free(s);
}
void fix_top(heap* s, int n)
{
	int r = (n - 1) / 2;
	if (n == 0)
		return;
	if (s->arr[r].num < s->arr[n].num)
	{
		int tmp = s->arr[r].num;
		s->arr[r].num = s->arr[n].num;
		s->arr[n].num = tmp;
		fix_top(s, r);
	}
}
void add(heap* h, int element)
{
	h->arr[h->br].num = element;
	fix_top(h, h->br);
	h->br++;
}
void fix_bottom(heap* s, int n)
{
	int l = 2 * n + 1;
	int d = 2 * n + 2;
	if (l >= s->br && d >= s->br)
		return;
	else if (s->arr[n].num < s->arr[l].num || s->arr[n].num < s->arr[d].num)
	{
		if (s->arr[l].num > s->arr[d].num)
		{
			int temp = s->arr[l].num;
			s->arr[l].num = s->arr[n].num;
			s->arr[n].num = temp;
			fix_bottom(s, l);
		}
		else if (s->arr[d].num > s->arr[l].num)
		{
			int temp = s->arr[n].num;
			s->arr[n].num = s->arr[d].num;
			s->arr[d].num = temp;
			fix_bottom(s, d);
		}
	}
}
void remove_leaf(heap* s)
{
	int temp = s->arr[s->br - 1].num;
	s->arr[0].num = temp;
	s->br--;
	fix_bottom(s, 0);
}
void main()
{
	heap* arr = create();

	add(arr, 5);
	add(arr, 4);
	add(arr, 3);
	add(arr, 2);
	add(arr, 1);

	remove_leaf(arr);

	for (int i = 0; i < arr->br; i++)
		printf("%d\n", arr->arr[i].num);

	destroy(arr);
}


