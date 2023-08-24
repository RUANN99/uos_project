#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkPrime(int n) {
    int i;
    int m = n / 2;
    
    for (i = 2; i <= m; i++) {
        if (n % i == 0) {
            return 0; // Not Prime
        }
    }

    return 1; // Prime
}

int findGCD(int n1, int n2) {
    int i, gcd;

    for(i = 1; i <= n1 && i <= n2; ++i) {
        if(n1 % i == 0 && n2 % i == 0)
            gcd = i;
    }

    return gcd;
}

int powMod(int a, int b, int n) {
    long long x = 1, y = a;

    while (b > 0) {
        if (b % 2 == 1)
            x = (x * y) % n;
        y = (y * y) % n; // Squaring the base
        b /= 2;
    }

    return x % n;
}


int main(int argc, char* argv[]) {
    int p, q;
    int n, phin, cnt;

    int data[5], cipher[5], decrypt[5];
    char name[5];

    while (1) {
        printf("Enter any two prime numbers: ");
        scanf("%d %d", &p, &q);

        if (!(checkPrime(p) && checkPrime(q)))
            printf("Both numbers are not prime. Please enter prime numbers only...\n");
        else if (!checkPrime(p))
            printf("The first prime number you entered is not prime, please try again...\n");
        else if (!checkPrime(q))
            printf("The second prime number you entered is not prime, please try again...\n");
        else
            break;
    }
    
    n = p * q;

    phin = (p - 1) * (q - 1);

    int e = 0;
    for (e = 5; e <= 100; e++) {
        if (findGCD(phin, e) == 1)
            break;
    }
    
    int d = 0;
    for (d = e + 1; d <= 200; d++) {
        if ( ((d * e) % phin) == 1)
            break;
    }

    printf("Value of e: %d\nValue of d: %d\n", e, d);

    printf("Enter your name(less than 5 characters):\n");
    scanf("%s", name);
    
    for(cnt=0;cnt<5;cnt++){
        data[cnt] = name[cnt];
    }
    /*for(cnt=0;cnt<5;cnt++){
        printf("%d ", data[cnt]);
    }
    printf(" (int)\n");*/
    
    //encrypt
    for(cnt=0;cnt<5;cnt++){
        cipher[cnt] = powMod(data[cnt], e, n);
    }
    
    printf("The cipher text is: ");
    for(cnt=0;cnt<5;cnt++){
        printf("%d ", cipher[cnt]);
    }
    printf(" (int)\n");
    
    printf("The cipher text is: ");
    for(cnt=0;cnt<5;cnt++){
        printf("%c", cipher[cnt]);
    }
    printf(" (char)\n");
    
    //decrypt
    for(cnt=0;cnt<5;cnt++){
        decrypt[cnt] = powMod(cipher[cnt], d, n);
    }
    
    printf("The decrypted text is: ");
    for(cnt=0;cnt<5;cnt++){
        printf("%d ", decrypt[cnt]);
    }
    printf(" (int)\n");
    
    printf("The decrypted text is: ");
    for(cnt=0;cnt<5;cnt++){
        printf("%c", decrypt[cnt]);
    }
    printf(" (char)\n");

    return 0;
}
