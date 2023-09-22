/******************************************************
* There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

* You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

* Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

 Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
 

Constraints:

n == gas.length == cost.length
1 <= n <= 105
0 <= gas[i], cost[i] <= 104

Time complexity : O(n+k)
Space complexity : O(1)

***********************************************************************/












class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        if ( (gas.size() ==0) || (cost.size() == 0) )
            return -1;
        
        if ( gas.size() != cost.size() )
            return -1;

        int available_gas = 0;
        int start_pos = -1;
        int round = 1; // To keep a check of number of round/iteration for gas station.
        for ( int i=0; i< gas.size(); ++i ) {
            
            available_gas = (available_gas+gas[i]) - cost[i];

            //If not sufficient gas to go next station
            if ( available_gas < 0 )
            {
                //If start point is not yet set. Continue
                if ( -1 == start_pos ){
                    available_gas = 0;
                    continue;
                }
                //If start point is already set. Here 2 cases can happen:
                // 1.It can be first iteration of gas i.e. round-1 [ iteartor i has not reseted to -1 yet]
                // 2. It can be round-2 iteration of gas i.e iterator has been resetted to -1 to start from begining 
                else {
                    //case -2
                    if (round ==2 )
                        return -1;
                    //case-1
                    else{
                        start_pos = -1;
                        available_gas = 0;
                        continue;
                    }
                        
                }
                
            }
            //If start_pos is not set yet.
            if ( -1 == start_pos ){
                start_pos = i;
            //If start_pos i set and we reach again the same position, this is result.
            } else if ( i == start_pos ) {
                return start_pos;
            }
            //Reset the iterator when we reach the end of gas station 
            if ( i == gas.size()-1 ){
                    i = -1;
                    round +=1;
            }
                
        }
        return -1;
    }
};