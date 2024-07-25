class Solution {
public:
// int partitionArray(vector<int> &nums, int low, int high) {
// 	if (low >= high) return -1;
// 	int pivot = low, l = pivot + 1, r = high;
// 	while (l <= r)
// 		if (nums[l] < nums[pivot]) l++;
// 		else if (nums[r] >= nums[pivot]) r--;
// 		else swap(nums[l], nums[r]);
// 	swap(nums[pivot], nums[r]);
// 	return r;
// }
	
// void quickSort(vector<int> &nums, int low, int high) {
// 	if (low >= high) return;
// 	int pivot = partitionArray(nums, low, high);
// 	quickSort(nums, low, pivot);
// 	quickSort(nums, pivot + 1, high);
// }
void outPlaceMerge(vector<int> &nums, int low, int mid, int high) {
	if (low >= high) return;
	int l = low, r = mid + 1, k = 0, size = high - low + 1;
	vector<int> sorted(size, 0);
	while (l <= mid and r <= high)
		sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
	while (l <= mid) 
		sorted[k++] = nums[l++];
	while (r <= high) 
		sorted[k++] = nums[r++];
	for (k = 0; k < size; k++)
		nums[k + low] = sorted[k];
}

void mergeSort(vector<int> &nums, int low, int high) {
	if (low >= high) return;
	int mid = (high - low) / 2 + low;
	mergeSort(nums, low, mid);
	mergeSort(nums, mid + 1, high);
	outPlaceMerge(nums, low, mid, high);
}
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};