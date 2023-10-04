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
#include <stdlib.h>

#define MAX_STUDENTS 100

// โครงสร้างข้อมูลสำหรับเก็บชื่อและความสูง
struct Student {
    char name[100];
    float height;
};

// ฟังก์ชันเปรียบเทียบสำหรับการเรียงลำดับคนตามความสูง
int compare(const void *a, const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;
    return (studentA->height > studentB->height) - (studentA->height < studentB->height);
}

int main() {
    struct Student roomA[MAX_STUDENTS], roomB[MAX_STUDENTS];
    char name[100];
    int roomASize = 0, roomBSize = 0;

    // รับข้อมูลสำหรับห้อง A
    printf("Room A\n");
    while (1) {
        printf("Name : ");
        scanf("%s", name);
        if (strcmp(name, "-1") == 0) break;
        strcpy(roomA[roomASize].name, name);
        printf("Height (cm) : ");
        scanf("%f", &roomA[roomASize].height);
        roomASize++;
    }

    // รับข้อมูลสำหรับห้อง B
    printf("\nRoom B\n");
    while (1) {
        printf("Name : ");
        scanf("%s", name);
        if (strcmp(name, "-1") == 0) break;
        strcpy(roomB[roomBSize].name, name);
        printf("Height (cm) : ");
        scanf("%f", &roomB[roomBSize].height);
        roomBSize++;
    }

    // เรียงลำดับคนในห้อง A และห้อง B ตามความสูง
    qsort(roomA, roomASize, sizeof(struct Student), compare);
    qsort(roomB, roomBSize, sizeof(struct Student), compare);

    // แสดงผลลัพธ์สำหรับแต่ละห้อง
    printf("\nRoom A -> ");
    for (int i = 0; i < roomASize; i++) {
        printf("%s ", roomA[i].name);
    }

    printf("\nRoom B -> ");
    for (int i = 0; i < roomBSize; i++) {
        printf("%s ", roomB[i].name);
    }

    // รวมข้อมูลจากทั้งห้อง A และห้อง B เพื่อเรียงลำดับทั้งโรงเรียน
    struct Student school[MAX_STUDENTS];
    int schoolSize = 0;

    for (int i = 0; i < roomASize; i++) {
        strcpy(school[schoolSize].name, roomA[i].name);
        school[schoolSize].height = roomA[i].height;
        schoolSize++;
    }

    for (int i = 0; i < roomBSize; i++) {
        strcpy(school[schoolSize].name, roomB[i].name);
        school[schoolSize].height = roomB[i].height;
        schoolSize++;
    }

    // เรียงลำดับคนในโรงเรียนตามความสูง
    qsort(school, schoolSize, sizeof(struct Student), compare);

    // แสดงผลลัพธ์สำหรับโรงเรียน
    printf("\nSchool -> ");
    for (int i = 0; i < schoolSize; i++) {
        printf("%s ", school[i].name);
    }

    return 0;
}
