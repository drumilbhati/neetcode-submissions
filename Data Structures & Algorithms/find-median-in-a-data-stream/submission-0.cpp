#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class MedianFinder {
public:
    ordered_set<pair<double, int>> os;
    int t;
    MedianFinder() {
        t = 0;
    }
    
    void addNum(int num) {
        os.insert({num, t++});
    }
    
    double findMedian() {
        int n = os.size();
        if (n & 1) {
            return (os.find_by_order(n / 2)->first);
        } else {
            return ((os.find_by_order(n / 2)->first) + (os.find_by_order(n / 2 - 1)->first)) / 2.0;
        }
    }
};
