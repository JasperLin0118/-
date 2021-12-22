#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *good_types[] = {
    "Juice",
    "Wine",
    "Laptop"
};

void *produce(void *top_of_stack, const char *good_type, size_t count);
void *consume(void *top_of_stack, size_t count);
void list_remain(void *top_of_stack);

int main(){
    char record[64], *job, *good;
    size_t count;
    void *top_of_stack = NULL;

    while(fgets(record, 64, stdin)){
        job = strtok(record, " ");
        if(!strcmp(job, "Produce")){
            good = strtok(NULL, " ");
            count = atol(strtok(NULL, " "));

            for(int i = 0; i < 3; i++){
                if(!strcmp(good, good_types[i])){
                    top_of_stack = produce(top_of_stack, good_types[i], count);
                    break;
                }
            }
        }
        else if(!strcmp(job, "Consume")){
            count = atol(strtok(NULL, " "));
            top_of_stack = consume(top_of_stack, count);
        }
    }

    list_remain(top_of_stack);

    return 0;
}
//You may need to define your own struct here.
struct items
{
    int amount;
    char goodname[20];
    struct items *next;
};
struct head
{
    //int size;
    struct items *init;
    struct items *top;
};
void *produce(struct head *top_of_stack, const char *good_type, const size_t count)
{
    struct items *new=malloc(sizeof(struct items));
    new->amount=(int)count;
    for(int i=0;i<strlen(good_type);i++)
        new->goodname[i]=good_type[i];
    new->next=NULL;
    if(top_of_stack->top)
    {
        top_of_stack->top->next=new;
        top_of_stack->top=new;
    }
    else
    {
        stack_p->top=new;
        stack_p->init=new;//
    }
}

void *consume(void *top_of_stack, const size_t count){

}

void list_remain(void *top_of_stack){
    for (struct items *ptr = stack_p->init; ptr != NULL; ptr = ptr->next)//
        printf("%s x %d", ptr->goodname, ptr->amount);
}
