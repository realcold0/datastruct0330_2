#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10

typedef int element;
typedef struct {
	element* data;		// data�� �����ͷ� ���ǵȴ�. 
	int capacity;		// ���� ũ��
	int top;
} StackType;

// ���� ���� �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType* s, element item)
{
	if (is_full(s)) {
		s->capacity *= 2;
		s->data =
			(element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		printf("pop -1\n");
		fprintf(stderr, "Stack Empty!\n");
		return;
	}
	else
	{
		printf("pop : %d\n", s->data[(s->top)]);
		return s->data[(s->top)--];
	}
}
int main(void)
{
	StackType s;

	init_stack(&s);

	srand(time(NULL));
	printf("-------using Malloc-------\n");
	int rand_num;
	for (int i = 0; i < 30; i++)
	{
		printf("[%d]\t", i);
		rand_num = rand() % 100 + 1;
		if (rand_num % 2 == 0)
		{
			printf("push :  %d\n", rand_num);
			push(&s, rand_num);
		}
		else {
			pop(&s);
		}
	}
}