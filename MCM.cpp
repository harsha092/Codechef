 #include <iostream>
#include <climits>
using namespace std;

int matrixChainMultiplication(int p[], int n) {
    int dp[n][n];

    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    for (int length = 2; length < n; length++) {
        for (int i = 1; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int c = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (c < dp[i][j])
                    dp[i][j] = c;
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int n;

    cout << "Enter the number of matrices: ";
    cin >> n;

    int arr[n + 1]; // Dimensions array with an extra element for simplicity
    cout << "Enter the dimensions of matrices: ";
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << "Minimum number of multiplications is: " << matrixChainMultiplication(arr, n + 1);

    return 0;
}
