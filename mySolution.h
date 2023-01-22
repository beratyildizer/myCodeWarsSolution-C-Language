#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define N 100

// www.codewars.com/kata/5324945e2ece5e1f32000370/solutions/c?filter=all&sort=best_practice&invalids=false
void fun(char* p);
char* strsum(const char* a, const char* b);

// www.codewars.com/kata/52a89c2ea8ddc5547a000863
typedef struct node_t Node;
struct node_t {
	const Node* next;
};
int loop_size(const Node* node);

// www.codewars.com/kata/525c7c5ab6aecef16e0001a5/solutions/c?filter=me&sort=best_practice&invalids=false
long parse_int(const char* number);

// www.codewars.com/kata/534e01fbbb17187c7e0000c6/solutions/c?filter=me&sort=best_practice&invalids=false
void spiralize(unsigned n, int spiral[N][N]);

// www.codewars.com/kata/51ba717bb08c1cd60f00002f/solutions/c?filter=me&sort=best_practice&invalids=false
char* range_extraction(const int* args, size_t n);


