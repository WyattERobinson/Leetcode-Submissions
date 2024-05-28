class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { return false; }

        int digits = 0;
        int tmp = x;
        while (tmp >= 1) {
            digits++;
            tmp /= 10;
        }
        for(int i = 0; i < digits / 2; i++) {
            if (getDigit(x, i) != getDigit(x, digits - i - 1)) {
                return false;
            }
        }
        return true;
    }

    int getDigit(int x, int index) {
        return (x / (int)pow(10, index)) % 10;
    }
};