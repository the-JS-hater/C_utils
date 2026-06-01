#include "file_handling.h"


char const *read_file(char const* file_name)
{
	FILE *f_ptr = fopen(file_name, "r");
	if (!f_ptr)
	{
		perror("failed to open file");
		exit(1);
	}
	if (fseek(f_ptr, 0, SEEK_END))
	{
		fclose(f_ptr);
		perror("fseek failed");
		exit(1);
	}
	long size = ftell(f_ptr);
	if (size < 0)
	{
		fclose(f_ptr);
		perror("ftell failed");
		exit(1);
	}
	rewind(f_ptr);
	char *data_buffer = malloc((size_t)size+1);
	if (fread(data_buffer, 1, size, f_ptr) < size)
	{
		fclose(f_ptr);
		perror("failed to read file");
		exit(1);
	}
	fclose(f_ptr);
	data_buffer[size] = '\0';
	return data_buffer;
}
