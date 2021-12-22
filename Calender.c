#include<stdio.h>

int main(){
    int days=3, count=0, num, month[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d", &num);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    for(int j=1;j<num;j++)
        days+=month[j-1];
    count+=days%7;
    for(int k=0;k<count;k++)
        printf("    ");
    for(int i=1;i<=month[num-1];i++)
    {
        printf("%3d ", i);
        count+=1;
        if(count%7==0 && i!=month[num-1])
            puts("");
    }
}
