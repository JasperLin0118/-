#include<stdio.h>
#include<string.h>

void add(char a[], char b[], char res[]);

int main(){
    char a[100], b[100], res[105];
    scanf("%s %s", a, b);
    add(a, b, res);
    printf("%s", res);
    return 0;
}
void add(char a[], char b[], char res[]){
    for(int i=0;i<strlen(a)/2;i++)
    {
        char temp=a[i];
        a[i]=a[strlen(a)-1-i];
        a[strlen(a)-1-i]=temp;
    }
    for(int j=0;j<strlen(b)/2;j++)
    {
        char temp=b[j];
        b[j]=b[strlen(b)-1-j];
        b[strlen(b)-1-j]=temp;
    }
    unsigned long length, length2;
    if(strlen(a)>strlen(b))
    {
        length=strlen(a);
        length2=strlen(b);
    }
    else
    {
        length=strlen(b);
        length2=strlen(a);
    }
    int carry=0;
    for(int k=0;k<length;k++)
    {
        if(k>=length2 && strlen(a)>strlen(b))
        {
            if(a[k]+carry>'9')
            {
                res[k]=(a[k]+carry)%('9'+1)+'0';
                carry=1;
                continue;
            }
            res[k]= a[k]+carry;
            carry=0;
        }
        else if(k>=length2 && strlen(b)>strlen(a))
        {
            if(b[k]+carry>'9')
            {
                res[k]=(b[k]+carry)%('9'+1)+'0';
                carry=1;
                continue;
            }
            res[k]= b[k]+carry;
            carry=0;
        }
        else if(k<length2 && a[k]+b[k]+carry-'0'>'9')
        {
            res[k]=(a[k]+b[k]+carry)%('9'+1);
            carry=1;
        }
        else if(k<length2 && a[k]+b[k]+carry-'0'<='9')
        {
            res[k]=a[k]+b[k]+carry-'0';
            carry=0;
        }
    }
    if(carry==1)
    {
        res[length]='1';
        res[length+1]='\0';
        length+=1;
    }
    else if(carry==0)
        res[length]='\0';
    for(int i=0;i<length/2;i++)
    {
        char temp=res[i];
        res[i]=res[length-1-i];
        res[length-1-i]=temp;
    }
}
