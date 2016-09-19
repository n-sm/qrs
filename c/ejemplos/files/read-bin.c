#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024*1024
int main(int argc, char *argv[])
{

    char * filename = argv[1];
    struct stat st;
    if (stat(filename, &st) == 0)
    {
	FILE *fp;
	long int buffer_size = st.st_size < MAX_BUFFER_SIZE ?
	   st.st_size : MAX_BUFFER_SIZE;
	fp = fopen (filename,  "rb" );
	char x[buffer_size];

	fread(x, sizeof(x[0]), buffer_size, fp);
	fclose(fp);
	for(int i = 0; i < buffer_size; i++)
	   printf("%c",x[i]);
	if (buffer_size == MAX_BUFFER_SIZE)
	   printf("warning, file too large, only partialy displayed\n");

	return 0;
    }
    else
    {
	printf("file does not exists\n");
	return -1;
    }

}

