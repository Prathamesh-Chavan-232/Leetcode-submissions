class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        int maxIndex = max(findMaxInArray(seats), findMaxInArray(students));
        vector<int> countSeats(maxIndex + 1, 0), countStudents(maxIndex + 1, 0);

        for (int i = 0; i < n; i++) {
            countSeats[seats[i]]++;
            countStudents[students[i]]++;
        }

        int i = 0, j = 0, minMoves = 0;
        while (i <= maxIndex && j <= maxIndex) {
            if (countSeats[i] != 0 && countStudents[j] != 0) {
                minMoves += abs(i - j);
                countSeats[i]--;
                countStudents[j]--;
            }
            if (i <= maxIndex && countSeats[i] == 0)
                i++;
            if (j <= maxIndex && countStudents[j] == 0) 
                j++;
        }
        return minMoves;
    }
    int findMaxInArray(vector<int>& arr) {
        int _max = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            _max = max(_max, arr[i]);
        }
        return _max;
    }
};
