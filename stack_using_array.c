#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
  int size;
  int top;
  int *arr;
} Stack;

Stack *createStack(int size)
{
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->size = size;
  stack->top = -1;
  stack->arr = (int *)malloc(stack->size * sizeof(int));

  return stack;
}

int isEmpty(Stack *check)
{
  if (check->top == -1)
    return 1;
  else
    return 0;
}

int isFull(Stack *check)
{
  if (check->top == check->size - 1)
    return 1;
  else
    return 0;
}

void push(Stack *stack, int value)
{
  if (isFull(stack))
  {
    printf("Stack Overflow\n");
    return;
  }
  else
  {
    stack->top++;
    stack->arr[stack->top] = value;
  }
}

void pop(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Stack Underflow\n");
    return;
  }
  else
  {
    stack->top--;
  }
}

void display(Stack *displayStack)
{
  if (isEmpty(displayStack))
  {
    printf("Stack is empty\n");
    return;
  }

  printf("Stack elements: ");
  for (int i = 0; i <= displayStack->top; i++)
  {
    printf("%d ", displayStack->arr[i]);
  }
  printf("\n");
}

void peek(Stack *stack, int position)
{
  int index = stack->top - position + 1;
  if (index < 0 || index > stack->top)
  {
    printf("Invalid position\n");
    return;
  }
  printf("Value at position %d is %d\n", position, stack->arr[index]);
}

void stackTop(Stack *stack)
{
  if(isEmpty(stack))
  {
    printf("Stack is empty\n");
    return;
  }
  printf("Top element is %d\n", stack->arr[stack->top]);
}

void stackBottom(Stack *stack)
{
  if(isEmpty(stack))
  {
    printf("Stack is empty\n");
    return;
  }
  printf("Bottom element is %d\n", stack->arr[0]);
}

int main()
{
  while (1)
  {
    printf("\nMenu:\n\n");
    printf("1. Create Stack\n");
    printf("2. Push element onto Stack\n");
    printf("3. Pop element from Stack\n");
    printf("4. Display Stack elements\n");
    printf("5. Peek element from Stack\n");
    printf("6. Peek element from StackTop\n");
    printf("7. Peek element from StackBottom\n");
    printf("8. Check if stack is empty\n");
    printf("9. Check if stack is full\n");
    printf("10. Exit\n\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the size of the stack: ");
      int size;
      scanf("%d", &size);
      Stack *stack = createStack(size);
      printf("Stack created successfully\n");
      break;

    case 2:
    {
      int value;
      printf("Enter the value to push onto the stack: ");
      scanf("%d", &value);
      push(stack, value);
      printf("Value pushed onto the stack\n");
      break;
    }

    case 3:
    {
      pop(stack);
      printf("Top value popped from the stack\n");
      break;
    }

    case 4:
      display(stack);
      break;

    case 5:
    {
      int position;
      printf("Enter the position to peek from the stack: ");
      scanf("%d", &position);
      peek(stack, position);
      break;
    }

    case 6:
      stackTop(stack);
      break;

    case 7:
      stackBottom(stack);
      break;

    case 8:
      if (isEmpty(stack))
        printf("Stack is empty\n");
      else
        printf("Stack is not empty\n");
      break;

    case 9:
      if (isFull(stack))
        printf("Stack is full\n");
      else
        printf("Stack is not full\n");
      break;

    case 10:
      printf("Exiting the program.\n");
      return 0;

    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  }

  return 0;
}