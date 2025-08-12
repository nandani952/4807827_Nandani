#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
int main() {
    long long superdigit=0,h;
    int k;
    int c;
    do{
        c=getchar();
        if(c != ' ')
            superdigit += c -'0'; 
    }while(c != ' ');
    scanf("%d",&k);
    superdigit *= k;
    while(superdigit > 10){
        h=0;
        while(superdigit > 0){
            h+= superdigit %10;
            superdigit = superdigit /10;
        }
        superdigit =h;
    }
    printf("%lld\n",superdigit);    
    return 0;
}
