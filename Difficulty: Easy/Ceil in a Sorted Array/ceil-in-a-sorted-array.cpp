// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // we want to return the index of the Ceil of the target in the array
        // i.e. we want the value which is greater than or equal to
        int n = arr.size();
        int low = 0, mid, high = n-1;
        while(low <= high) {
            mid = low + (high-low)/2;
            if(arr[mid] >= x) {
                // valid
                high = mid - 1;
            } else {
                // arr[mid] < x
                // not valid
                low = mid + 1;
            }
        }
        if(low == n)
            return -1;
        return low;
    }
};