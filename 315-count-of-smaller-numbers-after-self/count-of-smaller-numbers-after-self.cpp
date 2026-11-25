#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }
        mergeSort(arr, 0, n - 1, counts);
        return counts;
    }

private:
    void mergeSort(vector<pair<int, int>>& arr, int left, int right, vector<int>& counts) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, counts);
        mergeSort(arr, mid + 1, right, counts);
        merge(arr, left, mid, right, counts);
    }

    void merge(vector<pair<int, int>>& arr, int left, int mid, int right, vector<int>& counts) {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;
        int rightCount = 0;

        while (i <= mid && j <= right) {
            if (arr[j].first < arr[i].first) {
                rightCount++;
                temp[k++] = arr[j++];
            } else {
                counts[arr[i].second] += rightCount;
                temp[k++] = arr[i++];
            }
        }

        while (i <= mid) {
            counts[arr[i].second] += rightCount;
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (int p = 0; p < k; ++p) {
            arr[left + p] = temp[p];
        }
    }
};