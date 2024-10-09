#include <stdio.h>

int main() {

    int a;
    int n=2;
    int flag = 0;

    scanf("%d", &a);

    while (a%n!=0){
        n++;
        if (n==a) {
            flag = 1;
            break;}
}
printf("%d \n", flag);
}
