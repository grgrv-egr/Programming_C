#include <stdio.h>

int main() {

int s=1;
int n;

scanf("%d", &n);

for (int i=1; i<=n; i++) {
      s = s * i; }

printf("%d \n", s);
}
