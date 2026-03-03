#pragma once

#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	size_t flags;
} Bitset;

bool matches(Bitset const *set, size_t const count, ...);
void set_flag(Bitset *set, size_t const flag);
void set_flags(Bitset *set, size_t count, ...);
void toggle_flag(Bitset *set, size_t const flag);
void toggle_flags(Bitset *set, size_t const count, ...);
void toggle_all_flags(Bitset *set);
void clear_flag(Bitset *set, size_t flag);
void clear_flags(Bitset *set, size_t const count, ...);
void clear_all_flags(Bitset *set);
