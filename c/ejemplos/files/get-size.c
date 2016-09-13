#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
//#define COLUMNSIZE(x) "%" # x"ld"
off_t fsize(const char *filename);

int main(int argc, char *argv[])
{

    off_t size, max = 0, *sizes;
    char * filename;

    sizes = malloc(sizeof(off_t) * argc);
    
    for (int i = 1; i < argc; i++)
    {
	sizes[i] = fsize(argv[i]);
	if(max < sizes[i])
	    max = sizes[i];
    }

    for (int i = 1; i < argc; i++)
    {
	filename = argv[i];
	printf("%10ld  %s\n", sizes[i], argv[i]);
    }

    free(sizes);
    return 0;
}


off_t fsize(const char *filename)
{
    struct stat st;
    if (stat(filename, &st) == 0)
	return st.st_size;
    return -1;
}
