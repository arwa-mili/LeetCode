class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> setJewels(jewels.begin(), jewels.end());
        int ans = 0;

        for (char s : stones) {
            if (setJewels.count(s)) ans++;
        }

        return ans;
    }
};