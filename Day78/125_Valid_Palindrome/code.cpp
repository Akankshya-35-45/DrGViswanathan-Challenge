
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters on the left
            while (left < right &&
                   !isalnum(static_cast<unsigned char>(s[left]))) {
                left++;
            }

            // Skip non-alphanumeric characters on the right
            while (left < right &&
                   !isalnum(static_cast<unsigned char>(s[right]))) {
                right--;
            }

            // Compare characters without considering case
            if (tolower(static_cast<unsigned char>(s[left])) !=
                tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            }

            // Move both pointers inward
            left++;
            right--;
        }

        return true;
    }
};
