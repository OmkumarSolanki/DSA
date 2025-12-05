class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // Lower Bound means first value which is greater than or equal to
        // we need to return the index
        int n = arr.size();
        int low = 0, mid, high = n-1;
        int index = n; // if we did not find any value - return the last index + 1
        while(low <= high) {
            mid = low + (high-low)/2;
            if(arr[mid] >= target) {
                // valid
                high = mid - 1;
                index = mid;
            } else {
                // arr[mid] < target
                // not valid
                // need to increase the mid
                low = mid + 1;
            }
        }
        return low;
        // We can also return low
        // arr - 2 3 7 10 11 11 25 target - 100
        // l = 6 h = 6 
        // l = mid + 1 = 7
    }
};
