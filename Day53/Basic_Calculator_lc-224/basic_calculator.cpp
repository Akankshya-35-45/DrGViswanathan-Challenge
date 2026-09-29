class Solution {
public:
    int calculate(string s) {
        long long result = 0;
        long long number = 0;
        int sign = 1;
        stack<pair<long long, int>> st;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
            }
            else if (s[i] == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            }
            else if (s[i] == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            }
            else if (s[i] == '(') {
                st.push({result, sign});
                result = 0;
                sign = 1;
            }

            else if (s[i] == ')') {
                result += sign * number;
                number = 0;
                int previousSign = st.top().second;
                long long previousResult = st.top().first;
                st.pop();
                result = previousResult + previousSign * result;
            }
        }
        result += sign * number;
        return result;
    }
};
