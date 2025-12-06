#include<iostream>
using namespace std;

class   CircularQueue{
    private:
    int front;
    int rear;
    int arr[5];

    public:
    CircularQueue(){
        front=-1;
        rear=-1;
        for(int i=0;i<5;i++){
            arr[i]=0;
        }
    }

    bool isEmpty(){
        if(front==-1 && rear==-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if((rear+1)%5==front){
            return true;
        }
        else{
            return false;
        }
    }

    void Enqueue(int Val){
        if(isFull()){
            cout<<"Queue is full"<<endl;
            return;
        }
        else if(isEmpty()){
            front=0;
            rear=0;
            arr[rear]=Val;
        }
        else{
            rear=(rear+1)%5;
            arr[rear]=Val;
        }
        
    }

    int Dequeue(){
        int x;
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        else if(front==rear){
            x=arr[front];
            arr[front]=0;
            front=-1;
            rear=-1;
            return x;
        }
        else{
            x=arr[front];
            arr[front]=0;
            front=(front+1)%5;
            return x;
        }
    }
    void display(){
        cout<<"All values in the queue are:- "<<endl;
        for(int i=0;i<5;i++){
            cout<<arr[i]<<endl;;
        }
    }
};

int main(){
    CircularQueue q1;
    int option,Val;
    do{
        cout<<"\n\n What operation do you want  to perform? Select option number"<<endl;
        cout<<"1, Enqueue()"<<endl;
        cout<<"2, Dequeue()"<<endl;
        cout<<"3, isEmpty()"<<endl;
        cout<<"4, isFull()"<<endl;
        cout<<"5, display()"<<endl;
        
        cin>>option;
        switch(option){
            case 0:
            break;
            case 1:
            cout<<"enter an element"<<endl;
            cin>>Val;
            q1.Enqueue(Val);
            break;
            case 2:
            cout<<"Deleted value="<<q1.Dequeue()<<endl;
            break;
            case 3:
            if(q1.isEmpty()){
                cout<<"queue is empty"<<endl;
            }
            else{
                cout<<"queue is not empty"<<endl;
            }
            break;
            case 4:
            if(q1.isFull()){
                cout<<"queue is full"<<endl;
            }
            else{
                cout<<"queue is not full"<<endl;
            }
            break;
            case 5:
            cout<<"display function is called"<<endl;
            q1.display();
            break;
            default:
            cout<<"wrong operation"<<endl;
            break;
        }
    }while(option!=0);

    return 0;
}