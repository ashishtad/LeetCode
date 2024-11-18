/*
 * 2284. Sender With Largest Word Count
 *
 * 1. unorder map to hold the sender and their words count.
 * 2. Max Heap to hold the max frequency words.
   3. Pop top of heap until frequency is same for further elements.
      This is to identify if multiple senders having same words frequency.
   4. Determine the lexicographically largest sender if multiple senders 
   else if one largest sender return it.  
 */

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {

        int msgsize = messages.size();
        int sendersize = senders.size();
        if(msgsize == 0 || sendersize == 0)
            return "";
        /* Sender, wordcount */
        unordered_map<string,int> msgcount;

        for( int itr=0; itr< sendersize; ++itr) {
            string sendermsg = messages[itr];
            /* count the words */
            int count = std::count(sendermsg.begin(), sendermsg.end(), ' ')+1;
            msgcount[senders[itr]] += count;
        }
        /* Pair of word count and sender */
        using Pair = std::pair<int,string>;
        std::priority_queue<Pair, vector<Pair>> pq;

        for( const auto &[sender,count] : msgcount) {
            pq.emplace(std::make_pair(count,sender));
        }
        
        /* Pop the top/most word count sender */
        string result = pq.top().second;
        int maxcount = pq.top().first;
        pq.pop();
        vector<string> largestName;
        largestName.push_back(result);
        /* Pop the top until the largest found wordcount matches */
        while(!pq.empty() && (maxcount == pq.top().first) ) {
             largestName.push_back(pq.top().second);
             pq.pop();
        }

        if(largestName.size() == 0)
            return result;
        
        /* find lexicographically largest string */
        auto largeststr =  std::max_element(largestName.begin(), largestName.end());
        return (*largeststr);
    }
};