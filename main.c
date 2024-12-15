#include<stdio.h>
#include"dynarr.h"
#include<time.h>

int get_int(struct dynarr *arr, int index) {
	int *ptr = (int*) arr -> data;
	return *(ptr+index);
}

int main(void)
{
	struct dynarr *arr = create(sizeof(int), 1);
	int el1 = 1;
	int el2 = 2;
	add(arr, &el1);
	add(arr, &el2);
	printf("%d\n", *((int*) get(arr, 0)));
	printf("%d\n", get_int(arr, 1));

	clock_t start_time, end_time;
	start_time = clock();
	for (int i=0; i<1000000; i++) {
		add(arr, &i);
	}
	end_time = clock();
	printf("%f\n", ((double) (end_time-start_time)) / CLOCKS_PER_SEC);
	printf("%d\n", arr -> capacity);	
}
