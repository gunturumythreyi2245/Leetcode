class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string path;
        
        auto dfs = [&](auto& self, int idx, long eval, long multed) -> void {
            if (idx == num.size()) {
                if (eval == target) {
                    ans.push_back(path);
                }
                return;
            }
            
            long curr = 0;
            int len = path.size();
            
            for (int i = idx; i < num.size(); ++i) {
                if (i != idx && num[idx] == '0') break;
                curr = curr * 10 + (num[i] - '0');
                string sub = num.substr(idx, i - idx + 1);
                
                if (idx == 0) {
                    path += sub;
                    self(self, i + 1, curr, curr);
                    path.resize(len);
                } else {
                    path += "+" + sub;
                    self(self, i + 1, eval + curr, curr);
                    path.resize(len);
                    
                    path += "-" + sub;
                    self(self, i + 1, eval - curr, -curr);
                    path.resize(len);
                    
                    path += "*" + sub;
                    self(self, i + 1, eval - multed + multed * curr, multed * curr);
                    path.resize(len);
                }
            }
        };
        
        dfs(dfs, 0, 0, 0);
        return ans;
    }
};