#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1500
#define oo 1<<30

using namespace std;

int main() {
    int ugly_set[MAXN+1] = {0, 1};
    int pointers[] = {1, 1, 1};
    int factors[] = {2, 3, 5};
    for (int i = 2; i <= MAXN; ++i) {
        int minn = oo, minj = 0;
        for (int j = 0; j < 3; ++j) {
            while(ugly_set[pointers[j]] * factors[j] <= ugly_set[i - 1]) {
                ++pointers[j];
            }
            if (ugly_set[pointers[j]] * factors[j] < minn) {
                minn = ugly_set[pointers[j]] * factors[j];
                minj = j;
            }
        }
        ugly_set[i] = minn;
        ++pointers[minj];
    }
    printf("The 1500'th ugly number is %d.\n", ugly_set[MAXN]);
    return 0;
}

