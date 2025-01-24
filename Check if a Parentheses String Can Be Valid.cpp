class Solution {
public:
    bool canBeValid(string s, string l) {
        int n = s.size();
        if(n % 2 == 1){
            return false;
        }
        stack<int> un, open;
        for(int i = 0; i < n; i++){
            if(l[i] == '0'){
                un.push(i);
            }else if(s[i] == ')'){
                if(open.empty() && un.empty()){
                    return false;
                }
                if(open.empty()){
                    un.pop();
                }else{
                    open.pop();
                }
            }else if(s[i] == '('){
                open.push(i);
            }
        }
        while(!open.empty() && !un.empty() && open.top() < un.top()){
            open.pop();
            un.pop();
        }
        if(!open.empty()) return false;
        return true;
    }
};
