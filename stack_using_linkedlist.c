#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

StackNode *createStack(int data)
{
    StackNode *stack = (StackNode *)malloc(sizeof(StackNode));
    stack->data = data;
    stack->next = NULL;
    return stack;
}

int isEmpty(StackNode *check)
{
    if (check == NULL)
        return 1;
    else
        return 0;
}

int isFull(StackNode *check)
{
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    if(temp == NULL)
        return 1;
    else
    {
        free(temp);
        return 0;
    }
}

int main()
{

    int condition;
    do
    {
        int data;
        printf("Enter data to push onto the stack: ");
        scanf("%d", &data);
        createStack(data);

        printf("Do you want to create another Stack Node? (1 for yes / 0 for no): ");
        scanf("%d", &condition);
    } while (condition == 1);
    

    return 0;
}