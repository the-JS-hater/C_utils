#pragma once

#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

typedef struct
{
  int *items;
  size_t capacity, size;
} iVec;

typedef struct
{
  long long *items;
  size_t capacity, size;
} llVec;

typedef struct
{
  float *items;
  size_t capacity, size;
} fVec;

typedef struct
{
  double *items;
  size_t capacity, size;
} dVec;

typedef struct
{
  char const **items;
  size_t capacity, size;
} strVec;

#define append(xs, x)\
do {\
  if (xs.size >= xs.capacity)\
  {\
    if (xs.capacity == 0) xs.capacity = 256;\
    else xs.capacity *= 2;\
    xs.items = realloc(xs.items, xs.capacity * sizeof(*xs.items));\
  }\
  xs.items[xs.size++] = x;\
} while(0);

#define remove(xs, idx)\
do {\
  if (idx >= xs.size) break;\
  for (int i = idx; i < xs.size; ++i)\
  {\
    xs.items[i] = xs.items[i+1];\
  }\
  xs.size--;\
} while(0);

#define sort(xs, comp)\
do {\
  qsort(xs.items, xs.size, sizeof(*xs.items), comp);\
} while(0);

#define contains(xs, x, comp) (\
  {\
    int retval = false;\
    for (int i = 0; i < xs.size; ++i)\
    {\
      if (!comp(&xs.items[i], &x))\
      {\
        retval = true;\
        break;\
      }\
    }\
    retval;\
  }\
)

int comp_int(void const *ptr1, void const *ptr2);
int comp_ll(void const *ptr1, void const *ptr2);
int comp_float(void const *ptr1, void const *ptr2);
int comp_double(void const *ptr1, void const *ptr2);
int comp_str(void const *ptr1, void const *ptr2);
