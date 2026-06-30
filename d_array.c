#include "d_array.h"

int comp_int(void const *ptr1, void const *ptr2)
{
  return (*(int const *)ptr1 > *(int const *)ptr2) -
         (*(int const *)ptr1 < *(int const *)ptr2);
}

int comp_ll(void const *ptr1, void const *ptr2)
{
  return (*(long long const *)ptr1 > *(long long const *)ptr2) -
         (*(long long const *)ptr1 < *(long long const *)ptr2);
}

int comp_float(void const *ptr1, void const *ptr2)
{
  return (*(float const *)ptr1 > *(float const *)ptr2) -
         (*(float const *)ptr1 < *(float const *)ptr2);
}

int comp_double(void const *ptr1, void const *ptr2)
{
  return (*(double const *)ptr1 > *(double const *)ptr2) -
         (*(double const *)ptr1 < *(double const *)ptr2);
}

int comp_str(void const *ptr1, void const *ptr2)
{
  return strcmp(*(char *const *)ptr1, *(char *const *)ptr2);
}
