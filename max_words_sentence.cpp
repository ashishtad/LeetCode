

/**
* Maximum Number of Words Found in Sentences

*  A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

* You are given an array of strings sentences, where each sentences[i] represents a single sentence.

* Return the maximum number of words that appear in a single sentence.
* Time complexity: O(n*m)
* Space complexity : O(1)
**/


class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {

        int max_words=0;
        for ( int i=0;  i< sentences.size() ;++i ){
            int count = countWords( sentences[i]);
            max_words = std::max(count,max_words);
        }
        return max_words;
    }


    int countWords( const string &sentence) {

        if ( sentence.empty())
            return 0;

        int word_count = 0;
        
        //For first word in sentence
        if ( isalpha(sentence[0]) )
            word_count++;
            
        for ( int i =0; i< sentence.size();++i){
        
            //check for space, if found check if next char to space is alphabet or not.
            // Increment wordcount if so.
            if ( sentence[i] == ' ') {
                if ( (i+1 < sentence.size()) && isalpha(sentence[i+1]) )
                    word_count++;
            }	
        }
        
        return word_count;
    }
};