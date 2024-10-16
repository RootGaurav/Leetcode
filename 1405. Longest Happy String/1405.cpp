class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string result = "";
        
        while (!pq.empty()) {
            auto first = pq.top(); pq.pop();
            
            if (result.size() >= 2 && result[result.size() - 1] == first.second && result[result.size() - 2] == first.second) {
                if (pq.empty()) break;  
                
                auto second = pq.top(); pq.pop();
                result += second.second;
                if (--second.first > 0) pq.push(second); 
                
                pq.push(first); 
            } else {
                result += first.second;
                if (--first.first > 0) pq.push(first); 
            }
        }

        return result;
    }
};