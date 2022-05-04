int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>v(n+1, 0);
        for(int i = 1; i <= n; i++) {
            if(i>x && v[i-x]) {
                v[i] = max(v[i], 1 + v[i-x]);
            }
            if(i>y && v[i-y]) {
                v[i] = max(v[i], 1 + v[i-y]);
            }
            if(i>z && v[i-z]) {
                v[i] = max(v[i], 1 + v[i-z]);
            }
            if(i==x) {
                v[i] = max(v[i], 1);
            }
            if(i==y) {
                v[i] = max(v[i], 1);
            }
            if(i==z) {
                v[i] = max(v[i], 1);
            }
        }
        return v[n];
    }
