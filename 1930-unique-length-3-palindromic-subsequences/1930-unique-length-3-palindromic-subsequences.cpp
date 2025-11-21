class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int result = 0;

        for (char c = 'a'; c <= 'z'; c++) {
            int left = 0, right = n - 1;

            while (left < n && s[left] != c) left++;

            while (right >= 0 && s[right] != c) right--;

            if (left >= right) continue;

            unordered_set<char> middleChars;
            for (int i = left + 1; i < right; i++) {
                middleChars.insert(s[i]);
            }

            result += middleChars.size();
        }

        return result;
    }
};
