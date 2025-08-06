#include <stdio.h>
#include <string.h>

int main() {
    char time[11];
    scanf("%s", time);

    int hour;
    sscanf(time, "%d", &hour);
    if (strstr(time, "PM") != NULL && hour != 12) {
        hour += 12;
    } else if (strstr(time, "AM") != NULL && hour == 12) {
        hour = 0;
    }
    printf("%02d", hour); 
    
    for (int i = 2; i < 8; i++) {
        printf("%c", time[i]);
    }
    printf("\n");

    return 0;
}
