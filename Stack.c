#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

struct element {                        // elements of the stack
        int data;
        struct element *next;   // point to the next element in the stack
};

struct head {  //紀錄stack最上面的元素
        int size;                               // record the size of the stack
        struct element *init; // point to the bottom element in the stack if there is any
        struct element *top;    // point to the top of the stack
};

void print_stack(struct head *stack_p);
void push(struct head *stack_p, int data);// put an element to the top of the stack
struct element *pop(struct head *stack_p);// remove an element from the top of the stack

int main(void) {
        // stack declaration
        struct head stack_head;
        stack_head.size = 0;
        stack_head.init = NULL; //
        stack_head.top = NULL;
        // read instructions
        int num, data;
        char command[5];
        scanf("%d", &num);
        for (int i = 0; i < num; ++i) {
                scanf("%4s", command);
                if (strcmp(command, "push") == 0) {     // push command, call push()
                        scanf("%d", &data);
                        push(&stack_head, data);
                }
                else if (strcmp(command, "pop") == 0) { // pop command, call pop()
                        struct element *e = pop(&stack_head);
                        free(e);
                }
        }
        print_stack(&stack_head);
        return 0;
}

void print_stack(struct head *stack_p) {
        printf("%d\n", stack_p->size);
        for (struct element *ptr = stack_p->init; ptr != NULL; ptr = ptr->next)//
                printf("%d ", ptr->data);
}
void push(struct head *stack_p, int data)
{     // create an element and push it to the top of the stack
    stack_p->size+=1;
    struct element *new=malloc(sizeof(struct element));
    new->data=data;
    new->next=NULL;
    if(stack_p->top)
    {
        stack_p->top->next=new;
        stack_p->top=new;
    }
    else
    {
        stack_p->top=new;
        stack_p->init=new;//
    }
}

struct element* pop(struct head *stack_p)
{ // return the element which is popped from the stack
    stack_p->size-=1;
    struct element *curr=stack_p->top,*curr2=stack_p->init;//
    if(stack_p->size==0)
    {
        stack_p->init=NULL;//
        stack_p->top=NULL;
    }
    else
    {
        while(curr2)//
        {
            if(curr2->next==curr)
            {
                stack_p->top=curr2;
                curr2->next=NULL;
                break;
            }
            curr2=curr2->next;//
        }
    }
    return curr;
}
