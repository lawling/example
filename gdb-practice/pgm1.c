#include <stdio.h>

int power(int x, int y) {
  if (x == y + 1)
    return x;
  else return x * power(x, y - 1);
}

int main() {
  int a, b, n;

  a= 2;
  b= 5;
  n= power(a, b);
  printf("%d to the %d is %d.\n", a, b, n);

  a= 5;
  b= 2;
  n= power(a, b);
  printf("%d to the %d is %d.\n", a, b, n);

  return 0;
}
