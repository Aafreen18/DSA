#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    int data;
    Node *next;
    Node *previous;
    Node(){
        key=0;
        data=0;
        next=NULL;
        previous=NULL;
    }
    Node(int k, int d){
        key=k;
        data=d;
    }

};

class doublyLinkedList{
    public:
    Node *head;
    doublyLinkedList(){
        head=NULL;
    }
    doublyLinkedList(Node* n){
        head=n;
    }

    Node* nodeExists(int k){
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
                cout<<"Node Appended"<<endl;;
            }
            else{
                Node *ptr=head;
                while(ptr!=NULL){
                ptr=ptr->next;
                }
                ptr->next=n;
                n->previous=ptr;
                cout<<"Node Appended"<<endl;
            }
        }
    }

    void prependNode(Node *n){
        if(nodeExists(n->key)!=NULL){
            cout<<"Node already exists with the key value, Append Node with different key value"<<endl;
        }
        else{
            if(head==NULL){
                head=n;
                cout<<"Node Prepended"<<endl;;
            }
            else{
                head->previous=n;
                n->next=head;
                n->previous=NULL;
                head=n;
                cout<<"Node Prepended"<<endl;
            }
        }
    }

    void insertNodeAfter(int k,Node *n){
        Node *ptr=nodeExists(k);
        cout<<"No node exists with the key value"<<endl;
        
        if(nodeExists(n->key)!=NULL){
            cout<<"Node already exists with the key value, Append Node with different key value"<<endl;
        }
        else{
            if(ptr->next==NULL){
                ptr->next=n;
                n->previous=ptr;
                cout<<"Node Inserted at the end"<<endl;
            }
            else{
                n->next=ptr->next;
                (ptr->next)->previous=n;
                n->previous=ptr;
                ptr->next=n;
                cout<<"Node Inserted in between";
            }
        }
    }

    void deleteNodeByKey(int k){
        Node *ptr=nodeExists(k);
        if(ptr==NULL){
            cout<<"No node exists with the key value"<<endl;
        }
        else{
            if(head==NULL){
                cout<<"DoublyLinkedList is empty,can`t delete"<<endl;
            }
            else if(head->key==k){
                head=head->next;
                cout<<"Node Unlinked"<<endl;
            }
            else{
                if(ptr->next=NULL){
                    (ptr->previous)->next=NULL;
                    cout<<"Node Deleted at the end"<<endl;
                }
                else{
                    (ptr->previous)->next=ptr->next;
                    (ptr->next)->previous=ptr->previous;
                }
            }
        }
    }

    void updateNodeByKey(int k,int d){
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
            cout<<"No nodes in doubly linked list"<<endl;
        }
        else{
            cout<<endl<<"Doubly linked list values:-";
            Node *ptr=head;
            while(ptr!=NULL){
                cout<<"("<<ptr->key<<","<<ptr->data<<")-->";
                ptr=ptr->next;
            }
        }
    }
};

int main(){
    doublyLinkedList d;
    int option;
    int key1,k1,data1;
    do{
        cout<<"\n\n What operation do you want  to perform? Select option number"<<endl;
        cout<<"1, appendNode()"<<endl;
        cout<<"2, prependNode()"<<endl;
        cout<<"3, insertNodeAfter()"<<endl;
        cout<<"4, deleteNodeByKey()"<<endl;
        cout<<"5, updateNodeByKey()"<<endl;
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
            d.appendNode(n1);
            break;
            
            case 2:cout<<"Prepend Node opertion \n Enter key and data of the node to be prepended"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            d.prependNode(n1);
            break;
            
            case 3:cout<<"Insert Node after opertion \n Enter key of existing after which this new node"<<endl;
            cin>>k1;
            cout<<"Enter key and data of the new node"<<endl;
            cin>>key1;
            cin>>data1;
            n1->key=key1;
            n1->data=data1;
            d.insertNodeAfter(k1,n1);
            break;

            case 4:cout<<"Delete the node by key operation \n Enter key of the node to be deleted"<<endl;
            cin>>k1;
            d.deleteNodeByKey(k1);
            break;

            case 5:cout<<"Update the node by key operation \n Enter key & NEW data of the node to be updated"<<endl;
            cin>>k1;
            cin>>data1;
            d.updateNodeByKey(k1,data1);
            break;
            
            case 6:d.printLinkedList(); 
            break;

            default:
            cout<<"Enter proper option operation"<<endl;
            break;
        }
    }while(option!=0);

    return 0;
}
