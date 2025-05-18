# Лабораторная работа 7. Знакомство с POSIX потоками
## Цель работы
Изучение базовых возможностей работы с потоками в POSIX (pthread): создание, ожидание, передача параметров, отмена и обработка завершения.

## Задание 1: Создание потока
```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* thread_func(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Дочерний поток: строка %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);
    for (int i = 0; i < 5; i++) {
        printf("Родительский поток: строка %d\n", i);
        sleep(1);
    }
    pthread_join(thread, NULL);
    return 0;
}

```
Результат:
Вывод перемешанных строк от родительского и дочернего потоков.  
  
![Выполнение Задания 1](img/p1.png)
