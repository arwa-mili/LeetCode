class Solution {
public:
    long findNumbers(vector<int>& nums) {
        long ans = 0;
        multiset<long> sorted(nums.begin(), nums.end());

        long maxVal = *sorted.rbegin();
        long length = to_string(maxVal).size();

        for (int i = 0; i < length; i++) {
            long low = pow(10, i);
            long high = pow(10, i + 1);

            auto lower = sorted.lower_bound(low);
            auto upper = sorted.lower_bound(high);

            long count = distance(lower, upper);
            if (to_string(low).size() % 2 == 0) {
                ans += count;
            }
        }

        return ans;
    }
};