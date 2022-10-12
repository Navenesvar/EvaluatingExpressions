#include<stdio.h>
#include<ctype.h>   //For using isalpha() function
int arr[100];
char s[101];
int stack[100];
void precedence(int t);
void empty();
void display();
int j=0,k=0,i=0,a;
int main()
{
	int t;
	printf("Enter # symbol to stop");
	printf("\nEnter the infix expression :");
	scanf("%s",s);
	while(s[i]!='#')
	{
		if(s[i]=='(')
		{
			stack[j]=s[i];
			a=j;
			j++;
		}
		else if(s[i]=='*' || s[i]=='/')
		{
			t=1;
			precedence(t);
		}
		else if(s[i]=='-' || s[i]=='+')
		{
			t=2;
			precedence(t);
		}
		else if(s[i]==')')
		{
			empty();
		}
			
		else
		{
			arr[k]=s[i];
			k++;
		}
		i++;
		
	}
	arr[k]=stack[a];
	display();
	return 0;
}
void precedence(int t)
{
	if(t==1)
	{
		if(stack[a]=='*' || stack[a]=='/')
		{
			arr[k]=stack[a];
			j=a;
			stack[j]=s[i];
			j++;
			k++;
		}
		else
		{
			stack[j]=s[i];
			a=j;
			j++;
		}
	}
	if(t==2)
	{
		if(stack[a]=='*' || stack[a]=='/' || stack[a]=='+' || stack[a]=='-')
		{
			arr[k]=stack[a];
			j=a;
			stack[j]=s[i];
			j++;
			k++;
		}
		else
		{
			stack[j]=s[i];
			a=j;
			j++;
		}
	}
}
//Function to empty the stack until the open parenthesis occurs
void empty()
{
	int b=a;
	while(stack[b]!='(')
	{
		arr[k]=stack[b];
		b--;
		k++;
	}
	j=b-1;
	a=j;
}
//Function to finally display the postfix expression void display()
{
	printf("\nThe postfix expression is ");
	for(int c=0;c<=k;c++)
	{
		if(arr[c]=='+')
		{
			printf("+");
		}
		else if(arr[c]=='-')
		{
			printf("-");
		}
		else if(arr[c]=='*')
		{
			printf("*");
		}
		else if(arr[c]=='/')
		{
			printf("/");
		}
		else if(isalpha(arr[c]))
		{
			char x = arr[c];
			printf("%c",x);
		}
	}
}
