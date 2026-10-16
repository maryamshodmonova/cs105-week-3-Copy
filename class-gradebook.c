
#include <stdio.h>

typedef struct
{
    char name[50];
    int score;
} Student;

int main(void)
{
    Student students[10];
    int student_count;

    // Read a valid number of students.
    do
    {
        printf("Number of students: ");
        scanf("%d", &student_count);
    }
    while (student_count < 3 || student_count > 10);

    // Read every student's name and score.
    for (int i = 0; i < student_count; i++)
    {
        printf("Student %d name: ", i + 1);
        scanf("%49s", students[i].name);

        do
        {
            printf("%s's score: ", students[i].name);
            scanf("%d", &students[i].score);
        }
        while (students[i].score < 0 || students[i].score > 100);
    }

    // Calculate the average and find the highest-scoring student.
    int total = 0;
    int top_index = 0;

    for (int i = 0; i < student_count; i++)
    {
        total += students[i].score;

        if (students[i].score > students[top_index].score)
        {
            top_index = i;
        }
    }

    double average = (double) total / student_count;

    printf("\nAverage: %.2f\n", average);
    printf("Top student: %s (%d)\n",
           students[top_index].name,
           students[top_index].score);

    // Sort the Student records by score, highest to lowest.
    for (int i = 0; i < student_count - 1; i++)
    {
        int largest = i;

        for (int j = i + 1; j < student_count; j++)
        {
            if (students[j].score > students[largest].score)
            {
                largest = j;
            }
        }

        Student temporary = students[i];
        students[i] = students[largest];
        students[largest] = temporary;
    }

    // Print the results and ranking.
    printf("\nRanking:\n");

    for (int i = 0; i < student_count; i++)
    {
        printf("%d. %s - %d\n",
               i + 1,
               students[i].name,
               students[i].score);
    }

    return 0;
}