#include <stdio.h>

void main() {
    float x;
    float y;
    printf("Введите x: ");
    scanf("%f", &x);
    printf("Введите y: ");
    scanf("%f", &y);
    if (y>=-x &&  (x<=1 && x>=-1) && (y>=-1 && y<=1)) {
        printf("YES\n");
    } else {
        printf("NO\n");
}
}
