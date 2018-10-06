#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
	double findKth(vector<int>& nums1, int start_idx1, int end_idx1, vector<int>& nums2, int start_idx2, int end_idx2, int k)
	{
		if (end_idx1 - start_idx1 + 1 > end_idx2 - start_idx2 + 1) 
		{
			return findKth(nums2, start_idx2, end_idx2, nums1, start_idx1, end_idx1, k);
		}

		int size = end_idx1 - start_idx1 + 1;
		if (size == 0)
		{
			return nums2[start_idx2 + k - 1];
		}

		if (k == 1)
		{
			return nums1[start_idx1] > nums2[start_idx2] ? nums2[start_idx2] : nums1[start_idx1];
		}

		int move = (size < k / 2 ? size : k / 2);
		
		if (nums1[start_idx1 + move - 1] < nums2[start_idx2 + k - move - 1])
		{
			start_idx1 += move;

			return findKth(nums1, start_idx1, end_idx1, nums2, start_idx2, end_idx2, k - move);
		}
		else if (nums1[start_idx1 + move - 1] > nums2[start_idx2 + k - move - 1])
		{
			start_idx2 += move;

			return findKth(nums1, start_idx1, end_idx1, nums2, start_idx2, end_idx2, k - move);
		}

		return (double)nums1[start_idx1 + move - 1];
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size_1 = nums1.size();
		int size_2 = nums2.size();
		int total_size = size_1 + size_2;
		int idx1 = 0;
		int idx2 = 0;

		if (total_size & 0x01)
		{
			return findKth(nums1, 0, size_1 - 1, nums2, 0, size_2 - 1, total_size / 2 + 1);
		}
		else
		{
			return (findKth(nums1, 0, size_1 - 1, nums2, 0, size_2 - 1, total_size / 2) +
				findKth(nums1, 0, size_1 - 1, nums2, 0, size_2 - 1, total_size / 2 + 1)) / 2.0;
		}
	}
};

int main(int argc, char **argv)
{
	Solution sln;

	vector<int> array1;
	vector<int> array2;

	array1.push_back(1);
	array1.push_back(2);
	array2.push_back(3);
	array2.push_back(4);
	double b = 2.0;

	double mid = sln.findMedianSortedArrays(array1, array2);

	printf("output %f\n", mid);

	int a;
	cin >> a;

	return 0;
}