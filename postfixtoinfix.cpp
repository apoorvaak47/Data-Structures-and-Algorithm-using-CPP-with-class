#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;
const int size=50;
class StackIP
{
	public:
		char infix[size];
		char postfix[size];
		char Stack[size];
		int top=-1;
		int precedence(char ch);
		char pop();
		char topelement();
		void push(char ch);
		int braces(char *);
};
int StackIP :: precedence(char ch)
{
	switch(ch)
	{
		case'^': return 5;
		case'/': return 4;
		case'*': return 4;
		case'+': return 3;
		case'-': return 3;
		default: return 0;
	}
}
char StackIP :: pop()
{
	char ret;
	if(top!=-1)
	{
		ret=Stack[top];
		top--;
		return ret;
	}
	else
	return '#';
}
char StackIP :: topelement()
{
	char ch;
	if(top=-1)
	{
		ch=Stack[top];
	}
	else
	{
		ch='#';
	}
	return ch;
}
void StackIP :: push(char ch)
{
	if(top!=-1)
	{
		top++;
		Stack[top]=ch;
	}
}
int StackIP :: braces(char *s)
{
	int leftbr, rightbr;
	leftbr=rightbr=0;
	for(int i=0;s[i];i++)
	{
		if(s[i]=='(')
		{
			leftbr++;
		}
		else if(s[i]==')')
		{
			rightbr++;
		}
	}
	if(leftbr == rightbr)
	{
		return 0;
	}
	else if(leftbr<rightbr)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main()
{
	StackIP S;
	char ele, elem,st[2];
	int prep,pre,popped,j=0,chk=0;
	strcpy(S.postfix," ");
	cout<<"\n Enter Infix Expression : ";
	cin>>S.infix;
	chk=S.braces(S.infix);
	if(chk!=0)
	{
		cout<<"\nUnbalanced no. of braces.";
		cout<<(chk==1?"right braces":"left braces")<<endl;
		system("pause");
		exit(1);
	}
	for(int i=0;S.infix[i]!='\0';i++)
	{
		if (S.infix[i] != '(' && S.infix[i]!='^' && S.infix[i] != '*' && S.infix[i] != '/' && S.infix[i] != '+' && S.infix[i] != '-')
		{
			S.postfix[j++]=S.infix[i];
		}
		else if(S.infix[i] == '(')
		{
			elem=S.infix[i];
			S.push(elem);
		}
		else if(S.infix[i] == ')')
		{
			while((popped = S.pop()) != '(')
			{
				S.postfix[j++]=popped;
			}
		}
		else
		{
			elem = S.infix[i];
			pre = S.precedence(elem);
			ele = S.topelement();
			prep = S.precedence(ele);
			if(pre > prep)
			{
				S.push(elem);
			}
			else
			{
				while(prep>=pre)
				{
					if(ele = '#')
					{
						break;
						popped = S.pop();
						ele = S.topelement();
						S.postfix[j++] = popped;
						prep=S.precedence(ele);
					}
					S.push(elem);
				}
			}
		}
	}
	while((popped = S.pop()) != '#')
	{
		S.postfix[j++]=popped;
	}
	S.postfix[j]='\0';
	cout<<"\nThe postfix expression will be : "<<S.postfix<<endl;
	system("pause");
	return 0;
}