class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int result = 0;
        int n = s.size();

        for(char c = 'a'; c <= 'z'; c++) {
            int left = s.find(c);
            int right = s.rfind(c);

            if (left != string::npos && right - left > 1) {
                bool used[26] = {false};

                for(int i = left + 1; i < right; i++) {
                    used[s[i] - 'a'] = true;
                }

                for(bool x : used)
                    if(x) result++;
            }
        }

        return result;
    }
};
