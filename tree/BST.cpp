#include<iostream>
#define SPACE 10
using namespace std;

class TreeNode{
    public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(){
        value=0;
        left=NULL;
        right=NULL;
    }

    TreeNode(int v){
        value=v;
        left=NULL;
        right=NULL;
    }
    
};

class BST{
    public:
    TreeNode *root;

    BST(){
        root=NULL;
    }

    bool isEmpty(){
        if(root==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    void insertNode(TreeNode *newNode){
        if(root==NULL){
            root=newNode;
            cout<<"value Inserted as root Node"<<endl;
        }
        else{
            TreeNode *temp=root;
            while(temp!=NULL){
                if(newNode->value==temp->value){
                    cout<<"value already exist, Insert another value"<<endl;
                    return;
                }
                else if(newNode->value<temp->value && temp->left==NULL){
                    temp->left=newNode;
                    cout<<"value Inserted to the left"<<endl;
                    break;
                }
                else if(newNode->value<temp->value){
                    temp=temp->left;
                }
                else if(newNode->value>temp->value && temp->right==NULL){
                    temp->right=newNode;
                    cout<<"value Inserted to the right"<<endl;
                    break;
                }
                else{
                    temp=temp->right;
                }
            }
        }
    }

    TreeNode* insertRecursive(TreeNode *r, TreeNode *newNode){
        if(r==NULL){
            r=newNode;
            return r;
        }

        if(newNode->value<r->value){
            r->left=insertRecursive(r->left,newNode);
        }
        else if(newNode->value>r->value){
            r->right=insertRecursive(r->right,newNode);
        }
        else{
            cout<<"No Duplicate values are allowed"<<endl;
            return r;
        }
        
        return r;
    }

    TreeNode* iterativeSearch(int v){
        if(root==NULL){
            return root;
        }
        else{
            TreeNode *temp=root;
            while(temp!=NULL){
                if(v==temp->value){
                    return temp;
                }
                else if(v<temp->value){
                    temp=temp->left;
                }
                else{
                    temp=temp->right;
                }
            }
        }
    }

    int totalNodeCount(TreeNode *root){
        if(root == NULL){
            return 0;
        }

        int ans = 1 + totalNodeCount(root->left) + totalNodeCount(root->right);
        return ans;
    }

    bool isBst(TreeNode *root,int i ,int nodeCount){
        if(root == NULL){
            return true;
        }

        if(i > nodeCount){
            return false;
        }
        else{
            bool left = isBst(root->left, 2*i+1, nodeCount);
            bool right = isBst(root->left, 2*i+1, nodeCount);
            return left && right;
        }
    }
    
    void print2D(TreeNode *r, int space) {
        if (r == NULL) // Base case
            return;
    
        space += SPACE; // Increase distance between levels

        // Process right child first
        print2D(r->right, space);

        // Print current node after spacing
        cout << endl;
        for (int i = SPACE; i < space; i++) // Print spaces for proper alignment
            cout << " ";
        cout << r->value << "\n";

        // Process left child
        print2D(r->left, space);
    }

    void printPreorder(TreeNode *r){//NLR
        if(r==NULL){
            return ;
        }

        cout<<r->value<<" ";
        printPreorder(r->left);
        printPreorder(r->right);
    }

    void printInorder(TreeNode *r){//LNR
        if(r==NULL){
            return ;
        }

        printInorder(r->left);
        cout<<r->value<<" ";
        printInorder(r->right);
    }

    void printPostorder(TreeNode *r){//LRN
        if(r==NULL){
            return ;
        }

        printPostorder(r->left);
        printPostorder(r->right);
        cout<<r->value<<" ";
    }

    TreeNode* recursiveSearch(TreeNode *r,int v){
        if(r==NULL || r->value==v){
            return r;
        }
        else if(r->value>v){
            recursiveSearch(r->left,v);
        }
        else{
            recursiveSearch(r->right,v);
        }
    }


    int height(TreeNode *r){
        if (r == NULL)
        return -1;
        else {
            /* compute the height of each subtree */
            int lheight = height(r->left);
            int rheight = height(r->right);

            /* use the larger one */
            if (lheight > rheight)
                return (lheight + 1);
            else return (rheight + 1);
        }
    }

    /* Print nodes at a given level */
    void printGivenLevel(TreeNode *r, int level) {
        if (r == NULL)
        return;
        else if (level == 0)
        cout << r -> value << " ";
        else // level > 0  
        {
        printGivenLevel(r -> left, level - 1);
        printGivenLevel(r -> right, level - 1);
        }
    }
    
    void printLevelOrderBFS(TreeNode * r) {
        int h = height(r);
        for (int i = 0; i <= h; i++)
        printGivenLevel(r, i);
    }

    TreeNode* minValueNode(TreeNode *node){
        TreeNode *curr=node;
        while(curr->left!=NULL){
            curr=curr->left;
        }
        return curr;
    }

    TreeNode* deleteNode(TreeNode *r,int v){
        if(r==NULL){
            return r;
        }
        else if(v<r->value){
            r->left=deleteNode(r->left,v);
        }
        else if(v>r->value){
            r->right=deleteNode(r->right,v);
        }
        else{
            if(r->left==NULL){
                TreeNode *temp=r->right;
                delete r;
                return temp;
            }
            else if(r->right==NULL){
                TreeNode *temp=r->left;
                delete r;
                return temp;
            }
            else{
                TreeNode *temp = minValueNode(r->right);
                r->value=temp->value;
                r->right=deleteNode(r->right,temp->value);

            }
        }
        return r;
    }

};

int main(){
    BST obj;
    int option,val;

    do{
        cout<<"\n\n What operation do you want  to perform? Select option number,Enter 0 to EXIT"<<endl;
        cout<<"1, InsertNode()"<<endl;
        cout<<"2, SearchNode()"<<endl;
        cout<<"3, DeleteNode()"<<endl;
        cout<<"4, Print/Traversal BST values()"<<endl;
        cout << "5. Height of Tree" << endl;
        cout<<"0, ExitProgram()"<<endl;
        
        cin>>option;
        TreeNode *newNode= new TreeNode();

        switch(option){
            case 0:
            break;
            case 1:cout<<"Enter a value to insert in BST"<<endl;
            cin>>val;
            newNode->value=val;
            //obj.insertNode(newNode);
            obj.root = obj.insertRecursive(obj.root,newNode);
            cout<<endl;
            break;
            
            case 2:cout<<"Search"<<endl;
            cout<<"Enter a value to search in BST"<<endl;
            cin>>val;
            //newNode=obj.iterativeSearch(val);
            newNode=obj.recursiveSearch(obj.root,val);
            if(newNode!=NULL){
                cout<<"Value found"<<endl;
            }
            else{
                cout<<"Value not found"<<endl;
            }
            break;

            case 3:cout<<"delete"<<endl;
            cout<<"Enter value of TreeNode which you want to delete"<<endl;
            cin>>val;
            newNode=obj.iterativeSearch(val);
            if(newNode!=NULL){
                obj.deleteNode(obj.root,val);
                cout<<"value deleted"<<endl;
            }
            else{
                cout<<"value not found"<<endl;
            }
            break;
            
            case 4:cout<<"Print"<<endl;
            obj.print2D(obj.root, 5);
            cout<<endl;
            cout<<"Print level order BFS"<<endl;
            obj.printLevelOrderBFS(obj.root);
            cout<<endl;
            // cout<<"Preorder: ";
            // obj.printPreorder(obj.root);
            // cout<<endl;
            // cout<<"Inorder: ";
            // obj.printInorder(obj.root);
            // cout<<endl;
            // cout<<"Postorder: ";
            // obj.printPostorder(obj.root);
            // cout<<endl;
            break;
            
            case 5:cout<<"TRE HEIGHT"<<endl;
            cout<<"Height :"<<obj.height(obj.root)<<endl;
            break;
        
            default:cout<<"Enter proper option";
            break;
        }
    }while(option!=0);

    return 0;
}