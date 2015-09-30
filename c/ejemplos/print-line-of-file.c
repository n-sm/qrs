#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

void printLine(char * fileName, int lineNumber);

int main ( int argc, char *argv[] ) {
  int c;
  int line = 1;
  
  while ((c = getopt (argc, argv, "l:")) != -1)
    switch (c)
      {
      case 'l':
	if (!isdigit(*optarg)) {
	  printf("\nOptarg must be a digit.\n");
	  exit(1);
	}
	line = atoi(optarg);
	break;

      case '?':
        return 1;
      default:
	abort();
      }
  if (argc == 1) {
    printf("\nFile is missing\n");
    exit(1);
      }
  printLine(argv[argc-1], line);
}

void printLine(char * fileName, int lineNumber)
{
  int currentLine = 1;
  char ch;
  FILE *fp  = fopen(fileName, "r");
  if (fp == NULL) {
    printf("Cannot open file %s\n", fileName);
    exit(1);
  }
  printf("l%d:", lineNumber);
  while ((ch = fgetc(fp)) != EOF)
    {
      if (ch == '\n') currentLine++;
      if (currentLine == lineNumber) {
	printf("%c", ch);
      }
    }
  fclose(fp);
}
