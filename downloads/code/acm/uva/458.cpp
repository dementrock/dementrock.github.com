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
    char c;
    while (scanf("%c", &c) != EOF) {
        if (c == '\n') {
            printf("\n");
        } else {
            printf("%c", c - 7);
        }
    }
    return 0;
}

