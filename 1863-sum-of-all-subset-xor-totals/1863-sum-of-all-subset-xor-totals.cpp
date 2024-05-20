class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++){
            int curr_total=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) curr_total^=nums[j];
            }
            sum+=curr_total;
        }
        return sum;
        
        
    }
};