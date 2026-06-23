class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int x = 0;
        int i = 0;

        while (i < pushed.size() || x < popped.size()) {
            if (st.empty()) {
                st.push(pushed[i]);
                i++;
            } else if (st.top() != popped[x]) {
                if (i < pushed.size()) {
                    st.push(pushed[i]);
                    i++;
                } else {
                    break;
                }
            } else {
                st.pop();
                x++;
            }
        }

        return st.empty();
    }
};