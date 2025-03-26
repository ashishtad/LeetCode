/*Minimum Operations to Make a Uni-Value Grid*/

/*

Step 1: Understanding the Problem
We have a m x n grid with integer values.

We can increment or decrement values by a fixed step size x.

The goal is to make all values in the grid the same using the minimum number of operations.

Step 2: Check Feasibility
If the differences between any two elements in the grid are not divisible by x, it is impossible to make all values equal.

To check this, pick a base value (e.g., the first element) and ensure all other values in the grid have the same remainder when divided by x.

Step 3: Convert Grid to a Sorted 1D Array
Flatten the m x n grid into a 1D vector.

Sort the array to make it easier to find the median.

Step 4: Identify the Target Value (Median)
The best choice to minimize absolute differences is the median of the sorted values.

The median ensures that the sum of absolute differences is minimized.

Step 5: Calculate Minimum Operations
Iterate over the sorted array and count the number of operations needed 
to convert each element to the median, using step size x.

For each element in flattened, compute the difference from the median:
diff = abs(element-median)
operations = diff/x
Divide by x (since each operation increments or decrements by x):

Step 6: Return the Result
Return the total number of operations as the final answer.

Complexity
Time:
    Sorting takes O(N log N) (to find the median).

    Checking feasibility takes O(N).

    Computing moves takes O(N).

    Overall complexity: O(N log N).

Space : O(N) N:m*n for additional 1d array which is flattende


*/


class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        if(0==grid.size()) return 0;
        int remainder = grid[0][0]%x;
        vector<int> gridList;
        /* Traverse the grid and check if the all the elements has same remainder.
            In the same traversal form the 1d array of grid.
         */
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid[0].size(); ++j) {
                if(grid[i][j]%x != remainder) return -1;
                else gridList.push_back(grid[i][j]);
            }
        }

        std::sort(gridList.begin(), gridList.end());
        /* Get the median of sorted array */
        int median = gridList[gridList.size()/2];
        int count = 0;
        /* Traverse the sorted array and count the no of operations required by each element.*/
        for( const int &elem : gridList) {
            count += abs(elem-median)/x;
        }
        return count;
    }
};