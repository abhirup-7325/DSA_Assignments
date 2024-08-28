#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define BINARY_SEARCH(TYPE, BS_FN, COMPARE)                                   \
int BS_FN(TYPE *a, int n, TYPE target) {                                      \
    int low = 0, high = n - 1, mid;                                           \
                                                                              \
    while (low <= high) {                                                     \
        mid = low + (high - low) / 2;                                         \
                                                                              \
        if (COMPARE(a[mid], target)) {                                        \
            return mid;                                                       \
        } else if (COMPARE(a[mid], target)) {                                 \
            high = mid - 1;                                                   \
        } else {                                                              \
            low = mid + 1;                                                    \
        }                                                                     \
    }                                                                         \
                                                                              \
    return -1;                                                                \
}


#define GET_IO(TYPE, SPECIFIER, FN)                                            \
void FN(int *n, TYPE **a, TYPE *target) {                                      \
    printf("Enter number of sorted elements: ");                               \
    scanf("%d", n);                                                            \
    printf("Enter target: ");                                                  \
    scanf(SPECIFIER, target);                                                  \
                                                                               \
    (*a) = (TYPE *) malloc((*n) * sizeof(TYPE));                               \
    if (*a == NULL) {                                                          \
        printf("Memory allocation failed.\n");                                 \
        exit(1);                                                               \
    }                                                                          \
                                                                               \
    for (int i = 0; i < *n; i++) {                                             \
        printf("Enter element %d: ", i + 1);                                   \
        scanf(SPECIFIER, &(*a)[i]);                                            \
    }                                                                          \
}


bool cmpInt(int, int);
bool cmpFloat(float, float);
bool cmpWords(char *, char *);
void getIO_Words(int *, char ***, char **);

GET_IO(int, "%d", getIO_int)
GET_IO(float, "%f", getIO_float);

BINARY_SEARCH(int, binarySearchInt, cmpInt);
BINARY_SEARCH(float, binarySearchFloat, cmpFloat);
BINARY_SEARCH(char*, binarySearchWords, cmpWords);


int main() {
    printf("Enter 1 for int, 2 for float, 3 for words: ");
    int response;
    scanf("%d", &response);

    int n;
    int ans;
    switch (response) {
        case 1:
            int targetInt;
            int *aInt;
            getIO_int(&n, &aInt, &targetInt);

            ans = binarySearchInt(aInt, n, targetInt);

            free(aInt);
            break;

        case 2:
            float targetFloat;
            float *aFloat;

            getIO_float(&n, &aFloat, &targetFloat);

            ans = binarySearchFloat(aFloat, n, targetFloat);
            free(aFloat);
            break;

        case 3:
            char *targetWords = (char *) malloc(101 * sizeof(char));
            char **aWords;

            getIO_Words(&n, &aWords, &targetWords);

            ans = binarySearchWords(aWords, n, targetWords);

            free(targetWords);
            for (int i = 0; i < n; i++) {
                free(aWords[i]);
            }
            free(aWords);
            break;
    }

    if (ans == -1) {
        printf("Answer not found!\n");
    } else {
        printf("Answer = %d\n", ans);
    }

    return 0;
}


void getIO_Words(int *n, char ***a, char **target) {
    printf("Enter number of sorted elements: ");
    scanf("%d", n); 
    printf("Enter target: ");
    scanf("%99s", *target);
                                                                             
    (*a) = (char **) malloc((*n) * sizeof(char *));                             
    if (*a == NULL) {                                                      
        printf("Memory allocation failed.\n");                               
        exit(1);                                                           
    }

    for (int i = 0; i < *n; i++) {
        (*a)[i] = (char *) malloc(101 * sizeof(char));
    } 
                                                                            
    for (int i = 0; i < *n; i++) {                                          
        printf("Enter element %d: ", i + 1);                                
        scanf("%99s", (*a)[i]);                                  
    }
}


bool cmpInt(int a, int b) {
    if (a == b) return true;
    return false;
}


bool cmpFloat(float a, float b) {
    if (((a - b > 0) ? (a - b) : (b - a)) < 0.00001) return true;
    return false;
}


bool cmpWords(char *a, char *b) {
    if (strcmp(a, b) == 0) return true;
    return false;
}
