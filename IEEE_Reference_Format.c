#include<stdio.h>
#include<string.h>

char* reference(char author[], char title[], char conference[], char location[], char date[], char ppdoi[]);

int main(){
    char author[100], title[150], conference[150], location[30], date[5], ppdoi[60];
    scanf("%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]", author, title, conference, location, date, ppdoi);
    printf("%s", reference(author, title, conference, location, date, ppdoi));
    return 0;
}
// In case you don't know how to return a string, I already wrote that part. Just insert your thought between them.
char* reference(char author[], char title[], char conference[], char location[], char date[], char ppdoi[]){
    static char result[500];
    char a[4]={',', ' ', '"'}, b[3]={',', ' '}, c[4]={',', '"', ' '}, d[2]={'.'};
    strcat(result, author);
    strcat(result, a);
    strcat(result, title);
    strcat(result, c);
    strcat(result, conference);
    strcat(result, b);
    strcat(result, location);
    strcat(result, b);
    strcat(result, date);
    strcat(result, b);
    strcat(result, ppdoi);
    strcat(result, d);
    return result;
}
