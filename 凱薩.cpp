#include<stdio.h>
int main(){
    int k;
    scanf("%d\n", &k);
    k%=26;
    while(1)
    {
        char a=getchar();
        if(a=='\n')
            break;
        else if(a>='a'&&a<='z')
        {
        	if(k>=0 && a+k<='z')
        		printf("%c", a+k);
        	else if(k>0 && a+k>'z')
        		printf("%c", 'a'+((a+k)-'z'-1));
        	else if(k<0 && a+k>='a')
        		printf("%c", a+k);
        	else if(k<0 && a+k<'a')
        		printf("%c", 'z'-('a'-a-k)+1);
		}
		else if(a>='A'&&a<='Z')
		{
			if(k>=0 && a+k<='Z')
        		printf("%c", a+k);
        	else if(k>0 && a+k>'Z')
        		printf("%c", 'A'+((a+k)-'Z'-1));
        	else if(k<0 && a+k>='A')
        		printf("%c", a+k);
        	else if(k<0 && a+k<'A')
        		printf("%c", 'Z'-('A'-a-k)+1);
		}
		else 
			printf("%c", a);
    }
    return 0;
}

