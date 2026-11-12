
#include <stdio.h>
#include <string.h>

void readMarks(int *m1, int *m2, int *m3);

void calculateStats(int m1, int m2, int m3,
                    int *total, double *average,
                    int *highest, int *lowest);

void swapMarks(int *a, int *b);

void addGraceMarks(int *mark, int grace);

void findGrade(double avg, char *grade, char *remarks);

void incrementByValue(int x);
void incrementByReference(int *x);

int main()
{
    int m1, m2, m3;
    int total, highest, lowest;
    double average;
    int grace;
    char grade;
    char remarks[30];

    for (int i = 1; i <= 5; i++)
    {
        printf("\n========== STUDENT %d ==========\n", i);

        
        readMarks(&m1, &m2, &m3);

        
        printf("Enter grace marks (0-5): ");
        scanf("%d", &grace);

        
        addGraceMarks(&m1, grace);
        addGraceMarks(&m2, grace);
        addGraceMarks(&m3, grace);

        
        calculateStats(m1, m2, m3,
                       &total, &average, &highest, &lowest);

        
        if (m1 < m2)
            swapMarks(&m1, &m2);

        if (m1 < m3)
            swapMarks(&m1, &m3);

        if (m2 < m3)
            swapMarks(&m2, &m3);

        
        findGrade(average, &grade, remarks);

        
        printf("\nSorted marks: %d %d %d\n", m1, m2, m3);
        printf("Total: %d\n", total);
        printf("Average: %.2lf\n", average);
        printf("Highest: %d\n", highest);
        printf("Lowest: %d\n", lowest);
        printf("Grade: %c\n", grade);
        printf("Remarks: %s\n", remarks);
    }

    
    int number = 10;

    printf("\n========== POINTER DEMO ==========\n");

    printf("Original number: %d\n", number);

    incrementByValue(number);
    printf("After incrementByValue: %d\n", number);

    incrementByReference(&number);
    printf("After incrementByReference: %d\n", number);

    return 0;
}


void readMarks(int *m1, int *m2, int *m3)
{
    printf("Enter marks for 3 subjects: ");

    scanf("%d %d %d", m1, m2, m3);
}


void calculateStats(int m1, int m2, int m3,
                    int *total, double *average,
                    int *highest, int *lowest)
{
    *total = m1 + m2 + m3;

    *average = *total / 3.0;

    *highest = m1;
    if (m2 > *highest)
        *highest = m2;
    if (m3 > *highest)
        *highest = m3;

    *lowest = m1;
    if (m2 < *lowest)
        *lowest = m2;
    if (m3 < *lowest)
        *lowest = m3;
}


void swapMarks(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void addGraceMarks(int *mark, int grace)
{
    if (*mark >= 35 && *mark <= 39)
    {
        *mark = *mark + grace;

        if (*mark > 40)
            *mark = 40;
    }
}


void findGrade(double avg, char *grade, char *remarks)
{
    if (avg >= 80)
    {
        *grade = 'A';
        strcpy(remarks, "Excellent");
    }
    else if (avg >= 60)
    {
        *grade = 'B';
        strcpy(remarks, "Good");
    }
    else
    {
        *grade = 'C';
        strcpy(remarks, "Needs Improvement");
    }
}


void incrementByValue(int x)
{
    x++;
}


void incrementByReference(int *x)
{
    (*x)++;
}


