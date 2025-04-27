class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int swl = 0;
        int ans = 0;
        while (swl +2 < nums.size()) {
            if (((float)nums[swl] + (float)nums[swl+2] )==((float)nums[swl+1]/ 2)) {
                ans+=1;
            }
            swl++;
        }
        return ans;
    }
};