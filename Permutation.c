#include <stdio.h>
#include <string.h>
void per(char string[], int count[])
{
    int zero=0;
    for(int j=0;j<strlen(string);j++)
    {
        if(count[j]==1)
        {
            zero=1;
            break;
        }
    }
    if(zero==1)
    {
        for(int i=0;i<strlen(string);i++)
        {
            if(count[i]==1)
            {
                printf("%c", string[i]);
                count[i]=0;
                return per(string, count);
            }
        }
    }
}
int main(void){
    char a[7];
    scanf("%s", a);
    int count[7]={1};
    for(int i=0;i<strlen(a)-1;i++)
    {
        count[i]=1;
        for(int j=i+1;j<strlen(a);j++)
        {
            if(a[j-1]>a[j])
            {
                char flag=a[j-1];
                a[j-1]=a[j];
                a[j]=flag;
            }
        }
    }
    count[strlen(a)-1]=1;
    per(a, count);
    return 0;
}
