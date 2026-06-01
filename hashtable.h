#pragma once

typedef struct
{

} HBucket;

typedef int (*hash_foo)(const void *item);
typedef int (*cmp_foo)(const void *a, const void *b);	 

typedef struct {
	hash_foo hash;
	cmp_foo compare;
} HTable;

HTable init_htable(hash_foo, cmp_foo);

void htable_insert();
void htable_delete();
void *htable_get();

