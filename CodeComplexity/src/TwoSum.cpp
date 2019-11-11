/*
Given an array of integers, return the two numbers such that they add up to a specific target.

You may assume that each input will have exactly one solution. Return NULL for invalid inputs

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [4, 20]. (Always the first number should be less in final answer)

If target is 5 ,Return [1,4]
If target is 22 ,return [2,20]

Note :
Return_Array[0] should always be less than/equal to Return_Array[1]

Constraints :
len <100000
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .

You need to solve this question in 3 ways.And measure time for each way.

Observations: (Write down what you observed here):

Way 1 :In brute froce it takes N*N complexity.

Way 2 :After sorting and checking for sum its taking N*logN complexity.

Way 3:Using Extra arrays(hash tables) reducing complexity to N.

Conclusion :Since using hash tables may increase the memory consumed but it eventually decreases time complexity.
*/
#include <stdio.h>
#include <stdlib.h>
#include<algorithm>
using namespace std;

/*
Take each element, Sum with all other elements.
Repeat it with all elements.

What is the complexity of this method ? _____n^2_____
*/

int* sumoftwoBF(int *nums, int target, int len){
	if(len<=0)
	return NULL;
	if (nums == NULL)return NULL;
	int *ans = (int *)malloc(sizeof(int) * 2);
	for(int i=0;i<len;i++)
		for(int j=i+1;j<len;j++)
			if ((nums[i] + nums[j]) == target) {
				ans[0] = nums[j] + ((nums[i] - nums[j])&((nums[i] - nums[j]) >> 31));
				ans[1] = nums[i] - ((nums[i] - nums[j])&((nums[i] - nums[j]) >> 31));
				
				//ans[0]=(nums[i]<)
				break;
			}
	return ans;
}

/*
Sort the array first. Preferably using quicksort/mergesort. (nlogn)

Now the array is sorted, Can you do improve the above method.

Hint: 
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11. 

Lets say we added 3+12 first, whats the sum, Its 15 right ? Its greater than 11.So should we next add 
so that total sum will become less. 

What is the complexity of this method ? ____O(n*n)______
*/

int* sumoftwoSortAndSearch(int *nums, int target, int len){
	//Sort the array
	if (len <= 0 || nums == NULL)return NULL;
	sort(nums,nums+len);
	//Do the task
	int *ans = (int *)malloc(sizeof(int) * 2);
	int x=nums[0];
	for (int i = 0;i < len;) {
		for (int j = i + 1;j < len;j++) {
			if (nums[i] == nums[j])j++;
			if ((nums[i] + nums[j]) > target)
			{
				len = ((i > j) ? i : j);
			}
			else if ((nums[i] + nums[j]) == target) {
				ans[0] = nums[i];
				ans[1] = nums[j];
				break;
			}
		}
		x = nums[i];
		while (x == nums[i] && i < len)i++;
	}
	return ans;
}


/*

Array contains only integers from 1-100; Can you use this range restriction and an extra array to 
find 2Sum even more faster

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

If we are at 3, What number we need to tell that 3 is in final answer? 8 right (11-3 = 8). So some how we need to find a way
to know whether 8 is already in the array or not.As of now we dont know that, we will store 3 somewhere
(Which can be accesible in O(1)) and move to next element. 4 is there, we need to know whether array has 7 or not.(11-4 =7)
We dont know that yet, we move on ...we will store 4 somewhere now.

We go on till 7(4th element). We reach here we require 4 (11-7 = 4) .We already know 4 is present in array. (With O(1)).
We immediately return the answer. Think and discuss with your friends.

You are expected to solve this method in O(n)
*/
int* sumoftwoExtraArray(int *nums, int target, int len) {
	//Initialise the array
	if (len <= 0 || nums == NULL)return NULL;
	int pos[10001] = { 0 };
	int neg[10001] = { 0 };
	//Do the task
	for (int i = 0;i < len;i++) {
		if (nums[i] >= 0) {
			pos[nums[i]] = 1;
		}
		else neg[-nums[i]] = 1;
	}
	int *a = (int *)malloc(sizeof(int) * 2);
	int x;
	for (int i = 0;i < len;i++) {
		x = target - nums[i];
		if (x >= 0 && pos[x] == 1) {
			a[0] = (x > nums[i]) ? nums[i] : x;
			a[1] = (x < nums[i]) ? nums[i] : x;
			break;
		}
		else if(neg[-x]==1){
			a[0] = (x > nums[i]) ? nums[i] : x;
			a[1] = (x < nums[i]) ? nums[i] : x;
			break;
		}
	}
	return a;
}


