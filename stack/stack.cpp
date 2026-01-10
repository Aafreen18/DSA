#include<iostream>
#include<string>
using namespace std;

class Stack{
    private:
    int top;
    int stk[5];

    public:
    Stack(){
        top=-1;
        for(int i=0;i<5;i++){
            stk[i]=0;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if(top==4){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int item){
        if(isFull()){
            cout<<"STACK OVERFLOW"<<endl;
        }
        else{
            top++;
            stk[top]=item;
        }
    }

    int pop(){
        if(isEmpty()){
            cout<<"STACK UNDERFLOW"<<endl;
            return 0;
        }
        else{
            int popVal=stk[top];
            stk[top]=0;
            top--;
            return popVal;
        }
    }

    int peek(int idx){//print the element having index-idx
        if(isEmpty()){
            cout<<"STACK UNDERFLOW"<<endl;
            return 0;
        }
        else{
            return stk[idx];
        }
    }

    void update(int idx,int val){
        stk[idx]=val;
        cout<<"Stack is updated"<<endl;
    }
};

int main(){
    Stack s1;
    int option,idx,value;
    
    do{
        cout<<"\n\n What operation do you want  to perform? Select option number"<<endl;
        cout<<"1, push()"<<endl;
        cout<<"2, pop()"<<endl;
        cout<<"3, isEmpty()"<<endl;
        cout<<"4, isFull()"<<endl;
        cout<<"5, peek()"<<endl;
        cout<<"6, update()"<<endl;
        
        cin>>option;
        switch(option){
            case 0:
            break;
            case 1:cout<<"Enter an item to push in the stack"<<endl;
            cin>>value;
            s1.push(value);
            break;
            
            case 2:cout<<"Popped value="<<s1.pop()<<endl;
            break;
            
            case 3:
            if(s1.isEmpty()){
                cout<<"Stack is empty"<<endl;
            }
            else{
                cout<<"stack is not empty"<<endl;
            }
            break;

            case 4:
            if(s1.isFull()){
                cout<<"Stack is Full"<<endl;
            }
            else{
                cout<<"stack is not Full"<<endl;
            }
            break;

            case 5:cout<<"Enter index of the item which you want to peek"<<endl;
            cin>>idx;
            cout<<"Peaked value="<<s1.pop()<<endl;
            break;
            
            case 6:cout<<"Enter index of the item which you want to update"<<endl;
            cin>>idx;
            cout<<"Enter updated value:"<<endl;
            cin>>value;
            s1.update(idx,value);
            break;

            default:cout<<"Enter proper option";
            break;
        }
    }while(option!=0);

    return 0;
}