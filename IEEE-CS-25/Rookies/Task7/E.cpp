#include <iostream>
#include <cmath>

using namespace std;

long long findMinCost(long long n) {
    if (n == 1) return 0;
    
    long long left = 0, right = 1e18;
    long long result = 0;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long maxChips = (mid + 1) * (mid + 1);
        
        if (maxChips >= n) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        cout << findMinCost(n) << endl;
    }
    
    return 0;
}