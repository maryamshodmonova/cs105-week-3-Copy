
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
        {108, "Kamol", "Physics"},
        {103, "Madina", "Economics"},
        {105, "Zebo", "Computer Science"},
        {101, "Amina", "Computer Science"},
        {107, "Nilufar", "Biology"},
        {102, "Farid", "Mathematics"},
        {106, "Rustam", "Design"},
        {104, "Daler", "Engineering"}
    };

    int student_count = sizeof students / sizeof students[0];

    // Sort the complete records by ID using selection sort.
    for (int i = 0; i < student_count - 1; i++)
    {
        int smallest = i;

        for (int j = i + 1; j < student_count; j++)
        {
            if (students[j].id < students[smallest].id)
            {
                smallest = j;
            }
        }

        Student temporary = students[i];
        students[i] = students[smallest];
        students[smallest] = temporary;
    }

    // Print the sorted directory.
    printf("Sorted directory:\n");

    for (int i = 0; i < student_count; i++)
    {
        printf("%d - %s\n", students[i].id, students[i].name);
    }

    printf("\n");

    // Read the target ID.
    int target_id;
    printf("Student ID: ");
    scanf("%d", &target_id);

    // Search for the ID using binary search.
    int low = 0;
    int high = student_count - 1;
    int found_index = -1;
    int comparisons = 0;

    while (low <= high)
    {
        int middle = low + (high - low) / 2;
        comparisons++;

        if (students[middle].id == target_id)
        {
            found_index = middle;
            break;
        }
        else if (target_id < students[middle].id)
        {
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }

    if (found_index != -1)
    {
        printf("Name: %s\n", students[found_index].name);
        printf("Major: %s\n", students[found_index].major);
    }
    else
    {
        printf("Student not found.\n");
    }

    printf("Comparisons: %d\n", comparisons);

    return 0;
}
