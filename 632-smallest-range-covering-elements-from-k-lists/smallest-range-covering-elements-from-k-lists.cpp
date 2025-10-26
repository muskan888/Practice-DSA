class Solution {
public:
    struct info{
        int value;
        int row;
        int col;

        info(int val, int r, int c){
            value=val;
            row=r;
            col=c;
        }
    };
    struct comp{
        bool operator()(info*a , info* b) const{
            return a->value>b->value;
        }
    };
   
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int range=INT_MAX;
        
        priority_queue<info*, vector<info*>,comp>minHeap;
        int start=-1, end=-1;
        for(int i=0;i<nums.size();i++){

            mini=min(mini,nums[i][0]);
            maxi=max(maxi,nums[i][0]);
            range=maxi-mini; //range till we are processing the first col
            info* newNode= new info(nums[i][0],i,0);
            minHeap.push(newNode);
            start=mini;
            end=maxi;
        }
        while(!minHeap.empty()){

           info* curr= minHeap.top();
           mini=curr->value;

           if(maxi-mini<range){
            //if new range is less than prev range, we change the ans
            start=mini;
            end=maxi;
            range=maxi-mini;
           }
           minHeap.pop();
           int val=curr->value;
            int row=curr->row;
            int col=curr->col;
            if(col+1>=nums[row].size()){
                break;
            }
            
            info * newInfo=new info(nums[row][col+1],row,col+1);
            maxi=max(maxi,newInfo->value);
            minHeap.push(newInfo);

        }
        return {start,end};
    }
};