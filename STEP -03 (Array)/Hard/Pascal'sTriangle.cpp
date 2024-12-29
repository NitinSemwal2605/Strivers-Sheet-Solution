#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // Type 1: Generate full Pascal's Triangle up to `numRows`
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);
        
        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1); 
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++) {
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
            }
        }
        
        return r;
    }
    
    // Type 2: Print the k-th row (0-indexed) of Pascal's Triangle
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1); // Initialize with 1's
        
        for (int j = 1; j < rowIndex; j++) {
            row[j] = row[j - 1] * (rowIndex - j + 1) / (j);
        }
        
        return row;
    }
    
    // Type 3: Print the k-th element in the n-th row (0-indexed)
    int getElement(int row, int col) {
        // The element in Pascal's Triangle is computed as C(row, col) = row! / (col! * (row-col)!)
        long long result = 1;
        
        if (col > row - col) {
            col = row - col; // Optimize by taking the smaller value
        }
        
        for (int i = 1; i <= col; i++) {
            result = result * (row - col + i) / i;
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example for Type 1: Print full Pascal's Triangle for numRows = 5
    int numRows = 5;
    vector<vector<int>> fullTriangle = sol.generate(numRows);
    cout << "Full Pascal's Triangle:" << endl;
    for (const auto& row : fullTriangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    // Example for Type 2: Get the 4th row (index 4) of Pascal's Triangle
    int rowIndex = 4;
    vector<int> row = sol.getRow(rowIndex);
    cout << "\nThe 4th row is: ";
    for (int num : row) {
        cout << num << " ";
    }
    cout << endl;
    
    // Example for Type 3: Get the element at position 2 in the 4th row (C(4, 2))
    int n = 4, k = 2;
    int element = sol.getElement(n, k);
    cout << "\nThe element at row 4, position 2 is: " << element << endl;
    
    return 0;
}
