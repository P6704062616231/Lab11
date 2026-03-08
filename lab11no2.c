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

    // รับข้อมูลนักศึกษา 10 คน
    for(i = 0; i < 10; i++) {
        printf("Student %d name: ", i + 1);
        scanf("%s", std[i].name);
        printf("Student %d score: ", i + 1);
        scanf("%d", &std[i].score);
    }

    // เปิดไฟล์เพื่อเขียนข้อมูล
    fp = fopen("./lab11/no2/std10.dat", "wb");
    if(fp == NULL) {
        printf("Cannot open file\n");
        return 1;
    }

    fwrite(std, sizeof(Student), 10, fp);
    fclose(fp);

    printf("\nSave file complete already\n");

    // เปิดไฟล์เพื่ออ่านข้อมูลกลับมา
    fp = fopen("./lab11/no2/std10.dat", "rb");
    if(fp == NULL) {
        printf("Cannot open file\n");
        return 1;
    }

    fread(std, sizeof(Student), 10, fp);
    fclose(fp);

    // หาผลรวม
    for(i = 0; i < 10; i++) {
        sum += std[i].score;
    }

    avg = (float)sum / 10;

    // หา index ของคนน้อยสุด
    for(i = 1; i < 10; i++) {
        if(std[i].score < std[minIndex].score) {
            minIndex = i;
        }
    }

    // แสดงผลแต่ละคน
    printf("\n--- Student Records ---\n");
    for(i = 0; i < 10; i++) {
        printf("Name: %s, Score: %d\n", std[i].name, std[i].score);
    }

    // ค่าเฉลี่ย
    printf("\nAverage score = %.2f\n", avg);

    // คะแนนน้อยกว่า 10
    printf("Student who got less than 10 score:\n");
    for(i = 0; i < 10; i++) {
        if(std[i].score < 10) {
            printf("Name: %s, Score: %d\n", std[i].name, std[i].score);
        }
    }

    // คนน้อยสุด
    printf("\nLowest score student: %s, Score: %d\n",
           std[minIndex].name, std[minIndex].score);

    return 0;
}
