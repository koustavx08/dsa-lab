#include <stdio.h>

#define MAX_STUDENTS 100

// Call by value: Calculate percentage
float calculatePercentage(int m1, int m2, int m3) {
    return (m1 + m2 + m3) / 3.0;
}

// Call by reference: Assign grade
void assignGrade(float percentage, char *grade) {
    if (percentage >= 90)
        *grade = 'A';
    else if (percentage >= 75)
        *grade = 'B';
    else if (percentage >= 60)
        *grade = 'C';
    else if (percentage >= 40)
        *grade = 'D';
    else
        *grade = 'F';
}

int main() {
    int n;
    char names[MAX_STUDENTS][50];
    int marks1[MAX_STUDENTS], marks2[MAX_STUDENTS], marks3[MAX_STUDENTS];
    float percentages[MAX_STUDENTS];
    char grades[MAX_STUDENTS];

    printf("Enter number of students: ");
    scanf("%d", &n);
    getchar(); // Clear newline left in buffer

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        fgets(names[i], sizeof(names[i]), stdin);

        printf("Marks in Subject 1: ");
        scanf("%d", &marks1[i]);
        printf("Marks in Subject 2: ");
        scanf("%d", &marks2[i]);
        printf("Marks in Subject 3: ");
        scanf("%d", &marks3[i]);
        getchar(); // Clear newline

        // Call by value
        percentages[i] = calculatePercentage(marks1[i], marks2[i], marks3[i]);

        // Call by reference
        assignGrade(percentages[i], &grades[i]);
    }

    // Display results
    printf("\n----- Student Results -----\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name       : %s", names[i]);
        printf("Marks      : %d, %d, %d\n", marks1[i], marks2[i], marks3[i]);
        printf("Percentage : %.2f%%\n", percentages[i]);
        printf("Grade      : %c\n", grades[i]);
    }

    return 0;
}
