/**
 * Here the approach is to solve the problem in sliding window method.
 * Will frame windows using two pointers left and right.
 * In each window we need to figure out the popular char(max frequency).
 * If windowlen - popularcharfreq is less or equal to K , it's a valid window.
 * Note: We can do max K replacements of chars in a window.
 * Now if window is invalid, slide the left pointer and remember to decrement the frequency count
 * as we are reomving the left pointer char from window.
 * 
 * Reference: https://www.youtube.com/watch?v=gqXU1UyA8pk
 * 
 * Complexity
 * Time: O(n) : Traversing all the chars in string
 * Space:O(n) : Worst case if all the chars need to be stored in map.
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        if( s.empty() )
            return 0;
        int size = s.size();
        /* map to keep the frequency of chars in window */
        std::unordered_map<char,int> freqmap;
        int left = 0,right = 0, result = 0;
        while( (left<size) && (right<size) ){
            freqmap[s[right]] +=1;
            int windowlen = (right-left)+1;
            /* windowlen - popularcharfreq gives the max number of replacements 
                can be done in the window.
                So the condition is if in given window  windowlen - popularcharfreq is
                less or equal to k then it's a valid window.
             */
            if( windowlen-getPopularCharInWindow(freqmap) > k ){
                /*
                    Not a valid window.
                    Slide the left pointer to start a new window.
                */
                /* Update the map as we are removing the left char from window*/
                freqmap[s[left]] -=1;
                ++left;
                /*windowlen has changed now. Update it. */
                windowlen = (right-left)+1; 
            }
            /* Update the result for valid window*/
            result = std::max(result,windowlen);
            ++right;
        }
        return result;
    }

    int getPopularCharInWindow( const unordered_map<char,int> &freqmap){
        int max_freq=0;
        for( const auto& [key,value] : freqmap){
            max_freq = std::max(max_freq, value);
        }
        return max_freq;
    }
};