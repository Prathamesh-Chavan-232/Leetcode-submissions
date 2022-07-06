// This question requires pre - computation
// hash the tribonacci seq for all 1 <= N <= 37, then print -> hsh[n]
const int N = 38;
class Solution {
public:
    int tribonacci(int n) {
        vector<int> hsh(N);
        hsh[1] = hsh[2] = 1;
        for(int i = 3; i < N; ++i) {
            hsh[i] = hsh[i - 3] + hsh[i - 2] + hsh[i - 1];
        }
        return hsh[n];
    }
};


// Naive recursive solution - gives TlE
class Solution2 {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        
        return tribonacci(n - 1) + tribonacci(n -2) + tribonacci(n - 3);
    }
};