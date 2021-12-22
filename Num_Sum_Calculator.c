#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100

int addition(char str[]);

int main() {
    char str[N];
    scanf("%s", str);
    int sum = addition(str);
    printf("%d", sum);
    return 0;
}
int addition(char str[])
{
    int sum=0;
    char plus[2]={'+'}, *sub=strtok(str, plus);
    while(sub!=NULL)
    {
        sum+=atoi(sub);
        sub=strtok(NULL, plus);
    }
    return sum;
}
