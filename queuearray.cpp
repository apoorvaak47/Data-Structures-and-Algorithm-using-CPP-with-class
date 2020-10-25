#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<process.h>
using namespace std;
int size=10;
class Queue
{
	public:
		int q[size];
		int front;
		int rear;
		Queue();
		void enqueue(int);
		int dequeue();
		int isfull();
		int isempty();
		void display();
};
Queue :: Queue()
{
	rear= -1;
	front= 0;
}
void Queue :: enqueue(int item)
{
	rear++;
	q[rear]=item;
}
int Queue :: dequeue()
{
	int x=q[front];
	front++;
	return x;
}
int Queue :: isfull()
{
	if(rear==size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Queue :: isempty()
{
	if(front==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Queue :: display()
{
	for(int i= front;i<rear;i++)
	{
		cout<<q[i]<<",";
	}
}
int main()
{
	Queue Q;
	int a,b;
	do
	{
		cout<<"\n Main Menu : ";
		cout<<"\n 1. Enqueue";
		cout<<"\n 2. Dequeue";
		cout<<"\n 3. Display";
		cout<<"\n 4. Exit";
		cout<<"\n Enter your choice : ";
		cin>>a;
		switch(a)
		{
			case 1 : if(Q.isfull())
				 {
					cout<<"\n Queue is full";
				 }
				 else
				 {
					cout<<"\n Enter the element : ";
					cin>>b;
					Q.enqueue(b);
					cout<<"\n Queue after enqueue operation : ";
					Q.display();
				 }
				 break;
			case 2 : if(Q.isempty())
				 {
					cout<<"\n Queue is empty";
				 }
				 else
				 {
				  	int z;
					z=Q.dequeue();
					cout<<"\nThe dequeued value is : "<<z<<endl;
					cout<<"\nQueue after dequeue operation is : ";
					Q.display();
				 }
				 break;
			case 3 : cout<<"\n Queue is "<<Q.display();
				 break;
			case 4 : cout<<"\n END";
				 exit(0);
				 break;
		}
	}while(a<=4);
	return 0;
} 