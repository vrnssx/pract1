#include <stdio.h>
#include <math.h>

#define SIZE 10

int main() {
    double array[SIZE];
    double sum = 0.0, average;
    int i, closest_index;
    double min_diff;
    int first_negative_index = -1, second_positive_index = -1;
    double sum_between = 0.0;

    printf("Введіть %d дійсних чисел:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%lf", &array[i]);
        sum += array[i];
    }

    average = sum / SIZE;

    closest_index = 0;
    min_diff = fabs(array[0] - average);
    for (i = 1; i < SIZE; i++) {
        double diff = fabs(array[i] - average);
        if (diff < min_diff) {
            min_diff = diff;
            closest_index = i;
        }
    }

    for (i = 0; i < SIZE; i++) {
        if (array[i] < 0 && first_negative_index == -1) {
            first_negative_index = i;
        }
        if (array[i] > 0 && first_negative_index != -1 && second_positive_index == -1 && i > first_negative_index) {
            second_positive_index = i;
            break;
        }
    }

    if (first_negative_index != -1 && second_positive_index != -1 && second_positive_index > first_negative_index) {
        for (i = first_negative_index + 1; i < second_positive_index; i++) {
            sum_between += array[i];
        }
    }

    printf("Номер елемента, найближчого до середнього арифметичного: %d\n", closest_index);
    if (first_negative_index != -1 && second_positive_index != -1 && second_positive_index > first_negative_index) {
        printf("Сума елементів між першим від'ємним та другим додатним: %.2lf\n", sum_between);
    } else {
        printf("Не вдалося знайти перший від'ємний та другий додатний елементи, або вони розташовані неправильно.\n");
    }

    return 0;
}