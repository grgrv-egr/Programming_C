#include <stdio.h>

int main() {

    int a;
    int k;
    int c;
    printf("Введите число a: ");
    scanf("%d", &a);
    printf("Введите число k для сдвига влево: ");
    scanf("%d", &k);
    for (int i = sizeof(a)*2 - 1; i >= 0 ; i--) {
        printf("%d", (a >> i) & 1);
    }
    printf("\n");
    c=a<<k;
    printf("%d\n", c);
    for (int i = sizeof(c)*2 - 1; i >= 0 ; i--) {
        printf("%d", (c >> i) & 1);
    }

}
