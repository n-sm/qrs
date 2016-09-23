#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if ( argc != 3 )
    {
	printf("Debe haber dos parametros\n");
	return -1;
    }
    char * readfilename = argv[1];
    char * writefilename = argv[2];
    struct stat read_st, write_st;
    if (stat(writefilename, &write_st) == 0)
    {
	printf("output file exists\n");
	return -1;
    }
    
    off_t readfilesize = stat(readfilename, &read_st);
    if ( read_st.st_size < 0)
    {
	printf("inputfile does not exists\n");
	return -1;
    }
    else if (read_st.st_size > 1024*1024)
    {
	printf("file too large\n");
	return -1;
    }
    
    FILE *fpr;
    fpr = fopen (readfilename,  "rb" );
    unsigned char * buffer = malloc(read_st.st_size);
    
    fread(buffer, sizeof(char), read_st.st_size, fpr);

    FILE *fpw;
    fpw = fopen (writefilename,  "wb" );

    fwrite(buffer, sizeof(char), read_st.st_size, fpw);

    fclose(fpw);
    fclose(fpr);

    return 0;
    

}

