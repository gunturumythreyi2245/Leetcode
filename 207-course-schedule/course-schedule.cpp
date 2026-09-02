class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build the adjacency list and fill in-degrees
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }
        // Step 2: Push all courses with 0 prerequisites (in-degree == 0) into the queue
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        // Step 3: Process the queue
        int completedCourses = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            completedCourses++;
            // Reduce the in-degree of neighboring courses
            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                // If a neighbor has no more prerequisites, it's ready to be taken
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        // Step 4: If we successfully took all courses, no cycle exists
        return completedCourses == numCourses;
    }
};
