class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> son;
        int final = 0;
        for (auto &block : tokens) {
            if (isdigit(block[0])||(block.size()!=1&&isdigit(block[1]))) {
                son.push(stoi(block));
            } else {
                int second = son.top(); son.pop();
                int first = son.top(); son.pop();
                if (block == "+") { final = first + second; }
                else if (block == "-") { final = first - second; }
                else if (block == "*") { final = first * second; }
                else if (block == "/") {
                    final=(second == 0)?1:first/second; }
                son.push(final);}}
        return son.top();}};