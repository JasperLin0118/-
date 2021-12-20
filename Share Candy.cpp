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
	int i=0, left_plus=0, right_plus, total=0;
	while(i<100)
	{
		if(str[i]=='\0')
		{
			int ten1=1;
			right_plus=i-1;
			for(int k=right_plus-left_plus;k>left_plus;k--)
			{
				total+=ten1*(int)str[k];
				ten1*=10;
			}
			break;
		}
		else if(str[i]=='+')
		{
			int ten=1, n=i-1;
			right_plus=i;
			while(n--)
			{
				if(str[n]=='+')
				{
					left_plus=n;
					break;
				}
			}//4-1
			for(int j=right_plus-left_plus;j>left_plus;j--)
			{
				total=total+ ten*(int)str[j];
				ten*=10;
			}
			i++;
			printf("%d\n", total);
		}
		else//1+22+333
			i++;
	}
	return total;
}
