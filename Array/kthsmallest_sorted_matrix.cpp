

/*
 378. Kth Smallest Element in a Sorted Matrix
*  Approach
*  ==========
    The goal here is to solve it lesser than O(n^2) time and constant time.
    For this we can use the sorted properties of rows and columns.
    We can use Binary Search!!

    We know that matrix[0][0] is smalest and matrix [n-1][n-1] is the largest element.
    We can use binary search in between these two. Let low = first elem high = last elem
    mid = low+(high-low)/2. Now once we have the mid count the elements in each row which are <=mid.

    For this we can use linear traversal or upper_bound(which logN), so preferably upperbound.
    Once we have the count (elements <=mid) this count represents that there count no. of elements which comes before mid.
    E.g let say our mid is 10 and count=5 then it represents that 10 can be candidate of 5th smallest element.
    Now accordingly we have to adjust our low and high. 
    If count<=k , say count=5 and k=8 so we have to move up the low to mid+1
    If count >k we have to move down high=mid( note high=mid and not mid-1 do a dry run to understand this).

    We have to do this binary search till low<high then kth smallest element will be low/hgh return that.

    Time complexity:
    We are calculating binary search over range = low to high
    Log[high - low] let ay range is R so log R.
    We are using upperbound on all the rows which is Nlog N. logN for upper and for N rows.
    So overall logR * NlogN
    Space: O(1)

*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        if( matrix.size()==0)
            return 0;
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        
        while(low<high) {
            int mid = low+(high-low)/2;
            printf("Low =%d, high=%d mid=%d\n", low, high,mid);
            int count = getSmallElemsCount(matrix, mid, n);
            if(count < k) low=mid+1;
            else high=mid;
        }
        return low;
    }
    /* Get the elements count which are lesser or equal to upper val */
    int getSmallElemsCount(const vector<vector<int>>& matrix, const int &upper, int n) {
        int count = 0;
        for(int i=0; i<n; ++i) {
            auto it = std::upper_bound(matrix[i].begin(), matrix[i].end(), upper);
            count += (it-matrix[i].begin());
        }
        printf("count =%d\n",count);
        return count;
    }
};