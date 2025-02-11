/*
Remove All Occurrences of a Substring
Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.
A substring is a contiguous sequence of characters in a string.
*/
class Solution {
    public:
        string removeOccurrences(string s, string part) {
            stack<char> st;
            int strLength = s.length();
            int partLength = part.length();

            for (int index = 0; index < strLength; index++) {
                st.push(s[index]);

                if (st.size() >= partLength && checkMatch(st, part, partLength)) {
                    for (int j = 0; j < partLength; j++) {
                        st.pop();
                    }
                }
            }

            string result = "";
            while (!st.empty()) {
                result = st.top() + result;
                st.pop();
            }
            return result;
        }

    private:
        bool checkMatch(stack<char> temp, string& part, int partLength) {
            for (int partIndex = partLength - 1; partIndex >= 0; partIndex--) {
                if (temp.top() != part[partIndex]) {
                    return false;
                }
                temp.pop();
            }
            return true;
        }
    };