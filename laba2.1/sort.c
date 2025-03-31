#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10

struct Student {
    char name[64];
    int math;
    int phy;
    int inf;
    int total;
};

struct Student addStudent(const char *name, int math, int phy, int inf) {
    struct Student newStudent;
    strncpy(newStudent.name, name, sizeof(newStudent.name) - 1);
    newStudent.math = math;
    newStudent.phy = phy;
    newStudent.inf = inf;
    newStudent.total = math + phy + inf;
    return newStudent;
}

void printStudentInfo(struct Student student) {
    printf("Имя: %s, Математика: %d, Физика: %d, Информатика: %d, Общий балл: %d\n",
           student.name, student.math, student.phy, student.inf, student.total);
}

void selectSort(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].total > arr[k].total) {
                k = j;
            }
        }
        if (k != i) {
            struct Student temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
}

void radixSort(struct Student arr[], int n) {
    int max = arr[0].total;

    for (int i = 1; i < n; i++) {
        if (arr[i].total > max) {
            max = arr[i].total;
        }
    }

    for (int razryad = 1; max / razryad > 0; razryad *= 10) {
        struct Student output[n];
        int count[10] = {0}; 

        for (int i = 0; i < n; i++) {
            count[(arr[i].total / razryad) % 10]++;
        }

        for (int i = 8; i >= 0; i--) { 
            count[i] += count[i + 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i].total / razryad) % 10] - 1] = arr[i];
            count[(arr[i].total / razryad) % 10]--;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

void quickSort(struct Student arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high].total;
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j].total > pivot) {
                i++;
                struct Student temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        struct Student temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void generateRandomStudents(struct Student students[], int n) {
    const char *names[] = {"Иван", "Петр", "Сергей", "Анастасия", "Мария", "Ольга", "Дмитрий", "Елена", "Алексей", "Наталья"};
    for (int i = 0; i < n; i++) {
        snprintf(students[i].name, sizeof(students[i].name), "%s", names[rand() % 10]);
        students[i].math = rand() % 101;
        students[i].phy = rand() % 101;
        students[i].inf = rand() % 101;
        students[i].total = students[i].math + students[i].phy + students[i].inf;
    }
}

void printCPUInfo() {
    system("cat /proc/cpuinfo | grep 'model name' | uniq");
}

int main() {
    srand(time(NULL));
    struct Student students[N];

    generateRandomStudents(students, N);

    printf("Список студентов до сортировки:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    clock_t start = clock();
    selectSort(students, N);
    clock_t end = clock();
    double timeSelectSort = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nСписок студентов после сортировки SelectSort():\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    start = clock();
    radixSort(students, N);
    end = clock();
    double timeRadixSort = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nСписок студентов после сортировки RadixSort():\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    start = clock();
    quickSort(students, 0, N - 1);
    end = clock();
    double timeQuickSort = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nСписок студентов после сортировки QuickSort():\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    printf("\nВремя работы сортировки SelectSort(): %.6f секунд\n", timeSelectSort);
    printf("\nВремя работы сортировки RadixSort(): %.6f секунд\n", timeRadixSort);
    printf("\nВремя работы сортировки QuickSort(): %.6f секунд\n", timeQuickSort);

    printf("\nИнформация о процессоре:\n");
    printCPUInfo();

    return 0;
}

