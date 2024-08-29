/*
8. Convert your Name and Surname into large integers by juxtaposing integer ASCII codes for alphabet.
Print the corresponding converted integer. Cut the large integers into two halves and add the two
halves. Compute the remainder after dividing the result by the prime numbers P in problem 7.
*/

// NOT COMPLETE


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>


void sieve(int *isPrime, int n) {
    for (int i = 0; i <= n; i++) {
        isPrime[i] = 1;
    }

    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i*i <= n; i++) {
        if (isPrime[i] == 0) {
            continue;
        }

        for (int j = i*i; j <= n; j += i) {
            isPrime[j] = 0;
        }
    }
}


int main() {
    int *isPrime = (int *) malloc(10000 * sizeof(int));
    sieve(isPrime, 9999);

    char name[101], surname[101];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your surname: ");
    scanf("%s", surname);

    char fullName[201] = "";
    strcat(fullName, name);
    strcat(fullName, surname);

    
}