#include<iostream>
using namespace std;

int main(){
    int mat[4][4];
    int i,j,k=0,count=0;
    cout<<"Enter matrix elements:-"<<endl;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cin>>mat[i][j];
            if(mat[i][j]!=0){
                count++;
            }
        }
    }

    int arr[3][count];
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(mat[i][j]!=0){
                arr[0][k]=i;
                arr[1][k]=j;
                arr[2][k]=mat[i][j];
                k++;
            }
        }
    }

    cout<<"Elements:-"<<endl;
    for(i=0;i<3;i++){
        for(j=0;j<count;j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
