class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (char ch: s){
            //if this is the first charcter or the current letter along with the previous don't make 
            //any occurrence of one of the substrings "AB" or "CD" 
            // then add the current letter to st
            if (st.empty()||  ch == 'B' && st.top() != 'A' || ch == 'D' && st.top() != 'C' || ch != 'B' && ch != 'D' ){
                st.push(ch);
            }else{
            //if the current letter is D and C is at the
            // top of stack (that means that D appears after C (CD appears in s))
            //or the current is A and B is at the top of st
            //then  remove the element at the top of st
                st.pop();
            }
        }
        return st.size();
    }
};