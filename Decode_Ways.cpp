class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>v(n, 1);
        if(s[n-1]=='0'){
            v[n-1] = 0;
        }
        for(int i = n-2; i >= 0; i--) {
            if(i==(n-2)) {
                if(s[i]=='1') {
                    v[i] = 1 + v[i+1];
                }else if(s[i]=='2') {
                    if(s[i+1]<='6') {
                        v[i] = 1 + v[i+1];
                    }else{
                        v[i] = v[i+1];
                    }
                }else if(s[i]=='0') {
                    v[i] = 0;
                }else{
                    v[i] = v[i+1];
                }
            }else{
                if(s[i]=='1') {
                    v[i] = v[i+1] + v[i+2];
                }else if(s[i]=='2') {
                    if(s[i+1]<='6') {
                        v[i] = v[i+1] + v[i+2];
                    }else{
                        v[i] = v[i+1];
                    }
                }else if(s[i]=='0') {
                    v[i] = 0;
                }else{
                    v[i] = v[i+1];
                }
            }
        }
        return v[0];
    }
};
