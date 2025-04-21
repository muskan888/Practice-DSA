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

        return max(0L,((upper-lower)-(maxPrefix-minPrefix)+1));


    }
};


//     bool check(int ele,vector<int>&differences,int lower,int upper){
//         for(int i=0;i<differences.size();i++){
//             ele=ele+differences[i];
//             if(ele<lower || ele>upper){
//                 return false;
//             }
//         }
//         return true;
//     }
//     int numberOfArrays(vector<int>& differences, int lower, int upper) {
//         //binary search
//         //find lowest possible value
//         int start=lower;
//         int end=upper;
//         int lowest=0;
//         int mid=start+(end-start)/2;

//         while(start<=end){
//             cout<<start<<" "<<mid<<" "<< end<<endl;
//             if(check(mid,differences,lower,upper)){
//                 end=mid-1;
//                 lowest=mid;
//             }
//             else{
//                 start=mid+1;
//             }
//             mid=start+(end-start)/2;
//         }
//         //find largest possible value
//         int largest=0;
//          start=lowest;
//          end=upper;
//          mid=start+(end-start)/2;
//         while(start<=end){
//             if(check(mid,differences,lower,upper)){
//                 start=mid+1;
//                 largest=mid;
//             }
//             else{
//                 end=mid-1;
//             }
//               mid=start+(end-start)/2;
//         }
//         cout<<lowest<<" "<<largest;
//         if(lowest==0 && largest==0){
//             return 0;
//         }
//           return largest-lowest+1;
//     }
// };