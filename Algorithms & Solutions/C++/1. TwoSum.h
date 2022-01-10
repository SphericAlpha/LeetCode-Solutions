// Source : 
// Author : Johannes G. Gustafsson
// Date   : 2022-01-10

/*****************************************************************************************************
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.

 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 * Example 3:
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 * Constraints:
 * 2 <= nums.length <= 104
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 *
 * Only one valid answer exists.
 ******************************************************************************************************/

#pragma once
#include <vector>
#include <algorithm>

class TwoSumSolution
{
public:
	static int* twoSum(std::vector<int> nums, int target)
    {
        int start = 0;
        unsigned int end = nums.size() - 1;
        // the resulting array, which remains 0-valued if
        // no results where found
        int result[] = { 0, 0 };

        // start by sorting the array. We may assume it is sorted, but
        // this solution still only has O(n * log(n)) time complexity (O(n)
        // on already sorted arrays)
        std::sort(nums.begin(), nums.end());

        while(start < end)
        {
	        if(nums[start] + nums[end] == target)
	        {
                result[0] = start;
                result[1] = end;
                break;
	        }
            else if(nums[start] + nums[end] < target)
            {
                start++; 
            }
            else
            {
                end--;
            }
        }

        return result;
    }
};