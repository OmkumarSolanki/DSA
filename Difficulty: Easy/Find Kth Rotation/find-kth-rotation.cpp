class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // The array is right rotated - distinct
        // 1 2 3 4 5
        // 5 1 2 3 4 is rotated 1 times
        // 4 5 1 2 3 is rotated 2 times
        // the index of the min element in the arr is the answer
        int n = arr.size();
        int low = 0, mid, high = n - 1;
        int minEle = arr[0], minIndex = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;

            if (arr[low] <= arr[mid]) {
                // left one is sorted
                // consider the smallest one and move to other part
                if(minEle > arr[low]) {
                    minEle = arr[low];
                    minIndex = low;
                }
                low = mid + 1;
            } else {
                // arr[mid] <= arr[high]
                // right one is sorted
                if(minEle > arr[mid]) {
                    minEle = arr[mid];
                    minIndex = mid;
                }
                high = mid - 1;
            }
        }
        return minIndex;
    }
};
