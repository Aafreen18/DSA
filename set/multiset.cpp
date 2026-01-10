#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;

/*-------------------------------------------------------
    Custom comparator for pair (2D multiset)
    Sort by first, if equal, sort by second
--------------------------------------------------------*/
struct cmp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const {
        if (a.first == b.first) 
            return a.second < b.second;
        return a.first < b.first;
    }
};

int main() {

    /********************* 1-D MULTISET *********************/
    multiset<int> ms;

    // insert()
    ms.insert(5);
    ms.insert(2);
    ms.insert(3);
    ms.insert(2);   // duplicate allowed
    ms.insert(8);

    cout << "\n1D multiset (ms) elements:\n";
    for (int x : ms) cout << x << " ";
    cout << "\n";

    // count()
    cout << "\nCount of 2 = " << ms.count(2) << "\n";

    // find()
    auto it = ms.find(3);
    if (it != ms.end())
        cout << "Found element = " << *it << "\n";

    // erase(value)
    ms.erase(2);   // removes ALL occurrences of 2
    cout << "\nAfter erase(2):\n";
    for (int x : ms) cout << x << " ";
    cout << "\n";

    // erase(iterator)
    it = ms.find(5);
    if (it != ms.end()) ms.erase(it);
    cout << "\nAfter erase(iterator of 5):\n";
    for (int x : ms) cout << x << " ";
    cout << "\n";

    // lower_bound / upper_bound
    ms.insert(4);
    ms.insert(6);
    ms.insert(6);

    cout << "\nLower_bound(6): " << *ms.lower_bound(6) << "\n";
    cout << "Upper_bound(6): " << *ms.upper_bound(6) << "\n";


    /********************* 2-D MULTISET (pairs) *********************/

    multiset<pair<int,int>, cmp> ms2;

    // insert()
    ms2.insert({2, 50});
    ms2.insert({1, 40});
    ms2.insert({2, 30});
    ms2.insert({1, 20});
    ms2.insert({3, 10});
    ms2.insert({2, 30});     // duplicate allowed

    cout << "\n2D multiset (ms2) elements:\n";
    for (auto &p : ms2) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << "\n";

    // find()
    auto it2 = ms2.find({2, 30});
    if (it2 != ms2.end())
        cout << "Found element = (" << it2->first << ", " << it2->second << ")\n";

    // count()
    cout << "Count of (2,30) = " << ms2.count({2, 30}) << "\n";

    // erase single occurrence
    it2 = ms2.find({2, 30});
    if (it2 != ms2.end())
        ms2.erase(it2);

    cout << "\nAfter erasing one (2,30):\n";
    for (auto &p : ms2)
        cout << "(" << p.first << ", " << p.second << ") ";
    cout << "\n";

    // lower_bound upper_bound
    auto lb = ms2.lower_bound({2, 30});
    cout << "\nlower_bound({2,30}) → ";
    if (lb != ms2.end())
        cout << "(" << lb->first << "," << lb->second << ")";
    else
        cout << "end";

    cout << "\nupper_bound({2,30}) → ";
    auto ub = ms2.upper_bound({2, 30});
    if (ub != ms2.end())
        cout << "(" << ub->first << "," << ub->second << ")";
    else
        cout << "end";

    cout << "\n";


    return 0;
}
