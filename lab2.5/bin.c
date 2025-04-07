#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    char group[10];
    int marks[3];
};

void addStudents() {
    FILE *file = fopen("Wedomost.dat", "ab");
    if (!file) {
        printf("Ошибка создания файла\n");
        return;
    }

    int count;
    printf("Сколько студентов добавить? ");
    scanf("%d", &count);
    getchar();

    for (int i = 0; i < count; i++) {
        struct Student s;
        
        printf("\nСтудент %d:\n", i+1);
        printf("Фамилия и инициалы: ");
        fgets(s.name, 50, stdin);
        s.name[strlen(s.name)-1] = '\0';
        
        printf("Номер группы: ");
        fgets(s.group, 10, stdin);
        s.group[strlen(s.group)-1] = '\0';
        
        printf("Оценки (3 числа через пробел): ");
        scanf("%d %d %d", &s.marks[0], &s.marks[1], &s.marks[2]);
        getchar();
        
        fwrite(&s, sizeof(struct Student), 1, file);
    }
    
    fclose(file);
    printf("Данные сохранены в файл Wedomost.dat\n");
}

void searchStudents() {
    FILE *file = fopen("Wedomost.dat", "rb");
    if (!file) {
        printf("Файл не найден\n");
        return;
    }

    printf("\nПоиск по:\n");
    printf("1 - Фамилия и инициалы\n");
    printf("2 - Группа\n");
    printf("3 - Оценки\n");
    printf("Выберите вариант: ");
    
    int choice;
    scanf("%d", &choice);
    getchar();

    struct Student s;
    int found = 0;
    
    if (choice == 1) {
        char name[50];
        printf("Введите фамилию и инициалы: ");
        fgets(name, 50, stdin);
        name[strlen(name)-1] = '\0';
        
        while (fread(&s, sizeof(struct Student), 1, file)) {
            if (strcmp(s.name, name) == 0) {
                printf("Найден: %s, %s, %d %d %d\n", 
                      s.name, s.group, s.marks[0], s.marks[1], s.marks[2]);
                found = 1;
            }
        }
    }
    else if (choice == 2) {
        char group[10];
        printf("Введите группу: ");
        fgets(group, 10, stdin);
        group[strlen(group)-1] = '\0';
        
        while (fread(&s, sizeof(struct Student), 1, file)) {
            if (strcmp(s.group, group) == 0) {
                printf("Найден: %s, %s, %d %d %d\n", 
                      s.name, s.group, s.marks[0], s.marks[1], s.marks[2]);
                found = 1;
            }
        }
    }
    else if (choice == 3) {
        int m1, m2, m3;
        printf("Введите 3 оценки через пробел: ");
        scanf("%d %d %d", &m1, &m2, &m3);
        
        while (fread(&s, sizeof(struct Student), 1, file)) {
            if (s.marks[0] == m1 && s.marks[1] == m2 && s.marks[2] == m3) {
                printf("Найден: %s, %s, %d %d %d\n", 
                      s.name, s.group, s.marks[0], s.marks[1], s.marks[2]);
                found = 1;
            }
        }
    }
    else {
        printf("Неверный выбор\n");
    }
    
    if (!found) {
        printf("Совпадений не найдено\n");
    }
    
    fclose(file);
}

int main() {
    int choice;
    
    while (1) {
        printf("\n1 - Добавить студентов\n");
        printf("2 - Поиск\n");
        printf("3 - Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        getchar();
        
        if (choice == 1) addStudents();
        else if (choice == 2) searchStudents();
        else if (choice == 3) break;
        else printf("Неверный выбор\n");
    }
    
    return 0;
}
