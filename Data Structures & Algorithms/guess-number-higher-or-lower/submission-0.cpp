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
    int left = 1;
    int right = n;

    while (left <= right) {
      int my_guess = (left + right) / 2;
      int result = guess(my_guess);
      if (result == 0) {
        return my_guess;
      } else if (result == -1) {
        right = my_guess - 1;
      } else {
        left = my_guess + 1;
      }
    }

    return -1;
  }
};