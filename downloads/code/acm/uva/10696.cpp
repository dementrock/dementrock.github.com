#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n)) {
        if (!n) {
            break;
        }
        printf("f91(%d) = %d\n", n, n <= 100 ? 91 : n - 10);
    }
    return 0;
}

