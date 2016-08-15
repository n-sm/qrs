#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

void prhelp();



int main( int argc, char *argv[] )  
{
  int d = 0, c;
  int nline = 0;

  while ((c = getopt (argc, argv, "hn")) != -1)
    switch (c)
      {
      case 'h':
	prhelp();
	return 0;
      case 'n':
	nline = 1;
	break;
      case '?':
        if (optopt == 'd' || optopt == 'f') {
	  printf("case?\n");
	  prhelp();
	}
        else if (isprint (optopt)) {
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
	  prhelp();
	}
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
	
      }


  if(optind < argc )
    {    

      int index;
      for (index = optind; index < argc; index++)
	{

	  char * filename = argv[index];
	  FILE *fp  = fopen(filename, "r");
	  char *line = NULL;
	  size_t len = 0;
	  ssize_t read;

	  while ((read = getline(&line, &len, fp)) != -1) {
	    if(nline > 0) printf("%d\t", nline++);
	    printf("%s", line);
	}

	fclose(fp);
      }
    }
  else
    {
      char *line = NULL;
      size_t len = 0;
      ssize_t read;

      while ((read = getline(&line, &len, stdin)) != -1) {
	if(nline > 0) printf("%d\t", nline++);
	printf("%s", line);
      }

      free(line);
      exit(EXIT_SUCCESS);
      }
    
  return 0;
}

void prhelp()
{
  printf("\nUsage: cat.c [options] [string]\n\nOptions:\n");
  printf("\t-f file\n\n");
}


