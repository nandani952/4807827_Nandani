#include<stdio.h>
int main()
{
    int i,j,k,t,n,flag=0;
    char str[100][100];
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                scanf("%s",str[i]);
        }
        for(k=0;k<n;k++)
        {
             char current;
    
    for(i = 1; i< n; i++)
    {
        current = str[k][i];
        for(j = i-1; j>=0; j--)
        {
            if(current < str[k][j])
                str[k][j+1] = str[k][j];
            else
                break;
        }
        str[k][j+1] = current;
    }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(str[j][i]<=str[j+1][i])
                {
                    
                }
                else
                {
                    flag=1;
                }
            }
            if(flag==1)
            {
                break;
            }
        }
        if(flag==0)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
