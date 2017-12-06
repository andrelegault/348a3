#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int twoStrCompr(const char*, const char*);

int main() {
    char* str1 = "ccc";
    char* str2 = "ccca";
    printf("theirs: %d, mine: %d\n", strcmp(str1, str2), twoStrCompr(str1, str2));
    return 0;
    if(twoStrCompr(str1, str2) == 1)
        printf("%s\n", "True");
    else
        printf("%s\n", "False");
    char* str3 = "aaaaaaa";
    char* str4 = "aaaaaab";
    if(twoStrCompr(str3, str4) == 1)
        printf("%s\n", "True");
    else
        printf("%s\n", "False");
}

int twoStrCompr(const char* first, const char* second) {
    int i;
    int len1 = strlen(first);
    int len2 = strlen(second);
    int minLen = len1 < len2? len1: len2;
    for(i = 0; i < minLen; i++) {
        int ch1 = *(first+i);
        int ch2 = *(second+i);
        valid(ch1);
        valid(ch2);
        if (ch1 < ch2) return 1;
    }
    if(len1 < len2) {
        return 1;
    } else {
        if(len1 == len2) {
            printf("%d %d", *(first), *(second));
            return *(first+minLen-1) <= *(second+minLen-1);
        }
    }
    return 0;
}

int valid(int ch) {
    if(!(ch >= 97 && ch <= 122) && !(ch >= 65 && ch <= 90)) {
        fprintf(stderr, "invalid character");
        exit(EXIT_FAILURE);
    }
    return 1;
}
