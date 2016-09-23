#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    char * filename = argv[1];
    struct stat st;
    if (stat(filename, &st) != 0)
    {
	FILE *fp;
	fp = fopen (filename,  "wb" );
	char x[10]="ABCDEFGHIJ";

	fwrite(x, sizeof(x[0]), sizeof(x)/sizeof(x[0]), fp);
	fclose(fp);
	return 0;
    }
    else
    {
	printf("file exists\n");
	return -1;
    }

}

