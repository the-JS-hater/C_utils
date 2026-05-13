#include "stdio.h"
#include "d_array.h"

int map_func(int x) {return x * x;}
int reduce_func(int x, int y) {return x + y;}
int div_by_five(int x) {return x % 5 == 0;}

void print_int(int x) {printf("%d\n", x);}
void print_str(char const *str) {printf("%s\n", str);}

int main() 
{
  iVec numbers = {};
  printf("Empty?: %d\n", empty(numbers));
  for (int i = 10; i >= 0; --i) append(numbers, i);
  for (int i = 0; i < numbers.size; ++i) 
    printf("numbers[%d] = %d\n",i, numbers.items[i]);
  printf("Empty?: %d\n", empty(numbers));
  printf("\nremoving idx = 3\nb = pop()\n\n");
  vec_remove(numbers, 3);
  int b = pop(numbers);
  printf("b = %d\n", b);
  for (int i = 0; i < numbers.size; ++i) 
    printf("numbers[%d] = %d\n",i, numbers.items[i]);
  printf("\nSorting...\n\n");
  sort(numbers, comp_int);
  for (int i = 0; i < numbers.size; ++i) 
    printf("numbers[%d] = %d\n",i, numbers.items[i]);
  int a = 7;
  printf("numbers contains 7?: %d\n", contains(numbers, a, comp_int));
  a++;
  printf("numbers contains 8?: %d\n", contains(numbers, a, comp_int));
  printf("Insert(67, 5)\n");
  insert(numbers, 67, 5);
  for (int i = 0; i < numbers.size; ++i) 
    printf("numbers[%d] = %d\n",i, numbers.items[i]);
  printf("Clearing, and appending 2, 5, 7\n");
  clear(numbers);
  append(numbers, 2);
  append(numbers, 5);
  append(numbers, 7);
  for (int i = 0; i < numbers.size; ++i) 
    printf("numbers[%d] = %d\n",i, numbers.items[i]);
  printf("Copy of numpers\n");
  iVec numbers_copy = copy(numbers);
  for (int i = 0; i < numbers_copy.size; ++i) 
    printf("numbers_copy[%d] = %d\n",i, numbers_copy.items[i]);
  printf("Applying Map(x * x) on numbers_copy\n");
  map(numbers_copy, map_func);
  for (int i = 0; i < numbers_copy.size; ++i) 
    printf("numbers_copy[%d] = %d\n",i, numbers_copy.items[i]);
  printf("Applying pure Map(x * x) on original numbers\n");
  iVec mapped_numbers = pure_map(numbers, map_func);
  for (int i = 0; i < numbers.size; ++i) 
    printf("numbers[%d] = %d\n",i, numbers.items[i]);
  for (int i = 0; i < mapped_numbers.size; ++i) 
    printf("mapped_numbers[%d] = %d\n",i, mapped_numbers.items[i]);
  printf("sum of numbers: %d\n", reduce(numbers, reduce_func, 0));
  printf("numbers filtered for divisible by 5\n");
  iVec filtered = filter(numbers, div_by_five);
  for (int i = 0; i < filtered.size; ++i)
    printf("filtered[%d] = %d\n", i, filtered.items[i]);
  strVec names = {};
  append(names, "Ola");
  append(names, "Oscar");
  append(names, "Vilgot");
  append(names, "Morgan");
  sort(names, comp_str);
  for (int i = 0; i < names.size; ++i)
    printf("%s\n", names.items[i]);
  printf("For each loops\n");
  for_each(names, print_str);
  for_each(numbers, print_int);
}
