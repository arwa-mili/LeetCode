class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int lastSum = nums[0];
        int i =1;
        int ans =0;
        while(i< nums.size()) {
            lastSum += nums[i];
            nums[i] = lastSum;
            i++;
        }
        for (int i =0;i < nums.size()-1;i++){
            int total = (nums.back()-nums[i]);
            if ( (total - nums[i]) % 2 == 0 ){
                ans++;
            }
        }
        return ans; 
    }
};