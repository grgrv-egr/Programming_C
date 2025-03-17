#include <stdio.h>

float det2(float a, float b, float c, float d) { // функция вычисл. определителя для 2х2
    return a * d - b * c;
}

float det3(float matrix[3][3]) {  // функция вычисл. определителя для 3х3
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

void s2(float a, float b, float c, float d, float e, float f) { // функция счета системы для 2х2
    float D = det2(a, b, c, d); //определитель
    if (D == 0) {  // если определитель равен 0, то у системы нет единственного решения
        printf("Система не имеет единственного решения.\n");
        return;
    }

    float Dx = det2(e, b, f, d); 
    float Dy = det2(a, e, c, f);

    float x = Dx / D;
    float y = Dy / D;

    printf("Решение: x = %.2f, y = %.2f\n", x, y);
}

void s3(float matrix[3][3], float b[3]) {  // функция счета системы для 3х3
    float D = det3(matrix);  // определитель 
    if (D == 0) {
        printf("Система не имеет единственного решения.\n");
        return;
    }

    float matrixX[3][3], matrixY[3][3], matrixZ[3][3];  //создаем три матрицы

    for (int i = 0; i < 3; i++) {  // проходим по каждой строке
        for (int j = 0; j < 3; j++) {  // проходим по каждом столбце
            matrixX[i][j] = (j == 0) ? b[i] : matrix[i][j];
            matrixY[i][j] = (j == 1) ? b[i] : matrix[i][j];
            matrixZ[i][j] = (j == 2) ? b[i] : matrix[i][j];
        }
    }

    float Dx = det3(matrixX);
    float Dy = det3(matrixY);
    float Dz = det3(matrixZ);

    float x = Dx / D;
    float y = Dy / D;
    float z = Dz / D;

    printf("Решение: x = %.2f, y = %.2f, z = %.2f\n", x, y, z);
}

int main() {
    int N;
    printf("Введите размер системы (2 или 3): ");
    scanf("%d", &N);

    if (N == 2) {
        float a, b, c, d, e, f;
        printf("Введите коэффициенты a, b, c, d, e, f: ");
        scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f);
        s2(a, b, c, d, e, f);
    } else if (N == 3) {
        float matrix[3][3], b[3];
        printf("Введите коэффициенты матрицы (3x3):\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%f", &matrix[i][j]);
            }
        }
        printf("Введите свободные члены (b1, b2, b3):\n");
        for (int i = 0; i < 3; i++) {
            scanf("%f", &b[i]);
        }
        s3(matrix, b);
    } else {
        printf("Неверный размер системы. Должно быть 2 или 3.\n");
    }

    return 0;
}
