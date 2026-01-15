class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int children = g.size(), cookies = s.size();
        int assigned = 0;
        int i = 0, j = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while( i < children && j < cookies) {
            if( s[j] >= g[i] ) {
                assigned++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return assigned;
    }
};