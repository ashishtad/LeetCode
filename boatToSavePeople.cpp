
/*
 * 881. Boats to Save People
 *  The time complexity of this solution is O(n log n) due to the sorting operation, where n is the number of people. 
 *  The subsequent loop through the sorted array has a linear time complexity, 
 *  making the overall time complexity of the solution O(n log n).
 */
 
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        int num_people = people.size();
        if( 0== num_people)
            return 0;
        else if ( 1== num_people)
            return 1;
        
        std::sort(people.begin(), people.end());

        int end = num_people-1;
        int boat_count = 0;
        /*
            Now the array is sorted. So filter out -
            people whose weight is more than or equal to limit.
            For people whose weight is equal to limit,
            one boat each is reqd - increment the boat count.
        */
        while( people[end] >= limit ) {
            if( people[end] == limit )
                ++boat_count;
            --end;
        }

        /* Now pair up the start[min] and end [max] people. */
        int start = 0;
        while( start<= end ) {
            /* All people are processed.
               This is only person left. Process it and break */
            if ( start ==end ) {
                ++boat_count;
                break;
            }
            /* start and end people can pair up for a boat */
            if( limit >= people[start] + people[end] ){
                ++start;
                --end;
            } else{
                /* people[end] is maximum between start and end
                 and needs one boat alone. Send the end person in boat*/
                 --end;
            }
            ++boat_count;
        }

        return boat_count;
    }
};