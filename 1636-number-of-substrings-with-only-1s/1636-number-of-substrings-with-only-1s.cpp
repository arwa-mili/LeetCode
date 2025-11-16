class Solution {
public:
    static const long long MOD = 1'000'000'007;

    long long numberOfSubs(long long n) {
        return (n % MOD) * ((n + 1) % MOD) % MOD * 500000004 % MOD;  
    }

    int numSub(string s) {
        long long res = 0;
        long long count = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                count++;
            } else {
                res = (res + numberOfSubs(count)) % MOD;
                count = 0;
            }
        }

        res = (res + numberOfSubs(count)) % MOD;

        return (int)res;
    }
};
