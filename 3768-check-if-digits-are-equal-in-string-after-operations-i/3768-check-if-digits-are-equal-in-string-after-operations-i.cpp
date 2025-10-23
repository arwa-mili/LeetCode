class Solution {
public:
    bool hasSameDigits(string s) {
        string aux = s;
        while (!isFinal(aux)) {
            aux = replaceDigits(aux);
        }
        return isTrue(aux);
    }

private:
    string replaceDigits(const string& s) {
        string aux = "";
        for (size_t i = 0; i + 1 < s.size(); ++i) {
            int sum = (s[i]) + (s[i + 1]);
            aux += to_string(sum % 10); 
        }
        return aux;
    }

    bool isFinal(const string& s) {
        return s.size() == 2;
    }

    bool isTrue(const string& s) {
        return s[0] == s[1];
    }
};