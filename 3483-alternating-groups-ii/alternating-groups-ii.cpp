class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int i=0,j=0,count=0;
        int n= colors.size();
        int length=colors[0]==colors[n-1]?n :2*n;
        while(j<length && i<n){
            if(j%n!=0 && colors[j%n]==colors[(j%n)-1]){
                i=j;
            }

            if(j-i+1==k){
                count++;i++;
            }
            j++;
        }
        return count;
    }
};