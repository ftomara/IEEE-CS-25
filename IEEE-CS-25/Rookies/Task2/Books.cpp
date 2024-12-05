#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t; 
    cin >> n >> t;

    vector<int> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    int start = 0, end = 0;
    int currT = 0, maxB = 0;

    while (end < n) {
        currT += books[end]; 

        while (currT > t) {
            currT -= books[start];
            start++;
        }

        maxB = max(maxB, end - start + 1);

        end++;
    }

    cout << maxB << endl;

    return 0;
}
