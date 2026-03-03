#include "bitset.h"


bool matches(Bitset const *set, size_t const count, ...)
{
	va_list args;
	va_start(args, count);
	for (size_t i = 0; i < count; ++i)
	{
		size_t bit_mask = ((size_t)1 << va_arg(args, size_t));
		if (set->flags & bit_mask) continue;
		va_end(args);
		return false;
	}
	va_end(args);
	return true;
}

void set_flag(Bitset *set, size_t const flag)
{
	size_t bit_mask = ((size_t)1 << flag);
	set->flags |= bit_mask;
}

void set_flags(Bitset *set, size_t count, ...)
{
	va_list args;
	va_start(args, count);
	for (size_t i = 0; i < count; ++i)
	{
		size_t flag = va_arg(args, size_t);
		set_flag(set, flag);
	}
	va_end(args);
}

void toggle_flag(Bitset *set, size_t const flag)
{
	size_t bit_mask = ((size_t)1 << flag);
	set->flags ^= bit_mask;
}

void toggle_flags(Bitset *set, size_t const count, ...)
{
	va_list args;
	va_start(args, count);
	for (size_t i = 0; i < count; ++i)
	{
		size_t flag = va_arg(args, size_t);
		toggle_flag(set, flag);
	}
	va_end(args);
}

void toggle_all_flags(Bitset *set)
{
	set->flags = ~set->flags;
}

void clear_flag(Bitset *set, size_t flag)
{
	size_t bit_mask = ((size_t)1 << flag);
	set->flags &= ~bit_mask;
}

void clear_flags(Bitset *set)
{
	set->flags = 0;
}
