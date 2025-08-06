#include <stdio.h>
int main() {
    int day;
    do {
        printf("Enter a number between 1 and 7: ");
        scanf("%d", &day);
        
        if(day < 1 || day > 7) {
            printf("Invalid input! Please enter a valid number between 1 and 7.\n");
        }
    } 
    while(day < 1 || day > 7);
    switch(day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
    }
    return 0;
}
