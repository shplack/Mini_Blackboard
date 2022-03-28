#include "Course.h"
#include "Person/Student/Student.h"
#include "Person/Teacher/Teacher.h"
#include <string.h>

List CourseDB = { .head = NULL, .size = 0 };

void enrollStudent(Course * const course, Student * const student) {
    insert(&course->students, student);
    insert(&student->courses, course);
}

void assignTeacher(Course * const course, Teacher * const teacher) {
    insert(&course->teachers, teacher);
    insert(&teacher->courses, course);
}

Course *newCourse(
    char const * const     name,
    char const * const     code,
    unsigned char const    points,
    unsigned char const    period,
    unsigned short         year
) {
    if (period > 4)
        return NULL;

    Course * course = malloc(sizeof(Course));
    *course = (Course) {
            .points = points,
            .period = period,
            .year = year,
            .students = { .head = NULL, .size = 0 },
            .teachers = { .head = NULL, .size = 0 }
    };

    strncpy(course->name, name, COURSE_NAME_LEN);
    strncpy(course->code, code, COURSE_CODE_LEN);

    return course;
}

bool addCourse(Course * const course) {
    if (isEmpty(&course->teachers))
        return false;

    if (isEmpty(&course->students))
        return false;

    if (course->year < 2022)
        return false;

    insert(&CourseDB, course);
    return true;
}

char * courseInfoStr(Course const course) {

}