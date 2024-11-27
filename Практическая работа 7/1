#include <stdio.h>
#include <string.h>

int main() {
    char a[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

    char *words[1000];
    int k = 0;

    char *word = strtok(a, " ");
    while (word != NULL && k < 1000) {
        words[k++] = word;
        word = strtok(NULL, " ");
    }

    for (int i = k - 1; i >= 0; i--) {
        printf("%s ", words[i]);
    }

}
