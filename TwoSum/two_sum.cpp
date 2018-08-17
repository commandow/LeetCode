#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		// 用空间换时间，建hash_map，遍历一遍hash_map，比如：遍历到A，查找一下target-A是否在hash_map中，如果在，则命中成功
		int size = nums.size();
		unordered_map<int, int> hash_map;
		for (int idx = 0; idx < size; idx++)
		{
			hash_map[nums[idx]] = idx;
		}

		vector<int> result;
		for (int idx = 0; idx < size; idx++)
		{
			int other_num = target - nums[idx];
			unordered_map<int, int>::iterator other_iter = hash_map.find(other_num);
			if (other_iter == hash_map.end())
			{
				continue;
			}

			if (other_iter->second != idx)
			{
				result.push_back(idx);
				result.push_back(other_iter->second);

				break;
			}
		}

		return result;
	}
};
