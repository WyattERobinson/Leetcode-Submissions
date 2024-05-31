class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last_in = digits.size() - 1;
        do {
            if (last_in == -1) {
                digits.insert(digits.begin(), 1);
            }
            else {
                digits[last_in] = (digits[last_in] + 1) % 10;
                last_in--;
            }
        } while (digits[last_in + 1] == 0 && last_in >= -1);
        return digits;
    }
};