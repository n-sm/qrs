#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void prhelp();

int main( int argc, char *argv[] )  
{

  int c, d = 0,estado = 1;
  
  char* after = NULL;
  char* before = NULL;
  char* condition = NULL;
  

  while ((c = getopt (argc, argv, "ha:b:c:d:")) != -1)
    switch (c)
      {
      case 'h':
	prhelp(); return 0;
      case 'a':
	estado--;
	after = optarg;
	break;
      case 'b':
	before = optarg;
	break;
      case 'c':
	condition = optarg;
	break;
      case 'd':
	d = atoi(optarg);
	break;
      case '?':
        if (optopt == 'd' || optopt == 'f')
	  {
	    // aca cuando falta optarg
	    prhelp();
	  }
        else if (isprint (optopt))
	  {
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

  if(optind>=argc)
    {
      prhelp();
      return 0;
    }

  int index;
  for (index = optind; index < argc; index++)
    {

      char * filename = argv[index];
      FILE *fp  = fopen(filename, "r");
      char *line = NULL;
      size_t len = 0;
      ssize_t read;
      
      while ((read = getline(&line, &len, fp)) != -1) {
	switch (estado)
	  {
	  case 0:
	    if (strstr(line, after)) estado++;
	    continue;
	  case 1:
	    if (d) {d--;continue;}
	    if (before && strstr(line, before)) return 0;
	    if (condition && !strstr(line, condition)) continue;
	    printf("%s", line);
	  }
      }

      fclose(fp);
    }

  return 0;
}

void prhelp()
{
  printf("\nUsage: linesBetween [options] file[s]\n\nOptions:\n");
  printf("\t -a after\n\t -b before\n\t -c condition \n");
}


