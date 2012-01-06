#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Letter {
public:
    char c;
    int freq;
    Letter() {
        c = 0;
        freq = 0;
    }
    Letter(char tc) {
        c = tc;
        freq = 0;
    }
    bool operator < (const Letter &other) const {
        return freq < other.freq || freq == other.freq && c > other.c;
    }
};

int main() {
    vector<Letter> letters;
    int n;
    char c;
    for (c = 'A'; c <= 'Z'; ++c) {
        letters.push_back(Letter(c));
    }
    scanf("%d\n", &n);
    while(scanf("%c", &c) != EOF) {
        if ('a' <= c && c <= 'z') {
            ++letters[c - 'a'].freq;
        } else if ('A' <= c && c <= 'Z') {
            ++letters[c - 'A'].freq;
        }
    }
    sort(letters.begin(), letters.end());
    for (int i = 25; i >= 0; --i) {
        if (!letters[i].freq) {
            break;
        }
        printf("%c %d\n", letters[i].c, letters[i].freq);
    }
    return 0;
}

