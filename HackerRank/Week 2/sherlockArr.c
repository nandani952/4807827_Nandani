#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char _cases[10];
    int i,cases;
    fgets(_cases, sizeof(cases), stdin);
    sscanf(_cases,"%d", &cases);
    for (i=0; i< cases; i++){
        char _n[10];
        char _elementlist[1000000];
        unsigned long long int n;
        unsigned long long int elementlist[100000] = {0};
        fgets(_n, sizeof(n), stdin);
        sscanf(_n,"%llu", &n);

        fgets(_elementlist, sizeof(_elementlist), stdin);
        char *p;
        p = strtok(_elementlist, " ");
        int a=1;
        while (p != NULL){
            sscanf(p, "%llu", &elementlist[a]);
            elementlist[a] += elementlist[a-1];
            a++;
            p = strtok (NULL, " ");
        }
        int j, k=0;
        for(j=1; j<=n; j++){
            if(elementlist[j-1]==(elementlist[n]-elementlist[j])){
                k = 1;
                printf("YES\n");
                break;
            }
        }
        if(k==0){
            printf("NO\n");
        }

    }
}
