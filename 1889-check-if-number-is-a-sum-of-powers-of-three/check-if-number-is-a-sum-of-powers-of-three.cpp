class Solution {
public:
    bool checkRecursion(int n,int power){
         if(n==0){
            return true;
        }
        if(pow(3,power)>n){
            return false;
        }
        //include
        bool include= checkRecursion(n-pow(3,power),power+1);
        //not include
        bool notInclude=checkRecursion(n,power+1);

        return include || notInclude;
    }
    bool checkPowersOfThree(int n) {
      return checkRecursion(n,0);
        
    }
};