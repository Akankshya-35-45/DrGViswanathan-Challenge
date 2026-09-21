class Solution {
public:
    int findComplement(int num) {
        int mask = 0;
        int temp = num;

        // Create a mask containing 1s
        while (temp > 0) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        // XOR flips the required bits
        return num ^ mask;
    }
};
