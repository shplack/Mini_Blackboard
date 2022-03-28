#include "Student.h"
#include <string.h>

#define MAX_INFO_SIZE 4096

char *studentInfo(Student const student) {
    char *info = malloc(MAX_INFO_SIZE);
    char * personInfo = personInfoStr(&student.person);
    strcpy(info, personInfo);
    free(personInfo);

    unsigned long index = strlen(info);

    char id_intro[] = "Student ID: ";
    strcpy(info + index, id_intro);
    index += strlen(id_intro);

    strcpy(info + index, student.id);
    index += strlen(student.id);

    strcpy(info + index, "\n");
    index++;

    char year_intro[] = "Class year: ";
    strcpy(info + index, year_intro);
    index += strlen(year_intro);

    char year[6] = "";
    itoa(student.class_year, year, 10);
    strcpy(info + index, year);
    index += strlen(year);

    char courses_intro[] = "Courses:\n";
    strcpy(info + index, courses_intro);

    int i = 0;
    unsigned long strSize = 0;

    char * courseInfo[student.courses.size];
    ListElement *tmp = student.courses.head;

    while (tmp) {
        courseInfo[i] = courseInfoStr(*(Course*)tmp->data);
        strSize += strlen(courseInfo[i]) + 2;

        i++;
        tmp = tmp->next;
    }

    char *coursesInfo = malloc(strSize);
    for (i = 0, index = 0; i < sizeof(courseInfo); i++) {
        strcpy(coursesInfo + index, "\t");
        index++;

        strcpy(coursesInfo + index, courseInfo[i]);
        index += strlen(courseInfo[i]);

        strcpy(coursesInfo + index, "\n");
        index++;
    }

    char *info_done = malloc(strlen(info) + strlen(coursesInfo));
    strcpy(info_done, info);
    strcpy(info_done + strlen(info), coursesInfo);

    free(info);
    free(coursesInfo);

    return info_done;
}