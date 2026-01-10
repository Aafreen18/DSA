#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;

// Custom comparator for pair
struct cmp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};

int main() {

    /*************** 1) lower & upper on vector ***************/
    cout << "\n==== VECTOR DEMO ====\n";

    vector<int> v = {1,2,2,4,5,7,7,9};
    sort(v.begin(), v.end()); // needed for vector

    int x = 2;
    auto lbv = lower_bound(v.begin(), v.end(), x);
    auto ubv = upper_bound(v.begin(), v.end(), x);

    cout << "vector: ";
    for(int i:v) cout<<i<<" ";
    cout<<"\n";

    cout << "lower_bound(" << x << ") -> index : "
         << (lbv - v.begin()) << " value: " << *lbv << "\n";

    cout << "upper_bound(" << x << ") -> index : "
         << (ubv - v.begin()) << " value: " << *ubv << "\n";


    /*************** 2) lower & upper on set ***************/
    cout << "\n==== SET DEMO ====\n";

    set<int> st = {1, 4, 4, 5, 8};  // duplicates ignored
    int y = 4;

    auto lbs = st.lower_bound(y);
    auto ubs = st.upper_bound(y);

    cout << "set: ";
    for(int i:st) cout<<i<<" ";
    cout<<"\n";

    cout << "lower_bound(" << y << ") -> " << *lbs << "\n";
    cout << "upper_bound(" << y << ") -> " << *ubs << "\n";


    /*************** 3) lower & upper on multiset ***************/
    cout << "\n==== MULTISET DEMO ====\n";

    multiset<int> ms = {1,2,2,2,3,5,5,7};
    int z = 2;

    auto lbm = ms.lower_bound(z);
    auto ubm = ms.upper_bound(z);

    cout << "multiset: ";
    for(int i:ms) cout<<i<<" ";
    cout<<"\n";

    cout << "lower_bound(" << z << ") -> " << *lbm << "\n";
    cout << "upper_bound(" << z << ") -> " << *ubm << "\n";

    cout << "Elements equal to " << z << ": ";
    for(auto it = lbm; it != ubm; it++)
        cout << *it << " ";
    cout << "\n";


    /*************** 4) Using lower & upper to erase duplicates ***************/
    cout << "\n==== ERASE RANGE IN MULTISET ====\n";
    multiset<int> ms2 = {1,2,2,2,3,4};

    auto lb2 = ms2.lower_bound(2);
    auto ub2 = ms2.upper_bound(2);

    ms2.erase(lb2, ub2);  // removes all 2s

    cout << "After erase 2s: ";
    for(int i:ms2) cout<<i<<" ";
    cout << "\n";


    /*************** 5) 2-D multiset (pair) + custom comparator ***************/
    cout << "\n==== MULTISET OF PAIRS ====\n";

    multiset<pair<int,int>, cmp> mp;
    mp.insert({2,30});
    mp.insert({1,40});
    mp.insert({2,30});
    mp.insert({1,20});
    mp.insert({3,10});
    mp.insert({2,30}); // duplicate

    cout << "multiset(pair): ";
    for(auto &p : mp) cout<<"("<<p.first<<","<<p.second<<") ";
    cout<<"\n";

    pair<int,int> target = {2,30};

    auto lbp = mp.lower_bound(target);
    auto ubp = mp.upper_bound(target);

    cout << "lower_bound(" << target.first << "," << target.second << ") -> ";
    if (lbp != mp.end())
        cout<<"("<<lbp->first<<","<<lbp->second<<")\n";
    else
        cout<<"end()\n";

    cout << "upper_bound(" << target.first << "," << target.second << ") -> ";
    if (ubp != mp.end())
        cout<<"("<<ubp->first<<","<<ubp->second<<")\n";
    else
        cout<<"end()\n";

    cout << "All equal to {2,30}: ";
    for(auto it = lbp; it != ubp; it++)
        cout<<"("<<it->first<<","<<it->second<<") ";
    cout<<"\n";


    return 0;
}
