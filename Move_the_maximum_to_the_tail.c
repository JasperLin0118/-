#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;
void MoveToTail(void);

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        struct node* tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if(i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for(struct node* cur = head; cur != NULL; cur = cur->next)
        printf("%d ", cur->val);
    return 0;
}
void MoveToTail() {
    // "struct node* head" and "struct node* tail" are in global
    // you can use this two pointers to do this problem
    struct node* getmax=head;
    int currmax=0;
    while(getmax->next)
    {
        if(getmax->val>currmax)
            currmax=getmax->val;
        getmax=getmax->next;
    }
    if(tail->val>currmax)
        currmax=tail->val;
    getmax=head;
    while(getmax->next)
    {
        if(tail->val==currmax)
            break;
        if(head->val==currmax)
        {
            struct node* maxnode=getmax;
            head=maxnode->next;
            maxnode->next=NULL;
            tail->next=maxnode;
            tail=maxnode;
            break;
        }
        else if(getmax->next->val==currmax)
        {
            struct node* before_maxnode=getmax;  //2
            struct node* maxnode=getmax->next;  //5
            before_maxnode->next=maxnode->next;
            maxnode->next=NULL;
            tail->next=maxnode;
            tail=maxnode;
            break;
        }
        getmax=getmax->next;
    }
}
