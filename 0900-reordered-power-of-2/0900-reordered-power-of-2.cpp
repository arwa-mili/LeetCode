class Solution {
public:
    unordered_map<char, int> countDigits(int num) {
        unordered_map<char, int> freq;
        string s = to_string(num);
        for (char c : s)
            freq[c]++;
        return freq;
    }

    bool reorderedPowerOf2(int n) {
        auto targetFreq = countDigits(n);

        for (int i = 0; i < 31; ++i) {
            int power = 1 << i;
            if (countDigits(power) == targetFreq)
                return true;
        }
        return false;
    }
};