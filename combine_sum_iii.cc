class Solution {
public:
    void dfs(int curr, int k, int sum, vector<int> &vec, vector<vector<int> > &ret) {
        if (k == 0 && sum == 0) {
            ret.push_back(vec);
            return;
        }
        if (curr <= 9 && (k != 0 && curr <= sum / k)) {
            vec.push_back(curr);
            dfs(curr + 1, k - 1, sum - curr, vec, ret);
            vec.pop_back();
            dfs(curr + 1, k, sum, vec, ret);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ret;
        vector<int> vec;
        dfs(1, k, n, vec, ret);
        return ret;
    }
};

class Solution {
public:
    void dfs(vector<vector<int>> &ret, vector<int> &tmp, int k, int n, int start) {
        if(k == 0 && n == 0) {
            ret.push_back(tmp);
            return;
        }
        if(k != 0 && start <= n/k && start <= 9){
            tmp.push_back(start);
            dfs(ret, tmp, k - 1, n - start, start + 1);
            tmp.pop_back();
            dfs(ret, tmp, k, n, start + 1);
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        vector<vector<int>> ret;
        dfs(ret, tmp, k, n, 1);
        return ret;
    }
};
