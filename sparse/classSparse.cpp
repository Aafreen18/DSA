#include <iostream>
using namespace std;

class sparse {
private:
    int mat[4][4];
    int col = 0;
    int **arr = nullptr;

public:
    void matrix() {
        cout << "Enter matrix elements:" << endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin>>mat[i][j];
                if (mat[i][j] != 0) {
                    col++;
                }
            }
        }
    }

    void arrayRep() {
        arr = new int *[3];
        for (int i = 0; i < 3; i++) {
            arr[i] = new int[col];
        }
        int k = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (mat[i][j] != 0) {
                    arr[0][k] = i;
                    arr[1][k] = j;
                    arr[2][k] = mat[i][j];
                    k++;
                }
            }
        }
    }

    void display() {
        cout << "Elements:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < col; j++) {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }

    ~sparse() {
        if (arr != nullptr) {
            for (int i = 0; i < 3; i++) {
                delete[] arr[i];
            }
            delete[] arr;
        }
    }
};

int main() {
    sparse S1;
    S1.matrix();
    S1.arrayRep();
    S1.display();
    return 0;
}
