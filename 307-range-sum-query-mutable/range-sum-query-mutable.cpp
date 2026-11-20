class NumArray {
    vector<int> bit;
    vector<int> nums;
    int n;

    void add(int idx, int val) {
        for (++idx; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            add(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        add(index, diff);
    }
    
    int sumRange(int left, int right) {
        return query(right) - query(left - 1);
    }
};