class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int n = d.size();
        vector<int> a(n, -1);
        if(d[n-1] == 0){
            a[0] = 1;
            a[n-1] = 1;
        }else{
            a[0] = 1;
            a[n-1] = 0;
        }
        for(int i = 0; i < n; i++){
            if(d[i] == 1){
                if(a[i] != -1 && a[(i+1)%n] != -1){
                    if(d[i] != (a[i] ^ a[(i+1)%n])) return false;
                }
                a[(i+1)%n] = 1 - a[i];
            }else{
                if(a[i] != -1 && a[(i+1)%n] != -1){
                    if(d[i] != (a[i] ^ a[(i+1)%n])) return false;
                }
                a[(i+1)%n] = a[i];
            }
        }
        return true;
    }
};
