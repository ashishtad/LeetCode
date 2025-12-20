/*
    SIMPLIFIED PROBLEM STATEMENT 
    ============================
    We are given multiple trips.
    Each trip adds passengers at a start location 
    and removes them at an end location.
    We must ensure that at no point along the route
    does the total number of passengers exceed the car’s capacity.

    INTUITION
    =========
    Instead of simulating each trip, let's track how the passenger 
    count changes along the route and compute the cumulative
    load using a prefix sum.
    
    APPROACH-1
    ==========
    Since locations are bounded (0 ≤ location ≤ 1000 in this problem):
    Use an array (difference array) to store net passenger changes per location.

    1. Take an array of 1000 size and store each trip's passenger
       at start and end location.
       ar[start] = passenger of trip
       ar[end] = - passenger of trip
    2. Iterate through the array and maintain a cur passenger
       When cur passenger exceeds capacity return false.

    APPROACH-2
    ==========
    When the locations are huge say 10^9 then array 
    won't be suitable to iterate.
    Here will take a map where locations would be
    sorted automatically and rest of logic remains the same.
*/


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        if (trips.size() ==0) return true;

       map<int,int> locationMap;

        for (auto trip : trips) {
            int start = trip[1];
            int passenger = trip[0];
            int end = trip[2];
            locationMap[start] += passenger;
            locationMap[end] -= passenger;
        }
        int curPassengerCount = 0;
        for (auto &[location, passenger] : locationMap) {
            curPassengerCount += passenger; 
            if (curPassengerCount  > capacity) return false;
        }
        return true;
    }
};