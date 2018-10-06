#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		// ¶¯Ì¬¹æ»®
		if (s.length() == 0)
		{
			return "";
		}

		char v;
		v = s[0];
		char new_v;
		int len = 1;
		int new_len = 1;
		int size = s.length();
		for (int i = 1; i < size; i++)
		{
			if (v == s[i])
			{
				len++;
				continue;
			}

			if (len >= new_len)
			{
				new_len = len;
				new_v = v;
			}

			len = 0;
			v = s[i];
		}

		string r(new_len, new_v);
		return r;
	}
};

int main(int argc, char **argv)
{
	Solution sln;
	string s = "babad";

	string out = sln.longestPalindrome(s);
	cout << out << endl;

	int a;
	cin >> a;

	return 0;
}