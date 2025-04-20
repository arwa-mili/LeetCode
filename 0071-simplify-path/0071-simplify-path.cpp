class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.length(), i = 0;
        while (i < n) {
            string temp = "";
            while (i < n && path[i] == '/') i++;
            while (i < n && path[i] != '/') temp += path[i++];
            if (temp == "..") {
                if (!st.empty()) st.pop();
            } else if (!temp.empty() && temp != ".") {
                st.push(temp);
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans.empty() ? "/" : ans;
    }
};