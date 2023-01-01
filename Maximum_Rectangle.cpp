class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> v(n, vector<int>(m));
        v[0][0] = matrix[0][0] - '0';
        int res = 0;

        for(int i = 1; i < n; i++) {
            if(matrix[i][0] == '0') {
                v[i][0] = v[i-1][0];
            }else {
                v[i][0] = 1 + v[i-1][0];
            }
        }


        for(int i = 1; i < m; i++) {
            if(matrix[0][i] == '0') {
                v[0][i] = v[0][i-1];
            }else {
                v[0][i] = 1 + v[0][i-1];
            }
        }



        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == '0') v[i][j] = v[i-1][j] + v[i][j-1] - v[i-1][j-1];
                else v[i][j] = 1 + v[i-1][j] + v[i][j-1] - v[i-1][j-1];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = i; k < n; k++) {

                    int start = j;
                    int end = m - 1;
                    while(start <= end) {
                        int mid = start + (end - start)/2;
                        int ans;
                        if(i == 0) {
                            if(j) ans = v[k][mid] - v[k][j-1];
                            else ans = v[k][mid];
                        }else if(j == 0) {
                            ans = v[k][mid] - v[i-1][mid];
                        }else {
                            ans = v[k][mid] - v[k][j-1] - v[i-1][mid] + v[i-1][j-1];
                        }
                        if(ans  == (k - i + 1) * (mid - j + 1)) {
                            res = max(res, ans);
                            start = mid + 1;
                        }else {
                            end = mid - 1;
                        }
                    }
                }
            }
        }
        return res;
    }
};
