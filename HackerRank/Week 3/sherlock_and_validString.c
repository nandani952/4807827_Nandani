#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* checkValidity(char* s) {
    int freq[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        freq[s[i] - 'a']++;
    }
    int frequencyCounts[100001] = {0};
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            frequencyCounts[freq[i]]++;
        }
    }
    int distinctFreq = 0;
    int firstFreq = -1;
    int secondFreq = -1;
    
    for (int i = 0; i < 100001; i++) {
        if (frequencyCounts[i] > 0) {
            distinctFreq++;
            if (firstFreq == -1) {
                firstFreq = i;
            } else {
                secondFreq = i;
            }
        }
    }
    if (distinctFreq == 1) {
        return "YES";
    }
    if (distinctFreq == 2) {
        if (frequencyCounts[firstFreq] == 1 && firstFreq == 1) {
            return "YES";
        }
        if (frequencyCounts[secondFreq] == 1 && secondFreq - firstFreq == 1) {
            return "YES";
        }
    }
    return "NO";
}
int main() {
    char s[100001];
    scanf("%s", s);
    char* result = checkValidity(s);
    printf("%s\n", result);
    return 0;
}
