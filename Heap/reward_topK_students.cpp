/*
  
  These are inputs - postive feedback , negative feedback, review report of each student, student id.
  Now we have to frame the score of each student from the report.

  1. Traverse the report and find each report's word in positive and negative feeback list.
     For match in positive f/b increase score by 3 and match in negtive feedback dcrease by 1.
  2.Push the calculated score alongwith student is in min heap. When the heap size grows more than K pop top.

  3. Now we are left with students with highest score in the heap. Extrac them and return.    

*/

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {

        /* For quick look up */
        unordered_set<string> positiveSet(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> negativeSet(negative_feedback.begin(), negative_feedback.end());
        using pi = pair<int,int>;
        
        auto comp = [](const pi &a, const pi &b) {

            if (a.first == b.first) return (a.second < b.second);
            return (a.first > b.first);
        };
        /* pair of (score,student_id) -Min heap */
        priority_queue<pi, vector<pi>, decltype(comp)> pq(comp);
        for (int id=0; id<student_id.size(); ++id) {
            string review = report[id];
            int score = calculateScore(review, positiveSet, negativeSet) ;
            pq.emplace(score, student_id[id]);
            if (pq.size() > k) pq.pop();
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        std::reverse(res.begin(), res.end());
        return res; 
    }

    int calculateScore( const string &review, const unordered_set<string> &positiveSet, const unordered_set<string> &negativeSet) {

        istringstream iss(review);
        int score = 0;
        string word = "";
        while (iss >> word) {
            if (positiveSet.count(word)) score +=3;
            else if (negativeSet.count(word)) score -= 1;

            word = "";
        }
        return score;
    }
};