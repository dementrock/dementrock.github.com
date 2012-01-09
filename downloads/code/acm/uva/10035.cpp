#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 10

using namespace std;

int main() {
    int a, b, carry, remainder, sum;
    while(cin >> a >> b) {
        if (!a && !b) {
            break;
        }
        carry = 0;
        remainder = 0;
        for (int i = 0; i < LEN; ++i) {
            sum = a % 10 + b % 10 + remainder;
            if (sum >= 10) {
                ++carry;
                remainder = sum / 10;
            } else {
                remainder = 0;
            }
            a /= 10;
            b /= 10;
        }
        if (!carry) {
            cout << "No carry operation." << endl;
        } else if (carry == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << carry << " carry operations." << endl;
        }
    }
    return 0;
}

