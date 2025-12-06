#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
using namespace std;

// monotonic increasing function = ascending order(top to down) = nse, pse
// monotonic decreasing function = descending order(top to down) = nge, pge

int main() {
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    stack<int> st;

    for (int num : arr) {
        while (!st.empty() && st.top() > num) {
            st.pop();  // maintain increasing order
        }
        st.push(num);
        
        // print current stack content
        stack<int> temp = st;
        vector<int> current;
        while (!temp.empty()) {
            current.push_back(temp.top());
            temp.pop();
        }

        reverse(current.begin(), current.end());
        cout << "After " << num << " → ";
        for (int v : current) cout << v << " ";
        cout << endl;
    }
}
