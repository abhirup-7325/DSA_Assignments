/* 
2. Write a program to generate the nth Fibonacci number iteratively and recursively. Check when there
is overflow in the result and change the data types for accommodating higher values of inputs. Plot
the Fibonacci number vs n graph.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>


void getIO(int *);
void fibIterative(int);
void fibRecursive(int);
void drawGraph();


int main() {
    int n;
    getIO(&n);

    fibIterative(n);
    fibRecursive(n);

    drawGraph();
}


void fibIterative(int n) {
    /*
    Implements the dp approach with space optimisations
    */

    char text[100] = "The required number is: ";
    if (n < 1) {
        printf("Invalid input! Aborting...");
        exit(0);
    }

    if (n == 1 || n == 2) {
        printf("%s %d\n", text, 1);
        return;
    }

    int intPrev = 1, intPrev2 = 1, intCur;
    long long longPrev, longPrev2, longCur;

    bool isLong = false;

    for (int i = 3; i <= n; i++) {
        if (isLong) {
            if (LONG_MAX - longPrev < longPrev2) {
                printf("Too Large of a number! Aborting...\n");
                exit(0);
            } else {
                longCur = longPrev + longPrev2;
                longPrev2 = longPrev;
                longPrev = longCur;
            }
        } else {
            if (INT_MAX - intPrev < intPrev2) {
                isLong = true;

                longCur = (long long)intPrev + (long long)intPrev2;
                longPrev = longCur;
                longPrev2 = intPrev;
            } else {
                intCur = intPrev + intPrev2;
                intPrev2 = intPrev;
                intPrev = intCur;
            }
        }
    }


    if (isLong) {
        printf("%s %lld\n", text, longCur);
    } else {
        printf("%s %d\n", text, intCur);
    }
}


void fibRecursive(int n) {

} 


void drawGraph() {

}


void getIO(int *n) {
    printf("Enter a number: ");
    scanf("%d", n);
}