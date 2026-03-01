#include "stdio.h"
#include "d_array.h"

int comp_int(void const *ptr1, void const *ptr2)
{
  return (*(int const *)ptr1 > *(int const *)ptr2) - (*(int const *)ptr1 < *(int const *)ptr2);
}

int comp_ll(void const *ptr1, void const *ptr2)
{
  return (*(long long const *)ptr1 > *(long long const *)ptr2) - (*(long long const *)ptr1 < *(long long const *)ptr2);
}

int comp_float(void const *ptr1, void const *ptr2)
{
  return (*(float const *)ptr1 > *(float const *)ptr2) - (*(float const *)ptr1 < *(float const *)ptr2);
}

int comp_double(void const *ptr1, void const *ptr2)
{
  return (*(double const *)ptr1 > *(double const *)ptr2) - (*(double const *)ptr1 < *(double const *)ptr2);
}

int comp_str(void const *ptr1, void const *ptr2)
{
  return strcmp(* (char * const *) ptr1, * (char * const *) ptr2);
}


int main() 
{
  iVec numbers = {};
  for (int i = 100; i >= 0; --i) append(numbers, i);
  for (int i = 0; i < numbers.size; ++i) 
    printf("numbers[%d] = %d\n",i, numbers.items[i]);
  printf("\nremoveing idx = 3\n\n");
  remove(numbers, 3);
  for (int i = 0; i < numbers.size; ++i) 
    printf("numbers[%d] = %d\n",i, numbers.items[i]);
  printf("\nSorting...\n\n");
  sort(numbers, comp_int);
  for (int i = 0; i < numbers.size; ++i) 
    printf("numbers[%d] = %d\n",i, numbers.items[i]);
  int a = 97;
  printf("numbers contains 97?: %d\n", contains(numbers, a, comp_int));
  a++;
  printf("numbers contains 98?: %d\n", contains(numbers, a, comp_int));
}
