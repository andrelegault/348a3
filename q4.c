#include <stdio.h>
#include <string.h>

int twoStrCompr(const char*, const char*);

int main() {
    char* str1 = "AAAAAAA";
    char* str2 = "AAAAAAB";
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
    int minLen;
    if (len1 < len2)
        minLen = len1;
    else
        minLen = len2;
    for(i = 0; i < minLen; i++) {
        int ch1 = first[i];
        int ch2 = second[i];
        if (ch1 < ch2) return 1;
    }
    return 0;
}