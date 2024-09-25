#include <stdio.h>

int main() {
    float a;
    float a1;
    float a2;
    char b;
    char far = 'f';
    char far1 = 'F';
    char cel = 'c';
    char cel1 = 'C';
    printf("Input temperature: ");
    scanf("%f%c", &a, &b);
    if (b==far || b==far1) {
        printf("Ouput temperature: ");
        a1 = ((a-32)/1.8);
        printf("%.1f%c\n", a1, cel);
    } else if (b==cel || b==cel1) {
        a2 = ((a*1,8)+32);
        printf("Ouput temperature: "); printf("%.1f%c\n", a2, far);
    } else {
        printf("Ouput error\n");
}
}
