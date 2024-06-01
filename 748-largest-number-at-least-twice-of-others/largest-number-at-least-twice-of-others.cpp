class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = 0;
        int max_in = 0;

        // Find max and its index
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
                max_in = i;
            }
        }

        // Check that all other numbers doubled are less than or equal to max
        for (int i = 0; i < nums.size(); i++) {
            if (i != max_in && max < nums[i] * 2) {
                return -1;
            }
        }

        return max_in;
    }
};