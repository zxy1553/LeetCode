#include <iostream>
#include <vector>
#include <climits>

using namespace std;



int main(){
   int N,M;
   cin>>N>>M;
   vector<int> attractions(N,0);
   int num=0;

    for(int i=0; i<N; ++i){
        cin>>attractions[i];
    }

    vector<vector<int>> dp(N,vector<int>(N,0));
    int ans=0;
    int left=0, right=1; 
    int sum=attractions[left];
    while (left<right && right<N)
    {
        while(right<N){
            while (sum!=M && right<N)
            {
                sum+=attractions[right++];
            }
            if(sum == M){
                ans++;
                left = right-1;
                sum=attractions[left];
                break;
            }
            left++;
            right= left+1;
            sum = attractions[left];
            
        }
        
    }

    cout<<ans;

}