#ifndef DYNARR_H
#define DYNARR_H

struct dynarr {
	void *data;
	unsigned size;
	unsigned capacity;
	unsigned element_size;
};


struct dynarr * create(unsigned element_size, unsigned initial_capacity);

void add_many(struct dynarr *arr, void *elements, int count);

void add(struct dynarr *arr, void *element);

void* get(struct dynarr *arr, int index);

#endif
