class Solution {
public:
	// reverse characters for s[begin:end)
	void myswap(string&s, int begin, int end) {
		int k = (begin + end) >> 1;
		for (int i = begin; i<k; ++i)
			swap(s[i], s[end - i + begin - 1]);
	}
	void reverseWords(string &s) {
		// remove duplicate blank
		int len = s.length();
		int curn = 0;
		for (int i = 0; i < len; ++i) {
			if (s[i] != ' ')	s[curn++] = s[i];
			else if (curn && s[curn - 1] != ' ')	s[curn++] = ' ';
		}
		if (curn && s[curn - 1] == ' ')	--curn;
		s.resize(curn);
		len = curn;
		// reverse characters in each word
		// the sky is blue => eht yks si uelb
		int vi = 0;
		for (int i = 0; i<len; ++i) {
			if (s[i] == ' ') {
				myswap(s, vi, i);
				vi = i + 1;
			}
		}
		// reverse the last word
		myswap(s, vi, len);
		// reverse all characters in the string
		// eht yks si uelb => blue is sky the
		myswap(s, 0, len);
	}
};