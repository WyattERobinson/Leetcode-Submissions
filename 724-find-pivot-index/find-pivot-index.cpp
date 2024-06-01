class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        int sumLeft[size];
        int sumRight[size];

        // calculate left sum arr
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sumLeft[i] = sum;
            sum += nums[i];
        }

        // calculate right sum arr
        sum = 0;
        for (int i = size - 1; i >= 0; i--) {
            sumRight[i] = sum;
            sum += nums[i];
        }

        // compare arrays
        for (int i = 0; i < size; i++) {
            if (sumLeft[i] == sumRight[i]) {
                return i;
            }
        }

        // No index was found
        return -1;
    }
};