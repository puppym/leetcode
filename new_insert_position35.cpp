/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0
*/
/*
解题思路：常规的二分查找退出while循环的值就是一个数要插入的位置，注意在分析二分查找时，注意left和right值的实际意义
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	if(0 != nums.size()){
    		return binary_search(nums, 0, nums.size()-1, target);
    	}
    	return 0;
    }

    int binary_search(vector<int>& nums, int left, int right, int target){
    	int mid  = 0;
    	while(left <= right){
    		mid = (left+right)/2;
    		if(target == nums[mid]){
    			return mid;
    		//两种边界情况  不考虑等号的情况
    		}else if(target < nums[left]){
    			return left;
    		}else if(target > nums[right]){
    			return right+1;
    		}else if(target < nums[mid] && left == right){
    			return mid;
    		}else if(target > nums[mid] && left == right){
    			return mid+1;
    		}else if(target < nums[mid]){
    			right = mid-1;
    		}else{
    			left = mid+1;
    		}
    	}
    	//
    }
};

//没有明白二分查找中left 和 right 的实际意义
class Solution{
public:
	int searchInsert(vector<int>& nums, int target){
		int right = nums.size()-1;
		int left = 0;
		int mid = 0;
		while(left <= right){
			mid = (left+right)/2;
			if(target == nums[mid]){
				return mid;
			}else if(target < nums[mid]){
				right = mid-1;
			}else{
				left = mid+1;
			}
		}
		return left;
	}
};

