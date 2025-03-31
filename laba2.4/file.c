#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Используй: %s result.txt\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "w");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return 1;
    }

    for (double x = 2.0; x <= 6.0; x += 0.5) {
        double y = sin(x);
        double z = tan(x);

        fprintf(file, "%.1f\t\t%.2f\t%.2e\n", x, y, z);

        if (ferror(file)) {
            perror("Ошибка записи в файл");
            fclose(file);
            return 1;
        }
    }

    if (fclose(file) != 0) {
        perror("Ошибка закрытия файла");
        return 1;
    }

    printf("Таблица успешно записана в файл %s\n", argv[1]);
    return 0;
}
