class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size());
        for (int i = 0; i < seq.size(); ++i) {
            ans[i] = (seq[i] == '(') ? (i & 1) : (1 - (i & 1));
        }
        return ans;
    }
};