class Solution {
public:
    bool canBeValid(string s, string locked) {

        int n = s.size();
        if(n%2==1) return false;
        stack<int> open;
        stack<int>openclose;
            for(int i=0;i<n;i++){

                if(locked[i]=='0'){
                    openclose.push(i);
                }
                else if(s[i]=='('){
                        open.push(i);
                    }
                    else if(s[i]==')'){
                        if(!open.empty()){
                            open.pop();
                        }
                        else if(!openclose.empty()){
                                openclose.pop();
                            }
                            else{
                                return false;
                            }
                        }
                }
    while(!open.empty() && !openclose.empty() && open.top()<openclose.top()){
            open.pop();
            openclose.pop();

        }
    return open.empty();
    }
};