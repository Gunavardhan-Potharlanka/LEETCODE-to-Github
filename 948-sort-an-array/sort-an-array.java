class Solution {
    public static void merge(int[] arr, int low, int mid, int high) {
        int[] arr2 = new int[arr.length];
        int ind = 0, i = low, j = mid + 1;
        while(i < (mid + 1) && j < (high + 1)) {
            if(arr[i] < arr[j]) arr2[ind++] = arr[i++];
            else arr2[ind++] = arr[j++];
        }
        while(i < (mid + 1)) {
            arr2[ind++] = arr[i++];
        }
        while(j < (high + 1)) {
            arr2[ind++] = arr[j++];
        }
        for(int k = low ; k < (high + 1) ; k++) arr[k] = arr2[k - low];
    }
    public static void mergeSort(int st, int end, int[] nums) {
        if(st < end) {
            int mid = (st + end) / 2;
            mergeSort(st, mid, nums);
            mergeSort(mid + 1, end, nums);
            merge(nums, st, mid, end);
        }
    }
    public int[] sortArray(int[] nums) {
        mergeSort(0, nums.length - 1, nums);
        return nums;
    }
}