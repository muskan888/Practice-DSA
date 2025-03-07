class Solution {
public:
    bool checkPrime(int num){
        if(num==1){
            return false;
        }
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>ans;
        for(int i=left;i<=right;i++){
            if(checkPrime(i)){
                ans.push_back(i);
            }
        }
        if(ans.size()==0 || ans.size()==1){
            return {-1,-1};
        }
        int first=ans[0];
        int second=ans[1];
        int i=1;
        int mini=second-first;
        cout<<mini<<endl;
        while(i<ans.size()-1){
            if(ans[i+1]-ans[i]<mini){
                first=ans[i];
                second=ans[i+1];
                mini=second-first;
            }
            i++;
        }
       
        return {first,second};
    }
};