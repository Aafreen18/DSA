#include<iostream>
using namespace std;

class Node{/*user defined data type*/
    public:
    int key;
    int data;
    Node *next;
    Node(){
        key=0;
        data=0;
        next=NULL;
    }
    Node(int k,int d){
        key=k;
        data=d;
    }
};

class SinglyLinkedList{
    public:
    Node *head;
    SinglyLinkedList(){
        head=NULL;
    }
    SinglyLinkedList(Node* n){
        head=n;
    }

    Node* nodeExists(int k){//returntype-a pointer whose data type is Node.
        Node* temp = NULL;
        Node* ptr = head;
        while(ptr!=NULL){
            if(ptr->key==k){
                temp=ptr;
            }
            ptr=ptr->next;
        }
        return temp;
    }

    void appendNode(Node *n){
        if(nodeExists(n->key)!=NULL){
            cout<<"Node already exists with the key value, Append Node with different key value"<<endl;
        }
        else{
            if(head==NULL){
                head=n;
                cout<<"Node Appended"<<endl;
            }
            else{
                Node *ptr =head;
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                }
                ptr->next=n;
                cout<<"Node Appended"<<endl;
            }
        }
    }

    void prependNode(Node *n){
        if(nodeExists(n->key)!=NULL){
            cout<<"Node already exists with the key value, Append Node with different key value"<<endl;
        }
        else{
            n->next=head;
            head=n;
            cout<<"Node prepended"<<endl;
        }
    }

    void insertNode(int k, Node *n){
        Node *ptr=nodeExists(k);
        if(ptr==NULL){
            cout<<"No node exists with the key value"<<endl;
        }
        else{
            if(nodeExists(n->key)!=NULL){
                cout<<"Node already exists with the key value, Append Node with different key value"<<endl;
            }
            else{
                n->next=ptr->next;
                ptr->next=n;
                cout<<"Node inserted"<<endl;
            }
        }
    }

    void deleteNodeByKey(int k){
        if(head==NULL){
            cout<<"SinglyLinkedList is empty,can`t delete"<<endl;
        }
        else if(head->key==k){
            head=head->next;
            cout<<"Node unlinked"<<endl;
        }
        else{
            Node *temp=NULL;
            Node *prevptr=head;
            Node *currentptr=head->next;
            while(currentptr!=NULL){
                if(currentptr->key==k){
                    temp=currentptr;
                    currentptr=NULL;
                }
                else{
                    prevptr=prevptr->next;
                    currentptr=currentptr->next;
                }
            }
            if(temp!=NULL){
                prevptr->next=temp->next;
                cout<<"Node unlinked with key values"<<k<<endl;
            }
            else{
                cout<<"Node doesn`t exist with the key value"<<k<<endl;
            }
        }
    }

    void updateNodeByKey(int k, int d){
        Node *ptr = nodeExists(k);
        if(ptr != NULL) {
            ptr->data = d;
            cout << "Node data updated successfully" << endl;
        } 
        else{
            cout << "Node doesn't exist with the key value " << k << endl;
        }
    }
    
    void printLinkedList(){
        if(head==NULL){
            cout<<"No nodes in singly linked list"<<endl;
        }
        else{
            cout<<endl<<"Singly linked list values:-";
            Node *ptr=head;
            while(ptr!=NULL){
                cout<<"("<<ptr->key<<","<<ptr->data<<")-->";
                ptr=ptr->next;
            }
        }
    }
};

int main(){
    SinglyLinkedList S;
    int option;
    int key1,k1,data1;
    do{
        cout<<"\n\n What operation do you want  to perform? Select option number"<<endl;
        cout<<"1, appendNode()"<<endl;
        cout<<"2, prependNode()"<<endl;
        cout<<"3, insertNode()"<<endl;
        cout<<"4, deleteNode()"<<endl;
        cout<<"5, updateNode()"<<endl;
        cout<<"6, printLinkedList()"<<endl;
        
        cin>>option;
        Node *n1 = new Node();
        switch(option){
            case 0:
            break;
            case 1:cout<<"Append Node opertion \n Enter key and data of the node to be appended"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            S.appendNode(n1);
            break;
            
            case 2:cout<<"Prepend Node opertion \n Enter key and data of the node to be prepended"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            S.prependNode(n1);
            break;
            
            case 3:cout<<"Insert Node after opertion \n Enter key of existing after which this new node"<<endl;
            cin>>k1;
            cout<<"Enter key and data of the new node"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            S.insertNode(k1,n1);
            break;

            case 4:cout<<"Delete the node by key operation \n Enter key of the node to be deleted"<<endl;
            cin>>k1;
            S.deleteNodeByKey(k1);
            break;

            case 5:cout<<"Update the node by key operation \n Enter key & NEW data of the node to be updated"<<endl;
            cin>>k1;
            cin>>data1;
            S.updateNodeByKey(k1,data1);
            break;
            
            case 6:S.printLinkedList(); 
            break;

            default:
            cout<<"Enter proper option operation"<<endl;
            break;
        }
    }while(option!=0);

    return 0;
}
