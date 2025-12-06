#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    //creation of map<key, value>
    unordered_map<string ,int>m;

    //making pairs
    pair<string, int> p1 = make_pair("babbar", 3);
    pair<string, int> p2("love", 2);

    //insertion of pairs in the map
    m.insert(p1);
    m.insert(p2);

    //making pairs and doing insertion simultaneously
    m["mera"] = 1;
    m["mera"] = 2;//updation will happen 

    cout<<m["love"]<<endl;
    cout<<m.at("babbar")<<endl;

    cout<<m["unkownkey"]<<endl;//it will create a key with value 0.

    //size
    cout<<m.size()<<endl;

    //check presence if it is present, it`ll return 1, otherwise 0.
    cout<<m.count("babbar")<<endl;
    cout<<m.count("bro")<<endl;

    //erase
    m.erase("love");
    cout<<m.size()<<endl;
    

    //traversing

    //1st method for index
    //  for (auto& elem : m) {
    //     cout << elem.first << " : " << elem.second << endl;
    // }

    // //2nd method iterator
    // for (auto it = m.begin(); it != m.end(); ++it) {
    //     cout << it->first << " : " << it->second << endl;
    // }
    
    cout<<"Another way"<<endl;
    unordered_map<string, int> :: iterator it = m.begin();

    while(it != m.end()){
        cout << it->first << " : " << it->second << endl;
        it++;
    }

    return 0;
}