// то же самое, что было и в предыдущей программе,
// только мы сразу выходим из цикла, если найден первый делитель


#include <stdio.h>

int main() {

int a;
int s=1;
scanf("%d", &a);

for ( int n=2; n<a; n++) {
      if (a%n==0) {
        s=0;
        break;
}}
printf("%d \n", s);

}
