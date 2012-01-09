#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

string type[] = {"B", "G", "C"};

int main() {
    int a[3][3], ans = 0, sum = 0;
    string ansStr = "";
    while(1) {
        sum = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (!(cin >> a[i][j])) {
                    return 0;
                }
                sum += a[i][j];
            }
        }
        ans = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) if (i != j) {
                for (int k = 0; k < 3; ++k) if (k != i && k != j) {
                    int tmpans = a[0][i] + a[1][j] + a[2][k];
                    string tmpStr = type[i] + type[j] + type[k];
                    if (tmpans > ans || tmpans == ans && tmpStr < ansStr) {
                        ans = tmpans;
                        ansStr = tmpStr;
                    }
                }
            }
        }
        cout << ansStr << " " << sum - ans << endl;
    }
    return 0;
}

