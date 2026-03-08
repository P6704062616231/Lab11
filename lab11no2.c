#include <stdio.h>
#include <stdlib.h>
#define NO_SCORE 5
#define NO_STUDENTS 10
typedef struct {
    char name[16];
    char surname[20];
    int score[NO_SCORE];
    float total;
} Student;

void readStudentData(Student *);
void findTotalScore(Student *);
float findAverage(Student);
void findLessThanTen(Student);
void saveToFile(Student students[], int n);
void readFromFile(Student students[], int n);
void printStudentData(Student students[], int n);

int main() {
    Student students[NO_STUDENTS];
    float avg;
    int i;


    for (i = 0; i < NO_STUDENTS; i++) {
        printf("\nEnter data for student %d:\n", i + 1);
        readStudentData(&students[i]);
        findTotalScore(&students[i]);
    }

    saveToFile(students, NO_STUDENTS);

    readFromFile(students, NO_STUDENTS);

    printStudentData(students, NO_STUDENTS);

    for (i = 0; i < NO_STUDENTS; i++) {
        avg = findAverage(students[i]);
        printf("\nAverage score for student %d (%s %s) is %.2f", i + 1, students[i].name, students[i].surname, avg);
    }

    for (i = 0; i < NO_STUDENTS; i++) {
        printf("\n\nChecking scores less than 10 for student %d (%s %s):", i + 1, students[i].name, students[i].surname);
        findLessThanTen(students[i]);
    }

    return 0;
}
void readStudentData(Student *pStd) {
    int i;
    printf("\tName : ");
    scanf("%s", pStd->name);
    printf("\tSurname : ");
    scanf("%s", pStd->surname);
    for (i = 0; i < NO_SCORE; i++) {
        printf("\tScore %d : ", i + 1);
        scanf("%d", &pStd->score[i]);
    }
}
void findTotalScore(Student *pStd) {
    int i;
    pStd->total = 0.0;
    for (i = 0; i < NO_SCORE; i++) {
        pStd->total += pStd->score[i];
    }
}

float findAverage(Student s) {
    return s.total / NO_SCORE;
}
void findLessThanTen(Student s) {
    int i, count = 0;
    for (i = 0; i < NO_SCORE; i++) {
        if (s.score[i] < 10) {
            printf("\n\tTest no.%d - %d", i + 1, s.score[i]);
            count++;
        }
    }
    if (count == 0) {
        printf(" -> None");
    }
}
void saveToFile(Student students[], int n) {
    FILE *file;
    file = fopen("./lab11/no2/std10.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        exit(1);
    }
    fwrite(students, sizeof(Student), n, file);
    fclose(file);
    printf("\nData saved to file successfully!\n");
}
void readFromFile(Student students[], int n) {
    FILE *file;
    file = fopen("./lab11/no2/std10.dat", "rb");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        exit(1);
    }
    fread(students, sizeof(Student), n, file);
    fclose(file);
    printf("\nData read from file successfully!\n");
}
void printStudentData(Student students[], int n) {
    int i, j;
    printf("\n\nStudent Data:\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d: %s %s\n", i + 1, students[i].name, students[i].surname);
        printf("Scores: ");
        for (j = 0; j < NO_SCORE; j++) {
            printf("%d ", students[i].score[j]);
        }
        printf("\nTotal Score: %.2f", students[i].total);
    }
}
