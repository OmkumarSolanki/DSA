class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // we want to return the index of the floor of the target in the array
        // i.e. we want the value which is less than or equal to
        int n = arr.size();
        int low = 0, mid, high = n-1;
        while(low <= high) {
            mid = low + (high-low)/2;
            if(arr[mid] <= x) {
                // valid
                low = mid + 1;
            } else {
                // arr[mid] > x
                // not valid
                high = mid - 1;
            }
        }
        return high;
    }
};

/**
TC - O(logn)
SC - O(1)
**/
