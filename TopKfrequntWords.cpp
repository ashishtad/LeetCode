//////////////////////////////////////////////////////////////////////////
//
//  692. Top K Frequent Words
//  Date: 27/06/2020
////////////////////////////////////////////////////////////////////////////



class Solution {
public:
    
    struct comp {
        //This operator decides in the order in which first arguement i.e lhs will be stored in
        //heap in comparison to rhs which is top of priority queue or top of max heap
        // Return of true: first arg(lhs) will be pushed before/back of second arg i.e top of prio qu
        // False: First element/arg will be at top of prio q or max heap and second elemn(rhs) will be adjusted in max heap
        bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) const {
            //if the first argument frequency is not the same as top of priority queue and first arg freq is less than top of prio q.
            //Then return true i.e push the first arg back and adjust heap if first arg freq is  less to second arg freq. Because our aim is to keep always highest freq element at                  top
            if (lhs.first != rhs.first)
                return lhs.first < rhs.first;
            
            //If both top element frequency are same. Then the string with lowest alphabetical ordr among two will be at top. 
            return lhs.second > rhs.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result(k);
        
        if( 0== words.size() || 0 ==k )
            return result;
        
        
        //map to store words and their frequency
        std::map<string,int> frequencyMap;
        for( auto it =words.begin(); it != words.end(); ++it  )
        {
            frequencyMap[*it]++;
        }
        //max heap /priority queue to store frequency , words in pairs
        //Heap elements will be in pairs and will be stored in a vector of pairs as container.
        //comp structure will be used to adjust the heap/or order the heap
        std::priority_queue< pair<int,string>, vector<pair<int,string>>, comp> maxHeap;
        for( auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it )
            maxHeap.push( make_pair(it->second,it->first));  
        
        //Traverse priority queue/max heap to get elements
        int i=0;
        while( k-- >0 && !maxHeap.empty())
        {
            result[i++] = maxHeap.top().second;
            maxHeap.pop();
        }
        return result;
    }
};