class Solution {
public:
    int romanToInt(string s) {
        map<char, int> nums;
        nums['I'] = 1;
        nums['V'] = 5;
        nums['X'] = 10;
        nums['L'] = 50;
        nums['C'] = 100;
        nums['D'] = 500;
        nums['M'] = 1000;

        int size = s.size();
        int result = 0;

        for (int i = 0; i < size; i++) {
            // Oh hell nah this should be different (but it works :D)
            if ((s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
                (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
                (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))) {
                result += nums[s[i + 1]] - nums[s[i]];
                i++;
            } else {
                result += nums[s[i]];
            }
        }
        return result;
    }
};