#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"dynarr.h"

struct dynarr * create(unsigned element_size, unsigned initial_capacity) {
	struct dynarr *array = malloc(sizeof(struct dynarr));
	array->data = malloc(element_size*initial_capacity);
	array->size = 0;
	array->capacity = initial_capacity;
	array->element_size = element_size;
	return array;
}

void add_many(struct dynarr *arr, void *elements, int count) {
	while (arr->size + count > arr->capacity) {
		// Double the capacity
		arr->data = realloc(arr->data, 2 * arr->element_size * arr->capacity);
		arr->capacity = 2*arr->capacity;
	}
	char *dest = (char*) arr->data;
	dest += arr->size * arr->element_size;
	arr->size+=count;
	memcpy(dest, elements, arr->element_size*count);

}

void add(struct dynarr *arr, void *element) {
	add_many(arr, element, 1);
}

void* get(struct dynarr *arr, int index) {
	char *ptr = (char*) arr->data;
	return (void*) (ptr + (index*arr->element_size));
}


