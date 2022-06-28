#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int throw_error(void);
int binarySearch(int arr[], int l, int r, int x);
void swap(int* a, int* b);
int cmpfunc (const void * a, const void * b);

int main(void) {
  int arr[48040];

  arr[0] = 1;
  int k = 1;

  for (int i = 2; i <= 46340; i++) {
    int j = 2;

    while (pow(i, j) < 2147483647) {
      if(floor(pow(i, j)) == pow(i, j)) {
        arr[k] = pow(i, j);
        k++;
      }

      j++;
    }
  }

  printf("%d\n", k);

  qsort(arr, k, sizeof(int), cmpfunc);

  printf("Intervaly:\n");

  while (1) {
      int num_begin, num_end, i;
      int isValid;

      isValid = scanf("%d %d", &num_begin, &num_end);

      if (num_begin == EOF || num_end == EOF || isValid == EOF) {
        return 0;
      };

      if (isValid != 2 || num_end < num_begin) return throw_error();

      if (num_begin < 1 || num_end < 1) return throw_error();

      int result = num_end - num_begin + 1;

      for (i = 0; i <= k; i++) {
        if (arr[i] < num_begin) continue;

        if (arr[i] >= num_begin && arr[i] <= num_end && i == 0) {
          result -= 1;
        } else if (arr[i] >= num_begin && arr[i] <= num_end && arr[i] != arr[i-1]) result -= 1;

        if(arr[i] >= num_end) break;
      }

      printf("<%d;%d> -> %d\n", num_begin, num_end, result);
  }
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int throw_error(void) {
    printf("Nespravny vstup.\n");
    return 1;
}
