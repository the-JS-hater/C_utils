#include "bitset.h"


static inline size_t bitmask(size_t const flag)
{
  if (flag >= sizeof(size_t) * 8)
  {
    fprintf(stderr, "flag value exceeds capacity of bitset\n");
    exit(1);
  }
  return (size_t)1 << flag;
}

bool matches(Bitset const *set, size_t const count, ...)
{
  va_list args;
  va_start(args, count);
  for (size_t i = 0; i < count; ++i)
  {
    size_t flag = va_arg(args, size_t);
    if (set->flags & bitmask(flag)) continue;
    va_end(args);
    return false;
  }
  va_end(args);
  return true;
}

void set_flag(Bitset *set, size_t const flag) { set->flags |= bitmask(flag); }

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
  set->flags ^= bitmask(flag);
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

void toggle_all_flags(Bitset *set) { set->flags = ~set->flags; }

void clear_flag(Bitset *set, size_t flag) { set->flags &= ~bitmask(flag); }

void clear_flags(Bitset *set, size_t const count, ...)
{
  va_list args;
  va_start(args, count);
  for (size_t i = 0; i < count; ++i)
  {
    size_t flag = va_arg(args, size_t);
    clear_flag(set, flag);
  }
  va_end(args);
}

void clear_all_flags(Bitset *set) { set->flags = 0; }
