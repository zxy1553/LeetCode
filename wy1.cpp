#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool cmp(int& a, int& b){
    return a>b;
}

bool isEnough(int target, vector<int> nums, int index){
    double sum=0.0;
    for(int i=index; i<nums.size(); ++i){
        sum +=  static_cast<double>(1.0/(1 << (target-nums[i])));
        if(sum >= 1.0){
            return true;
        }
    }
    return false;
}

int main(){
    int n,m;
    cin >>n >>m;
    vector<int> materials(n,0);
    vector<int> requests(m,0);

    for(int i=0; i<n; ++i){
        cin>>materials[i];
    }
    for(int i=0; i<m; ++i){
        cin>>requests[i];
    }
    sort(materials.begin(),materials.end(), cmp);
    sort(requests.begin(),requests.end(), cmp);
    
    int maxBills=0, minMaterials=0;
    int mIndex = 0,rIndex=0;
    while(rIndex<m && mIndex<n){
        int flag = false;
        int request = requests[rIndex];
        int tempMateiral=0; double tempRequest=0;
         while(mIndex<n){
            int material = materials[mIndex];
            if(material==request) {
                maxBills++; 
                minMaterials++;
                mIndex++;
                rIndex++;
                break;
            }
            else if(material<request){
                
                if(flag || isEnough(request,materials,mIndex)){
                    flag = true;
                    tempMateiral+=1;
                    tempRequest +=  static_cast<double>(1.0/(1 << (request-material)));
                    if(tempRequest == 1){
                        minMaterials +=tempMateiral;
                        maxBills++;
                        rIndex++;
                        mIndex++;
                        break;
                    }
                    mIndex++;
                    continue;
                }else{
                    rIndex++;
                    break;
                }
            }else{
                mIndex++;
                break;
            }
        }
    }

    cout << (maxBills==m?minMaterials:maxBills);

}