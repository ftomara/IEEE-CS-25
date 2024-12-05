#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    vector<int> shops, money;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        shops.push_back(x);
    }
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        money.push_back(x);
    }
    sort(shops.begin(),shops.end());
    vector<int> ans;
    // 1 10 3 11
    //3 6 8 10 11
    for(int i = 0 ; i<q ; i++)
    {
        int left = 0 ;
        int right = n-1;
        int result = 0;
        while(left<=right)
        {
        int mid = left + (right - left) / 2;
            if(money[i]<shops[mid])
            {
                  right=mid-1;
            }
            else if (money[i]>= shops[mid])
            {
                left=mid+1;
                result = mid+1;
            }
        }
        // cout<<"right : "<<right<<endl;
        ans.push_back(result);
    }
    for(int i = 0 ; i<q ; i++)
      cout<<ans[i]<<endl;

    return 0;
}
