#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    vector<int>v = {9,8,7,4,4,2,1,1,9,8,8,1,1};
   
    map<int, int> stringMap;

    map<int,int>:: iterator it;
    for (int i=0;i<v.size();i++) {

        // if (stringMap.find(A[i]) == stringMap.end()) {
        //     stringMap[A[i]] = i;
        // }

        stringMap[v[i]]++;
    }

    // Print all unique strings
    cout << "Elements : Frequency " << endl;
    for (auto const& pair : stringMap) {
        cout << pair.first << "          "<< pair.second << endl;
    }

    return 0;
}
