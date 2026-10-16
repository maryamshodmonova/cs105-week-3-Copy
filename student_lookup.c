
#include <stdio.h>

typedef struct
{
    int id;
    char name[50];
    char major[50];
} Student;

int main(void)
{
    Student students[] = {
        {101, "Amina", "Computer Science"},
        {102, "Farid", "Mathematics"},
        {103, "Madina", "Economics"},
        {104, "Rustam", "Design"},
        {105, "Zebo", "Computer Science"}
    };

    // Calculate the number of students.
    int length = sizeof(students) / sizeof(students[0]);

    // Read the ID to search for.
    int search_id;
    printf("Student ID: ");
    scanf("%d", &search_id);

    // Search for a matching student.
    int found = 0;

    for (int i = 0; i < length; i++)
    {
        if (students[i].id == search_id)
        {
            printf("Name: %s\n", students[i].name);
            printf("Major: %s\n", students[i].major);
            found = 1;
            break;
        }
    }

    // Print the result.
    if (found == 0)
    {
        printf("Student not found.\n");
    }
}
