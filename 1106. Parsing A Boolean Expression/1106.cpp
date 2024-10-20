class Solution {
public:
    bool parseBoolExpr(string s) {
        int n = s.length();
        stack <char> operand;
        stack <char> oper;

        for (int i = 0; i < n; i++) {
            if (s[i] == 't' || s[i] == 'f' || s[i] == '(') {
                operand.push(s[i]);
            } else if (s[i] == '&' || s[i] == '!' || s[i] == '|') {
                oper.push(s[i]);
            } else if (s[i] == ')') {
                char operation = oper.top();
                oper.pop();
                if (operation == '!') {
                    char c = operand.top();
                    operand.pop(); operand.pop();
                    if (c == 't') operand.push('f');
                    else operand.push('t');
                } else if (operation == '&') {
                    bool flag = true;
                    while (operand.top() != '(') {
                        char c = operand.top();
                        if (c == 'f') {
                            flag = false;
                        }
                        operand.pop();
                    }
                    operand.pop();
                    if (flag) operand.push('t');
                    else operand.push('f');
                } else if (operation == '|') {
                    bool flag = false;
                    while (operand.top() != '(') {
                        char c = operand.top();
                        if (c == 't') {
                            flag = true;
                        }
                        operand.pop();
                    }
                    operand.pop();
                    if (flag) operand.push('t');
                    else operand.push('f');
                }
            } else {
                continue;
            }
        }
        if (operand.top() == 'f') return false;
        return true;
    }
};