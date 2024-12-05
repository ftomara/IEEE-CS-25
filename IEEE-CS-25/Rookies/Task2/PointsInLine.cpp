#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{

    int n, d;
    cin >> n >> d;
    vector<int> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i];
    }
    int groups =0;
    for (int i = 0 , j=2 ; i < n ; i++)
    {
        if(j>=n-1 && j-i ==2)
        {
            break;
            
        }
        if(points[j]-points[i]<=d)
        {
            groups++;
            j++;
        }
    }
    cout<<groups<<endl;
  

    return 0;
}