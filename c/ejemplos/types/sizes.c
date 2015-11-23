#include <stdio.h>

#define PR_SIZE(X) printf("Size of " # X " is %lu\n", sizeof(X))

int main() {

  PR_SIZE(char);
  PR_SIZE(short);
  PR_SIZE(int);
  PR_SIZE(long);
}
