#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char name[50];
    int score;
} Student;

int main() {
    Student std[10];
    FILE *fp;
    int i, sum = 0;
    float avg;
    int minIndex = 0;

    for(i = 0; i < 10; i++) {
        printf("Student %d name: ", i + 1);
        scanf("%s", std[i].name);
        printf("Student %d score: ", i + 1);
        scanf("%d", &std[i].score);
    }
    fp = fopen("./lab11/no2/std10.dat", "wb");
    if(fp == NULL) {
        printf("Cannot open file\n");
        return 1;
    }
    fwrite(std, sizeof(Student), 10, fp);
    fclose(fp);

    printf("\nSave file complete already\n");

    fp = fopen("./lab11/no2/std10.dat", "rb");
    if(fp == NULL) {
        printf("Cannot open file\n");
        return 1;
    }
    fread(std, sizeof(Student), 10, fp);
    fclose(fp);

    for(i = 0; i < 10; i++) {
        sum += std[i].score;
    }
    avg = (float)sum / 10;

    for(i = 1; i < 10; i++) {
        if(std[i].score < std[minIndex].score) {
            minIndex = i;
        }
    }
    printf("\n--- Student Records ---\n");
    for(i = 0; i < 10; i++) {
        printf("Name: %s, Score: %d\n", std[i].name, std[i].score);
    }
    printf("\nAverage score = %.2f\n", avg);

    printf("Student who got less than 10 score:\n");
    for(i = 0; i < 10; i++) {
        if(std[i].score < 10) {
            printf("Name: %s, Score: %d\n", std[i].name, std[i].score);
        }
    }
    printf("\nLowest score student: %s, Score: %d\n",
           std[minIndex].name, std[minIndex].score);

    return 0;
}
