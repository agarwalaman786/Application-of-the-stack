#include<stdio.h>
#include<conio.h>
#include<time.h>
#define capacity 20
struct stack 
{
    int top;
    char array[capacity];
};
struct stack s1;

// Expression to push the character in the stack;
void push(char s)
{
 if(s1.top==capacity-1)
    printf("Stack is full\n");
  else
    {
    s1.top++;
    s1.array[s1.top]=s;
    }
}

//function to pop the elements
char pop()
{
    char popped;
    if(s1.top==-1)
      return '0';
    else
      {
          popped = s1.array[s1.top];
          s1.top--;
      }
    return popped;
}

// Expression to peek the top element
char peep()
{
    if(s1.top==-1)
      return '0';
    else
      return s1.array[s1.top];
}

// Tower oh hanoi
void TOH(int n,char beg, char aux, char end)
{
	if(n>=1)
	{
		TOH(n-1,beg,end,aux);
		printf("%c to %c\n",beg,end);
		TOH(n-1,aux,beg,end);
	}
}


int priority(char c)
{
    if(c=='^')
        return 3;
    if(c=='*'||c=='/')
        return 2;
    if(c=='+'||c=='-')
        return 1;
    if(c=='(')
        return 0;
}

void infix_to_postfix(char *s, int length)
{
    int i=0,j=-1;
    char string[30],character;
    push('(');
    s[length]=')';
    for(i=0;i<=length;i++)
    {
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
            {
            j++;
            string[j]=s[i];
            }
        else
            if(s[i]=='(')
               push('(');
        else
            if(s[i]=='+'||s[i]=='*'||s[i]=='-'||s[i]=='/'||s[i]=='^')
            {
            if(priority(peep())<priority(s[i]))
               push(s[i]);
            else
            {
                character=pop();
                j++;
                string[j]=character;
                push(s[i]);
            }
           }
        else
        {
            if(s[i]==')')
            {
                while(peep()!='(')
                {
                    j++;
                    string[j]=pop();
                }
                if(peep()=='(')
                   pop();
            }
        }
    }
    printf("postfix Expression %s",string);
}

void Evaluation_of_postfix(char *s, int length)
{
    int i,a,b;
    for(i=0;i<length;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            push(s[i]-'0');
        }
        if(s[i]=='+' || s[i]=='-' || s[i]=='*'|| s[i]=='/')
        {
            if(s[i]=='+')
            {
                a=pop();
                b=pop();
                push(a+b);
            }
            if(s[i]=='-')
            {
                a=pop();
                b=pop();
                push(b-a);
            }
            if(s[i]=='*')
            {
                a=pop();
                b=pop();
                push(a*b);
            }
            if(s[i]=='/')
            {
                a=pop();
                b=pop();
                push(b/a);
            }
        }
    }
    printf("Evaluated value %d",peep());
    getch();
}

//function to check balancing 
void balance(char *s,int length)
{
    int i;
    push('{');
    for(i=0;i<length;i++)
    {
        if(s[i]=='(')
          push(s[i]);
        if(s[i]==')')
          pop();
    }
    if(peep()=='{' && i==length)
    {
       printf("Expression is balanced\n");
       getch();
    }
    else

    {   printf("Expression is not balanced\n");
       getch();
        
    }
}

// choice function to implement the choice
void choice()
{
    int choice;
    time_t start,end;
    char s[30];
    int l;
    while(1)
    {
        printf("\n1.Tower oh Hanoi\n2.Convert infix to postfix\n3.check the balancing of an Expression\n4.Evalualtion of a postfix Expression\n5.Exit\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            start=time(NULL);
            TOH(20,'A','B','C');
            end=time(NULL);
            printf("%lf",(end-start));
            getch();
            break;
            case 2:
            printf("Enter the infix expression to convert into postfix\n");
            scanf("%s",&s);
            l=strlen(s);
            infix_to_postfix(s,l);
            break;
            case 3:
            printf("Enter the expression to check the balancing\n");
            scanf("%s",&s);
            l=strlen(s);
            balance(s,l);
            getch();
            break;
            case 4:
            printf("Enter the psotfix expression\n");
            scanf("%s",&s);
            l=strlen(s);
            Evaluation_of_postfix(s,l);
            getch();
            break;
            case 5:
            exit(0);
            break;
        }
    }
}

// main function to implement all the operations
int main()
{
   s1.top=-1;
   choice();
   getch();
   return 0;
}

