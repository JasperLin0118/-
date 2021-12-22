#include<stdio.h>

int main(){
    int a[32], b[32], total[32], flag=0;
    for(int i=0;i<32;i++)
        scanf("%d", &a[i]);
    for(int j=0;j<32;j++)
        scanf("%d", &b[j]);
    for(int k=31;k>=0;k--)
    {
        if((a[k]^b[k])==1&&flag==0)
            total[k]=1;
        else if((a[k]^b[k])==1&&flag==1)
            total[k]=0;
        else if((a[k]==0&&b[k]==0)&&flag==0)
            total[k]=0;
        else if((a[k]==0&&b[k]==0)&&flag==1)
        {
            total[k]=1;
            flag=0;
        }
        else if((a[k]==1&&b[k]==1)&&flag==1)
        {
            total[k]=1;
            flag=1;
        }
        else if((a[k]==1&&b[k]==1)&& flag==0)
        {
            total[k]=0;
            flag=1;
        }
    }
    for(int l=0;l<32;l++)
        printf("%d ", total[l]);
}
/*Hint: After you finish this problem, you can try to use binary operators|, &, ^to implement an actual binary adder circuit in CPU. */
