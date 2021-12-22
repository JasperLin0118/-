/*
#include <stdio.h>
#include <math.h>
int main() {
    int mode;
    scanf("%d", &mode);
    if(mode==1)
    {
        double length;
        scanf("%lf", &length);
        printf("%.2lf", pow(length, 3));
    }
    else if(mode==2)
    {
        double l, h, w;
        scanf("%lf %lf %lf", &l, &h, &w);
        printf("%.2lf", l*h*w);
    }
    else if (mode==3)
    {
        double radius, height;
        scanf("%lf %lf", &radius, &height);
        printf("%.2lf", 3.14*pow(radius, 2)*height);
    }
    else
    {
        double length;
        scanf("%lf", &length);
        printf("%.2lf", (sqrt(2)/12)*pow(length, 3));
    }
    return 0;
}

#include<stdio.h>
#include<math.h>
int main(){
    double R;
    int N;
    scanf("%lf %d",&R, &N);
    printf("%d", (int)pow(R, N));
    return 0;
}
 
#include<stdio.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    int first[m], second[n], total[m+n];
    for(int i=0;i<m;i++)
    {
        scanf("%d", &first[i]);
        total[i]=first[i];
    }
    for(int j=0;j<n;j++)
        scanf("%d", &second[j]);
    int count=0;
    for(int k=m;k<m+n;k++)
    {
        total[k]=second[count];
        count++;
    }
    for(int a=0;a<m+n-1;a++)
    {
        for(int b=a+1;b<m+n;b++)
        {
            if(total[a]>total[b])
            {
                int flag=total[a];
                total[a]=total[b];
                total[b]=flag;
                continue;
            }
        }
    }
    for(int check=0;check<m+n;check++)
        printf("%d ", total[check]);
    return 0;
}

#include<stdio.h>

int main(){
    int degree;
    scanf("%d", &degree);
    int m, n;
    scanf("%d %d", &m, &n);
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d", &a[i][j]);
    }
    if(degree==90)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=m-1;j>=0;j--)
                printf("%d ", a[j][i]);
            printf("\n");
        }
    }
    else if(degree==180)
    {
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
                printf("%d ", a[i][j]);
            printf("\n");
        }
    }
    else
    {
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<m;j++)
                printf("%d ", a[j][i]);
            printf("\n");
        }
    }
    return 0;
}


#include<stdio.h>

int main(){
    int key, i=0;
    scanf("%d\n", &key);
    int secret[key];
    while(1)
    {
        char a = getchar();
        if(a=='\n')
            break;
        secret[i]=a-'a';
        i++;
    }
    int count=0;
    while(1)
    {
        char b=getchar();
        if(b=='\n')
            break;
        else if('A'<= b && b <='Z')
        {
            if(b+secret[count]<='Z')
            {
                printf("%c", b+secret[count]);
                count++;
            }
            else
            {
                printf("%c", b+secret[count]-('Z'-'A'+1));
                count++;
            }
        }
        else if('a'<= b && b <='z')
        {
            if(b+secret[count]<='z')
            {
                printf("%c", b+secret[count]);
                count++;
            }
            else
            {
                printf("%c", b+secret[count]-('z'-'a'+1));
                count++;
            }
        }
        else
            putchar(b);
        if(count==i)
            count-=i;
    }
    return 0;
}

*/

#include<stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    int array[num][num];
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
            array[i][j]=0;
    }
    array[0][num/2]=1;
    int i=0, j=num/2, count=2;
    while(count!=num*num+1)
    {
        if((i-1>=0 && j+1<num))  //正常
        {
            if(array[i-1][j+1]==0)
            {
                array[i-1][j+1]=count;
                count++;
                i-=1;
                j+=1;
            }
            else
            {
                array[i+1][j]=count;
                count++;
                i+=1;
            }
        }
        else if(i-1<0 && j+1>=num) //  (0, 2) ---> (2, 0)
        {
            if(array[num-1][0]==0)
            {
                array[num-1][0]=count;
                count++;
                i=num-1;
                j=0;
            }
            else
            {
                array[i+1][j]=count;
                count++;
                i+=1;
            }
        }
        else if(i-1>=0 && j+1>=num)    // (1, 2)-->(0, 0)
        {
            if(array[i-1][0]==0)
            {
                array[i-1][0]=count;
                count++;
                i-=1;
                j=0;
            }
            else
            {
                array[i+1][j]=count;
                count++;
                i+=1;
            }
        }
        else if(i-1<0 && j+1<num)   //(0, 1)-->(2, 2)
        {
            if(array[num-1][j+1]==0)
            {
                array[num-1][j+1]=count;
                count++;
                i=num-1;
                j+=1;
            }
            else
            {
                array[i+1][j]=count;
                count++;
                i+=1;
            }
        }
    }
    for(int a=0;a<num;a++)
    {
        for(int b=0;b<num;b++)
            printf("%d ", array[a][b]);
        puts("");
    }
    return 0;
}
