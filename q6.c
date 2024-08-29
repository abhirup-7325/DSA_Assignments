/*
6. Store the names of your classmates according to roll numbers in a text file one name per line. Write
a program to find out from the file, the smallest and largest names and their lengths in number of
characters. Write a function to sort the names alphabetically and store in a second file.
*/

// NOT COMPLETE

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>


int getData() {
    FILE *fp = fopen("students.txt", "w");

    printf("Enter number of students: ");
    int n;
    scanf("%d", &n);

    char name[101];
    for (int i = 1; i <= n; i++) {
        printf("Enter name of student with roll number %d: ", i);
        scanf("%100s", name);

        fprintf(fp, "%d %s\n", i, name);
    }
}


void findExtrema(int n) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Couldn't open file.\n");
        return;
    }

    int roll;
    char name[101];

    char smallestName[101], largestName[101];
    smallestName[0] = '\0';
    largestName[0] = '\0';

    int *lengths = (int *) malloc(n * sizeof(int));
    if (lengths == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fp);
        return;
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d %s", &roll, name);
        printf("%d\n", roll);

        if (strlen(smallestName) == 0 || strcmp(smallestName, name) > 0) {
            strcpy(smallestName, name);
        }

        if (strlen(largestName) == 0 || strcmp(largestName, name) < 0) {
            strcpy(largestName, name);
        }

        lengths[i] = strlen(name);
    }

    fclose(fp);

    printf("Smallest name: %s\n", smallestName);
    printf("Largest name: %s\n", largestName);
    printf("Lengths of names: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", lengths[i]);
    }
    printf("\n");

    free(lengths);
}

int main() {
    int n = getData();
    printf("%d", n);

    findExtrema(n);

    return 0;
}