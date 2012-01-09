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
    int is_first = 1;
    while (scanf("%c", &c) != EOF) {
        if (c == '"') {
            if (is_first) {
                printf("``");
            } else {
                printf("''");
            }
            is_first = 1 - is_first;
        } else {
            printf("%c", c);
        }
    }
    return 0;
}

