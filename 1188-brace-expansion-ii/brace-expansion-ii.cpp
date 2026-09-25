class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        vector<set<string>> stk;
        stk.push_back({});
        stk.push_back({""});
        for (char c : expression) {
            if (c == '{') {
                stk.push_back({});
                stk.push_back({""});
            } else if (c == '}') {
                set<string> right = stk.back(); stk.pop_back();
                set<string> union_set = stk.back(); stk.pop_back();
                for (const string& s : right) {
                    union_set.insert(s);
                }
                set<string> left = stk.back(); stk.pop_back();
                set<string> concat;
                for (const string& l : left) {
                    for (const string& r : union_set) {
                        concat.insert(l + r);
                    }
                }
                stk.push_back(concat);
            } else if (c == ',') {
                set<string> right = stk.back(); stk.pop_back();
                for (const string& s : right) {
                    stk.back().insert(s);
                }
                stk.push_back({""});
            } else {
                set<string> right = stk.back(); stk.pop_back();
                set<string> next_set;
                string char_str(1, c);
                for (const string& s : right) {
                    next_set.insert(s + char_str);
                }
                stk.push_back(next_set);
            }
        }
        set<string> total_union = stk.back(); stk.pop_back();
        if (!stk.empty()) {
            for (const string& s : total_union) {
                stk.back().insert(s);
            }
            total_union = stk.back();
        }
        return vector<string>(total_union.begin(), total_union.end());
    }
};