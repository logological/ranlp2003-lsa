/*-----------------------------------------------------------------------------
Filename: getrand.c
Purpose : Prints out random numbers, without replacement
Usage   : getrand num min max
-----------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int *r;
  int num = atoi(argv[1]);
  int min = atoi(argv[2]);
  int max = atoi(argv[3]);
  int range = max - min + 1;
  int x;

  /* Sanity checks */

  if (argc != 4) {
    fprintf(stderr, "Usage: getrand num min max\n");
    exit(EXIT_FAILURE);
  }

  if (num > range) {
    fprintf(stderr, "%s: Can't have range < num\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if (min > max) {
    fprintf(stderr, "%s: Can't have min > max\n", argv[0]);
    exit(EXIT_FAILURE);
  }


  /* initialize seed */

  srand(time(NULL));


  /* allocate memory */

  r = calloc(max - min + 1, sizeof(int));

  if (!r) {
    fprintf(stderr, "%s: Out of memory\n", argv[0]);
    exit(EXIT_FAILURE);
  }


  /* generate numbers */

  while (num) {
    x = rand() % range;
    if (!r[x]) {
      printf("%d\n", x + min);
      r[x] = 1;
      num--;
    }
  }

  return 0;
}
