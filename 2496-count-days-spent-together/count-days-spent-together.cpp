class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        auto getDayOfYear = [&](const string& date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int total = day;
            for (int i = 0; i < month - 1; ++i) {
                total += daysInMonth[i];
            }
            return total;
        };

        int startAlice = getDayOfYear(arriveAlice);
        int endAlice = getDayOfYear(leaveAlice);
        int startBob = getDayOfYear(arriveBob);
        int endBob = getDayOfYear(leaveBob);

        int overlapStart = max(startAlice, startBob);
        int overlapEnd = min(endAlice, endBob);

        return max(0, overlapEnd - overlapStart + 1);
    }
};