class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long minPrefix=0;
        long maxPrefix=0;
        long sum=0;
        for(int i=0;i<differences.size();i++){
            sum+=differences[i];
            minPrefix=min(minPrefix,sum);
            maxPrefix=max(maxPrefix,sum);

        }
        //treat 0 as long
        return max(0L,((upper-lower)-(maxPrefix-minPrefix)+1));


    }
};


