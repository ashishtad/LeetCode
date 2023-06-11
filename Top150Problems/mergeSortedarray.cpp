#include <iostream>
#include <vector>
using namespace std;


vector<int> merge ( vector<int> nums1, int m, vector<int> nums2 , int n) {

    if( m==0 ) return nums2;
    else if( n==0 ) return nums1;

    vector<int> result;
    int i , j=0;

    for( i =0, j=0; i<m && j<n; ) {

        if( nums1[i] < nums2[j]) {
             result.push_back(nums1[i]);
             ++i;
        }
        else if ( nums1[i]== nums2[j] ){
            result.push_back(nums1[i]);
            ++i;
            ++j;
        }
        else{
            result.push_back(nums2[j]);
            ++j;
        }
           
    }

    if ( i< m) {
        while (i<m)
        {
            result.push_back(nums1[i++]);
        }
    }
    else if ( j < n){
          while (j<n)
        {
            result.push_back(nums2[j++]);
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = {1, 2, 12,16, 20};
   // int m = 3;
    vector<int> nums2 = {2, 5, 6};
    //int n = 3;

     vector<int> result = merge(nums1, nums1.size(), nums2, nums2.size());

    // Print the merged array
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}