#include <stdio.h>

#include "bitset.h"


typedef enum {
  A,
  B,
  C,
} TestFlags;


int main()
{
  Bitset set = {0};
  printf("Empty set:\n");
  printf("matches: A ? %d\n", matches(&set, 1, A));
  printf("set: A\n");
  set_flag(&set, A);
  printf("matches: A ? %d\n", matches(&set, 1, A));
  printf("matches: B ? %d\n", matches(&set, 1, B));
  printf("matches: A, B, C ? %d\n", matches(&set, 3, A, B, C));
  printf("set: B\n");
  set_flag(&set, B);
  printf("matches: A, B ? %d\n", matches(&set, 2, A, B));
  printf("set: C\n");
  set_flag(&set, C);
  printf("matches: A, B, C ? %d\n", matches(&set, 3, A, B, C));
  printf("Clear flags\n");
  clear_all_flags(&set);
  printf("matches: B ? %d\n", matches(&set, 1, B));
  printf("set: C\n");
  set_flag(&set, C);
  printf("Toggle flags\n");
  toggle_all_flags(&set);
  printf("matches: A, B ? %d\n", matches(&set, 2, A, B));
  printf("Toggle: A\n");
  toggle_flag(&set, A);
  printf("matches: B ? %d\n", matches(&set, 1, B));
  printf("Toggle: C\n");
  toggle_flag(&set, C);
  printf("matches: B, C ? %d\n", matches(&set, 1, C));
  printf("Clear flags\n");
  clear_all_flags(&set);
  printf("Set flags A, C\n");
  set_flags(&set, 2, A, C);
  printf("matches: A, C ? %d\n", matches(&set, 2, A, C));
}
