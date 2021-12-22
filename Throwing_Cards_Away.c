#include <stdio.h>

int main()
{
    int n, count, current=1;
    scanf("%d %d", &n, &count);
    int card[n], check[n];
    for(int i=0;i<n;i++)
    {
        card[i]=i+1;
        check[i]=1;
    }
    while(count!=0)
    {
        for(int j=0;j<n;j++)
        {
            if(check[j]==1)
            {
                if(current==0)
                    current++;
                else if(current==1)
                {
                    current=0;
                    printf("%d ", card[j]);
                    check[j]=0;
                    count--;
                }
            }
            if(count==0)
                break;
        }
    }
    return 0;
}
