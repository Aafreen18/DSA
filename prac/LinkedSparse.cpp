#include<iostream>
using namespace std;

// Node class to represent link list
class Node
{
	public:
	int row;
	int col;
	int data;
	Node *next;
};

void createNode(Node **n, int row_index,int col_index, int val){
	Node *temp = *n;
	Node *r;
	
	// If link list is empty 
	if (temp == NULL){
		temp = new Node();
		temp->row = row_index;
		temp->col = col_index;
		temp->data = val;
		temp->next = NULL;
		*n = temp;
	}
	
	// If link list is already created
	// then append newly created node
	else
	{
		while (temp->next != NULL){
            temp = temp->next;
        }
			
		r = new Node();
		r->row = row_index;
		r->col = col_index;
		r->data = val;
		r->next = NULL;
		temp->next = r;
	}
}


void printList(Node *start){
	Node *ptr = start;
	while (ptr != NULL)
	{
		cout <<"("<<ptr->row <<","<< ptr->col<<","<<ptr->data<<")--->";
		ptr = ptr->next;
	}
}

int main(){ 
	int sparseMatrix[4][4] = { { 10 , 0 , 0 , 20 },
							{ 0 , 30 , 0, 0 },
							{ 0 , 0 , 40 ,50 },
							{ 60, 70, 80 , 0 } 
    };
	
	Node *head = NULL;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			// Pass only those values which are non - zero
			if (sparseMatrix[i][j] != 0){
                createNode(&head, i, j,sparseMatrix[i][j]);
            }
				
		}
	}
	printList(head);

	return 0;
}

