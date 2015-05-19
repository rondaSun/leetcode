void combineDFS(vector<vector<int>> &res, vector<int> tmp, int start, int n, int k) {
        if(k == 0) res.push_back(tmp);
        else {
            for(int i = start; i <= n; ++i) {
                tmp.push_back(i);
                combineDFS(res, tmp, i + 1, n, k - 1);
                tmp.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        combineDFS(res, tmp, 1, n, k);
        return res;
    }
