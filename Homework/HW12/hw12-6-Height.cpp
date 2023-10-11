/*
    ผู้ใช้กรอกชื่อและความสูงของคนในโรงเรียนในห้อง A และห้อง B และเรียงลำดับของคนที่ตัวเล็กที่สุดไปยังตัวใหญ่ที่สุดในแต่ละห้อง และเรียงลำดับของคนทั้งโรงเรียนจากตัวที่ใหญ่ที่สุดมายังตัวเล็กที่สุด

    Test case:
        Room A
        Name : 
            John
        Height (cm) : 
            176.6
        Name : 
            Job
        Height (cm) : 
            177.5
        Name : 
            Aim
        Height (cm) : 
            149.8
        Name : 
            Mon
        Height (cm) : 
            158.9
        Name : 
            Ammy
        Height (cm) : 
            151.0
        Name : 
            A
        Height (cm) : 
            169.7
        Name : 
            -1

        Room B
        Name : 
            Komsam
        Height (cm) : 
            176.1
        Name : 
            Samart
        Height (cm) : 
            165.4
        Name : 
            Sunu
        Height (cm) : 
            168.1
        Name : 
            -1

    Output:
        Room A -> Aim Ammy Mon A John Job
        Room B -> Samart Sunu Komsam
        School -> Job John Komsam A Sunu Samart Mon Ammy Aim
*/
#include <stdio.h>
#include <string.h>

struct Student {
    char name[100];
    float height;
};

void inputStudents(struct Student students[], int* count) {
    while (1) {
        printf("Name : ");
        scanf("%s", students[*count].name);
        if (strcmp(students[*count].name, "-1") == 0) break;
        printf("Height (cm) : ");
        scanf("%f", &students[*count].height);
        (*count)++;
    }
}

void sortStudents(struct Student students[], int count) {
    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
            if (students[j].height > students[j + 1].height) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
}

int main() {
    struct Student studentsA[100], studentsB[100], schoolStudents[200];
    int countA = 0, countB = 0, totalStudents = 0;
    
    printf("Room A\n"); inputStudents(studentsA, &countA);
    printf("\nRoom B\n"); inputStudents(studentsB, &countB);

    sortStudents(studentsA, countA);
    sortStudents(studentsB, countB);

    printf("Room A -> "); for (int i = 0; i < countA; i++) printf("%s ", studentsA[i].name);
    printf("\nRoom B -> "); for (int i = 0; i < countB; i++) printf("%s ", studentsB[i].name);
    
    for (int i = 0; i < countA; i++) schoolStudents[totalStudents++] = studentsA[i];
    for (int i = 0; i < countB; i++) schoolStudents[totalStudents++] = studentsB[i];
    sortStudents(schoolStudents, totalStudents);

    printf("\nSchool -> "); for (int i = 0; i < totalStudents; i++) printf("%s ", schoolStudents[i].name);
    
    return 0;
}
