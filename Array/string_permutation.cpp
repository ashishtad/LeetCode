/*
Brute force Approach:
Generate all permutations of s1.
Check if any permutation is a substring of s2.
While this approach is valid, it is not optimal because:

Generating all permutations of s1 takes O(N!) time (where N = s1.length()).
Checking each permutation in s2 takes O(M) (where M = s2.length()).
Overall, this results in O(N! * M) time complexity, which is inefficient for large inputs.

Optimized Approach: Sliding Window + Frequency Count.
Count the frequency of characters in s1.
Use a sliding window of length s1.size() to traverse s2 and check 
if the window has the same character count as s1.

Time complexity : O(N+M) N: size of s1 M: size of s2
Space complexity: O(1) freq array size is fixed of 26. 
*/


class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            if(s1.empty() || s2.empty() || s1.size()> s2.size())
                return false;
            
            /* calc and store frequency of chars in s1 */
            vector<int> s1_freq(26,0);
            for(char c: s1)
                s1_freq[c-'a']++; /* chars are referenced from 'a' as to store them in integer which is index  of mas1_freq.
                s1_freq length would be 26 i.e 0 to 25 for 26 chars 0th index for a , 1st index for b and so on..*/
    
            vector<int> s2_freq(26,0);
            /* Traverse s2 with fixed window size of s1.size() and check the frequence of chars in the window */
            for(int i=0; i<s2.size(); ++i) {
    
                s2_freq[s2[i]-'a']++;
    
                /* Discard the s2 char from the window as it exceeds the s1 size. 
                    As we have to check for s1.size as the window size in s2.
                */
                if(i>=s1.size()) {
                    s2_freq[s2[i-s1.size()]-'a']--;
                }
    
                if(s1_freq == s2_freq)
                    return true;
            }
            return false;
        }
    };