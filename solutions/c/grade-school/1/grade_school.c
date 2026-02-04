#include "grade_school.h"

void init_roster(roster_t *roster) {
    roster->count = 0;
}

bool add_student(roster_t *roster, const char *name, uint8_t grade) {
    if (roster->count >= MAX_STUDENTS) {
        return false;
    }

    size_t pos = roster->count;
    for (size_t i = 0; i < roster->count; i++) {
        if (strcmp(name, roster->students[i].name) == 0) {
            return false;
        }
        if (grade < roster->students[i].grade || 
            (grade == roster->students[i].grade &&
             strcmp(name, roster->students[i].name) < 0)) {
                pos = i;
                break;
        }
    }

    for (size_t i = roster->count; i > pos; i--) {
        roster->students[i] = roster->students[i - 1];
    }

    roster->students[pos].grade = grade;
    strcpy(roster->students[pos].name, name);
    roster->count += 1;
    return true;
}

roster_t get_grade(roster_t *roster, uint8_t grade) {
    roster_t grade_x = {0};
    for (size_t i = 0; i < roster->count; i++) {
        if (roster->students[i].grade == grade) {
            grade_x.students[grade_x.count].grade = grade;
            strcpy(grade_x.students[grade_x.count].name,  roster->students[i].name);
            grade_x.count += 1;
        }
    }
    return grade_x;
}