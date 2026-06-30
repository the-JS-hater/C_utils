#include "file_handling.h"


int read_file(char **data_buffer, char const* file_name)
{
	FILE *f_ptr = fopen(file_name, "r");
	if (!f_ptr)
	{
		printf("failed to open file\n");
		return -1;
	}
	if (fseek(f_ptr, 0, SEEK_END))
	{
		fclose(f_ptr);
		printf("fseek failed\n");
		return -1;
	}
	long size = ftell(f_ptr);
	if (size < 0)
	{
		fclose(f_ptr);
		printf("ftell failed\n");
		return -1;
	}
	rewind(f_ptr);
	*data_buffer = malloc(size+1);
	if (fread(*data_buffer, 1, size, f_ptr) < size)
	{
		fclose(f_ptr);
		printf("failed to read file\n");
		free(*data_buffer);
    return -1;
	}
	fclose(f_ptr);
	(*data_buffer)[size] = '\0';
	return 0;
}

void print_file(char const* data_buffer)
{
  printf("%s\n", data_buffer);
}
