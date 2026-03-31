class Solution {
public:
  int reverseBits(unsigned int n) {
  int ans = 0;

	// traversing bits of 'n' from the right
for (int i = 0; i < 32 ; ++i){	    
		// bitwise left shift
		// 'ans' by 1
		ans <<= 1;

		// if current bit is '1'
		if (n & 1 == 1)
			ans |= 1;
		// bitwise right shift
		// 'n' by 1
		n >>= 1;

	}

	// required number
	return ans;;
  }

    
};
