/*
Here you will compare 2 searching algorithms.

LinearSearch and BinarySearch

Question :
Given an Array and its length and a key element, return the index (Where key is found) if key is found in array
or -1 if key is not found.

Sample Input : 
[1,2,3,4,5] Key : 4, Returns 3
[0,49,22] Key : 212, Returns -1

Observations: (Write down what you observed here, Run for various variations):

Linear Search:time complexity is O(n).

Binary Search :time complexity is O(log(n)).

Conclusion :binary search is more optimal compared to linear search.
*/

int linearSearch(int *arr, int len, int key) {
	for (int i = 0;i < len;i++)
		if (arr[i] == key)return i;
	return -1;
}

int bsUtil(int *arr, int f, int l, int key) {
	if (f > l)return -1;
	int mid = (f + l) / 2;
	if ((arr[mid] == key))return mid;
	if (arr[mid] < key) return bsUtil(arr, mid + 1, l, key);
	return bsUtil(arr, f , mid - 1, key);
}
int binarySearch(int *arr, int len, int key) {
	//Use this function as wrapper function,if you are implementing bs recursively.

	return bsUtil(arr,0,len,key);
}