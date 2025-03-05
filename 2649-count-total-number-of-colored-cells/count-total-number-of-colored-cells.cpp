class Solution {
public:
    long long coloredCells(int n) {
        long long newN=n;
        long long ans=  1+(4*(newN*(newN-1)/2));
        return ans;
    }
};