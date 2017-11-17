#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
}*top=NULL,*p;
 
Node* newnode(int x)
{
    p=new Node;
    p->data=x;
    p->next=NULL;
    return(p);
}
 
void push(Node *q)
{
    if(top==NULL)
        top=q;
    else
    {
        q->next=top;
        top=q;
    }
}
 
void pop(){
    if(top==NULL){
        cout<<"Stack is empty!!";
    }
    else{
        cout<<"Deleted element is "<<top->data;
        p=top;
        top=top->next;
        delete(p);
    }
}
 
void showstack()
{
    Node *q;
    q=top;
 
    if(top==NULL){
        cout<<"Stack is empty!!";
    }
    else{
        while(q!=NULL)
        {
            cout<<q->data<<" ";
            q=q->next;
        }        
    }
}
 
int main()
{
    int ch,x;
    char cha;
    Node *nptr;
    cout<<"\n \nPROGRAM TO USE THE CONCEPT OF STACK";
    do 
    {
        cout<<"\n\n1.Push\n2.Pop\n3.Display\n4.Exit";
        cout<<"\nEnter your choice(1-4):";
        cin>>ch;
        
        switch(ch){
            case 1: cout<<"\nEnter data:";
                    cin>>x;
                    nptr=newnode(x);
                    push(nptr);
                    break;
            
            case 2: pop();
                    break;
                    
            case 3: showstack();
                    break;
            
            case 4: exit(0);
            
            default: cout<<"\nWrong choice!!";
        }
    cout<<"\n \nDo you want to continue?(y/n)";
    cin>>cha;
    }
    while(cha=='y' || cha=='Y');
    return 0;
}
