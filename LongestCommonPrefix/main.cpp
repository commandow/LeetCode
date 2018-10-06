#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	struct TrieNode
	{
		TrieNode()
		{
			for (int i = 0; i < 26; i++)
			{
				next[i] = NULL;
			}
		}

		TrieNode *next[26];
	};

	void build_tree(string &str)
	{
		TrieNode *cur = &tree;
		for (int i = 0; i < str.length(); i++)
		{
			TrieNode *node = new TrieNode;
			cur->next[str[i] - 'a'] = node;
			cur = node;
		}
	}

	int find(string &str)
	{
		int len = 0;
		TrieNode *cur = &tree;
		for (int i = 0; i < str.length(); i++)
		{
			if (cur->next[str[i] - 'a'] == NULL)
			{
				break;
			}

			len++;
			cur = cur->next[str[i] - 'a'];
		}

		return len;
	}

	string longestCommonPrefix(vector<string>& strs) {

		if (strs.size() == 0) return "";

		build_tree(strs[0]);

		int len = strs[0].length();
		for (int i = 1; i < strs.size(); i++)
		{
			int ret = find(strs[i]);
			if (ret == 0)
			{
				return "";
			}

			len = (ret < len ? ret : len);
		}

		string out;
		out.append(strs[0], 0, len);

		return out;
	}

	TrieNode tree;
};


int main(int argc, char **argv)
{
	Solution sln;
	vector<string> strs;

	strs.push_back("flower");
	strs.push_back("flow");
	strs.push_back("flight");


	string out = sln.longestCommonPrefix(strs);

	cout << out;

	int a;
	cin >> a;

	return 0;
}