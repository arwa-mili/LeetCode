#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        multiset<int> window;

        for (int i = 0; i < nums.size(); ++i) {
            // Insert the new element into the window
            window.insert(nums[i]);

            // If window size exceeds k, remove the leftmost element
            if (i >= k) {
                window.erase(window.find(nums[i - k]));
            }

            // Once the window reaches size k, record the maximum
            if (i >= k - 1) {
                result.push_back(*window.rbegin()); // Max is the last element
            }
        }

        return result;
    }
};
