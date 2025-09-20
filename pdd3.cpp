#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int N,T;
    cin >>N>>T;

    vector<vector<int>> levels(N,vector<int>(2));
    for(int i=0; i<N; ++i){
       cin>> levels[i][0]>>levels[i][1];
    }
    int left=0,right=0;
    int maxHard=INT_MAX;
    int tempHard=INT_MIN;
    int score=0;

    while(right<N){
        if(score<T){
            score+=levels[right][0];
            tempHard = max(tempHard,levels[right][1]);
            if(right!=N){
                right++;
            }
        }
        if(score>=T){
            maxHard = min(maxHard,tempHard);
            while(score>=T && left<right){
                score-=levels[left++][0];
            }
            tempHard = INT_MIN;
            for(int i=left; i<right; ++i){
                tempHard = max(tempHard,levels[i][1]);
            }
        }

    }

    cout << maxHard;

}