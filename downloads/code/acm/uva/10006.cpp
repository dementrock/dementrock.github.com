#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 65000

using namespace std;

int is_prime[MAXN+1], is_carmichael[MAXN+1];

int expmod (int a, int b, int c) { // Calculate a ^ b mod c
    long long ans = 1, mult = a;
    while (b) {
        if (b & 1) {
            ans = (ans * mult) % c;
        }
        mult = (mult * mult) % c;
        b >>= 1;
    }
    return (int) ans;
}

int is_passed (int n) {
    for (int a = 2; a < n; ++a) {
        if (expmod(a, n, n) != a) {
            return 0;
        }
    }
    return 1;
}

int init() {
    /* Sieve primes */
    memset(is_prime, 0xff, sizeof(is_prime));
    for (int i = 2; i < MAXN; ++i) if (is_prime[i]) {
        for (int j = i + i; j < MAXN; j += i) {
            is_prime[j] = 0;
        }
    }
    for (int i = 3; i < MAXN; ++i) {
        is_carmichael[i] = !is_prime[i] && is_passed(i);
    }
}
        

int main() {
    init();
    int n;
    while (scanf("%d", &n)) {
        if (!n) {
            break;
        }
        printf(is_carmichael[n] ? "The number %d is a Carmichael number.\n" : "%d is normal.\n", n);
    }
    return 0;
}

