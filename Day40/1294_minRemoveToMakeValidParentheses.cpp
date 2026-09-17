class Solution {
public:

    string minRemoveToMakeValid(string s) {

        string temp;
        int balance = 0;

        // First pass: remove invalid ')'
        for (char c : s) {

            if (c == '(') {
                balance++;
                temp += c;
            }

            else if (c == ')') {

                if (balance > 0) {
                    balance--;
                    temp += c;
                }
            }

            else {
                temp += c;
            }
        }

        // Second pass: remove extra '('
        string ans;
        int openToRemove = balance;

        for (int i = temp.length() - 1; i >= 0; i--) {

            if (temp[i] == '(' && openToRemove > 0) {
                openToRemove--;
            }
            else {
                ans += temp[i];
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
