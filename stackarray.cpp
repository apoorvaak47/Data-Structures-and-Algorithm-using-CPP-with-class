#include<iostream>
using namespace std;
#define SIZE 10
class Stack
{
    public:
       int num[SIZE];
       Stack();
       int top;
       int push(int);
       int pop();
       int isEmpty();
       int peek();
       int isFull();
       void displayItems();
};
Stack::Stack()
{
    top=-1;
}
int Stack::isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Stack::isFull()
{
    if(top==(SIZE-1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Stack::push(int n)
{
    if(isFull())
    {
        return 0;
    }
    ++top;
    num[top]=n;
    return n;
}
int Stack::pop()
{
    int temp;
    if(isEmpty())
    {
	cout<<"\n Nothing to be eliminate or pop out"<<endl;
        return 0;
    }
    temp=num[top];
    --top;
    cout<<"\n eliminated"<<endl;
    return temp;
}
int Stack::peek()
{
    if(!isEmpty())
    {
	cout<<"\n The top element is "<<num[top]<<endl;
	return num[top];
    }
    else
    {
	cout<<"\n No such element"<<endl;
        return 0;
    }
}
void Stack::displayItems() 
{
   if(top>=0) 
   {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<num[i]<<" ";
      cout<<endl;
   } 
   else
   {
       cout<<"Stack is empty";
   }
}
int main()
{
    Stack s;
    int choice,n,temp;
    do
    {
        cout<<"\n";
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Insert item. "<<endl;
        cout<<"2 - Eliminate. "<<endl;
        cout<<"3 - Display Items."<<endl;
	cout<<"4 - Show the top element."<<endl;
        
        cout<<"Enter your choice : ";
        cin>>choice;
        
        switch(choice)
        {
            case 0: break;
            case 1: 
                   cout<<"Enter item : ";
                   cin>>n;
                   temp= s.push(n);
                   if(temp==0)
                   {
                       cout<<"Empty Stack"<<endl;
                   }
                   else
                   {
                     cout<<temp<<" inserted into stack."<<endl;
                     break;
                   }
            case 2: 
                   temp=s.pop();
                   if(temp==0)
                   {
                      cout<<"Stack empty."<<endl;
                   }
                   break;
            case 3:
                   s.displayItems();
                   break;
	    case 4:
		   s.peek();
		   break;
            default:
                  cout<<"Check the choice."<<endl;
            }
        }while(choice!=0);
    return 0;
}