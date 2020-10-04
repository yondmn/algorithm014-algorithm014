class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
      int result = 0, power = 31;
      while (n != 0) {
          result += (n & 1) << power;
          n = n >> 1;
          power -= 1;
      } 

      return result;
  }
};
