#include "file_handling.h"


int main(int argc, char **argv)
{ 
  if (argc < 2)
  {
    printf("No arg given\n");
    return 1;
  }
  char const *filename = argv[1];
  char *buff;
  if(read_file(&buff, filename))
  {
    printf("failed to read file\n");
    return 1;
  }
  print_file(buff);
  return 0;
}
