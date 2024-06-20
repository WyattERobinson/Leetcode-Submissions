/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 0;
        int right = n;
        int mid = right / 2;
        int result = guess(mid);
        while (result != 0) {
            if (result == -1) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
            mid = left + (right - left) / 2;
            result = guess(mid);
        }
        return mid;
    }
};