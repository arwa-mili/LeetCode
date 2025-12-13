#include <vector>
#include <string>
#include <regex>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        vector<pair<int, string>> valid;

        for (int i = 0; i < code.size(); i++) {
            if (isActive[i] &&
                isValidCode(code[i]) &&
                isValidBusinessLine(businessLine[i])) {

                valid.push_back({order.at(businessLine[i]), code[i]});
            }
        }

        sort(valid.begin(), valid.end(),
             [](const auto& a, const auto& b) {
                 if (a.first != b.first)
                     return a.first < b.first;
                 return a.second < b.second;
             });

        vector<string> res;
        for (auto& p : valid) {
            res.push_back(p.second);
        }

        return res;
    }

private:
    static const regex pattern;
    static const unordered_map<string, int> order;

    bool isValidCode(const string& c) {
        return !c.empty() && regex_match(c, pattern);
    }

    bool isValidBusinessLine(const string& b) {
        return order.count(b) > 0;
    }
};

const regex Solution::pattern("^[A-Za-z0-9_]+$");

const unordered_map<string, int> Solution::order = {
    {"electronics", 0},
    {"grocery", 1},
    {"pharmacy", 2},
    {"restaurant", 3}
};
