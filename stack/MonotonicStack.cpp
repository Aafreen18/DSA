//Rule of Thumb

//Previous → go left-to-right (because you look back at what’s before you).

//Next → go right-to-left (because you look ahead at what comes after you).

//Smaller → maintain increasing stack (pop while st.top() >= arr[i]).

//Greater → maintain decreasing stack (pop while st.top() <= arr[i]).


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> previousSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n, -1); // default -1 if no smaller element exists
    stack<int> st;          // will store elements in increasing order

    for (int i = 0; i < n; i++) {
        // Pop until we find a smaller element
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        // If stack not empty, top is next smaller
        if (!st.empty()) {
            nse[i] = st.top();
        }
        // Push current element
        st.push(arr[i]);
    }
    return nse;
}

int main() {
    vector<int> arr = {3, 1, 2, 4};
    vector<int> result = previousSmaller(arr);

    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}
