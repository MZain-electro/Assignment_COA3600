#include<ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>


int top = -1;

char stack[100];

//Define Stack Operations
int Stack_is_filled() {
    return top == 100 - 1;
} 

int Stack_is_empty() { 
    return top == -1; 
}

void push(char item) {
    if (Stack_is_filled()) 
        return; //no space
        else{
	top++;
	stack[top] = item;
    return;
        }
}

int pop() { 
    if (Stack_is_empty()) 
        return -1; 
           
    return stack[top--]; 
} 

int peek(){ 
    if (Stack_is_empty()) 
        return -1; 
    return stack[top]; 
} 
//End Define Stack Operations
int checkIfOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

int precedence(char operand_type) 
{ 
    switch (operand_type) 
    { 
    case '+': 
    case '-': 
        return 1; 

    case '*': 
    case '/': 
        return 2; 

    case '^': 
        return 3; 
    } 
    return -1; 
} 

void paranthesis(char* exp){
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
          {  exp[i]=')';}
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}

int getPostfix(char* expression) 
{ 
    int i, j;

    for (i = 0, j = -1; expression[i]; ++i) 
    { 
        if (checkIfOperand(expression[i])) 
            expression[++j] = expression[i]; 

        else if (expression[i] == '(') 
            push(expression[i]); 

        else if (expression[i] == ')') 
        { 
            while (!Stack_is_empty(stack) && peek(stack) != '(') 
                expression[++j] = pop(stack); 
            if (!Stack_is_empty(stack) && peek(stack) != '(') 
                return -1;              
            else
                pop(stack); 
        } 
        else 
        { 
            while (!Stack_is_empty(stack) && precedence(expression[i]) <= precedence(peek(stack))) 
                expression[++j] = pop(stack); 
            push(expression[i]); 
        } 

    } 
    while (!Stack_is_empty(stack)) 
        expression[++j] = pop(stack); 

    expression[++j] = '\0'; 
    
}

void reverse(char *exp){

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}

void InfixtoPrefix(char *exp){

    int size = strlen(exp);

    reverse(exp);
    paranthesis(exp);
    getPostfix(exp);
    reverse(exp);
}

int main()
{    
    printf("The infix is: ");

    char expression[] = "A*B-(C+D)+E"; 
    printf(" %s \n",expression);
    InfixtoPrefix(expression); 

    printf("The prefix is: ");
    printf(" %s \n",expression);

    return 0; 
}
