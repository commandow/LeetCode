#include <iostream>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int m[256] = { 0 }, res = 0, left = 0;
		for (int i = 0; i < (int)s.size(); ++i) {
			if (m[s[i]] == 0 || m[s[i]] < left) {
				res = (res > i - left + 1 ? res : i - left + 1);
			}
			else {
				left = m[s[i]];
			}
			m[s[i]] = i + 1;
		}
		return res;
	}
};

int main(int argc, char **argv)
{
	Solution sln;

	int len = sln.lengthOfLongestSubstring("pwwkew");

	return 0;
}