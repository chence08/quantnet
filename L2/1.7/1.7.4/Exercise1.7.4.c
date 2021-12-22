/* Author: YiJia Chen */
#include <stdio.h>

/* Print the day of a given day-number.
The day-name should be "hard-coded" into the program using an array of strings. */
char names[7][9] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

void DayName(int day)
{
    printf("Day %d is a %s.\n", day, names[day-1]);
}

int main()
{
    int day;
    printf("Enter day number: ");
    scanf("%d", &day);
    DayName(day);
}