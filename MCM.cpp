#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the most efficient way to multiply a given sequence of matrices
int matrixChainOrder(const vector<int>& p) {
    int n = p.size();
    // dp[i][j] stores the minimum number of scalar multiplications needed 
    // to compute the matrix A[i]...A[j], where matrix A[i] has dimensions p[i-1] x p[i].
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // length is the chain length. 
    // L = 2 means multiplying chains of length 2 (e.g., A_i * A_{i+1})
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;

            // k is the partition index
            for (int k = i; k <= j - 1; k++) {
                // Cost = cost of multiplying left sub-chain + 
                //        cost of multiplying right sub-chain + 
                //        cost of multiplying the two resulting matrices
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // Return the minimum cost to multiply from matrix 1 to matrix n-1
    return dp[1][n - 1];
}

int main() {
    // Example: Dimensions of matrices are 
    // A1: 10 x 30, A2: 30 x 5, A3: 5 x 60
    vector<int> dimensions = {10, 30, 5, 60};

    int minMultiplications = matrixChainOrder(dimensions);

    cout << "The minimum number of multiplications is: " << minMultiplications << endl;
