#include <iostream>
#include <vector>

void setZeroes(std::vector<std::vector<int>>& matrix) {
    std::vector<bool> rows(matrix.size());
    std::vector<bool> cols(matrix[0].size());

    for(int i{}; i < matrix.size(); i++) {
        for(int j{}; j < matrix[i].size(); j++) {
            if(matrix[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    for(int i{}; i < rows.size(); i++) {
        if(rows[i]) {
            for(int j{}; j < matrix[0].size(); j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for(int i{}; i < cols.size(); i++) {
        if(cols[i]) {
            for(int j{}; j < matrix.size(); j++) {
                matrix[j][i] = 0;
            }
        }
    }
};

int main() {

    std::vector<std::vector<int>> mat = {
        {7, 2, 6},
        {1, 0, 2},
        {4, 2, 3},
    };
    setZeroes(mat);
    for(const auto& a : mat) {
        for(const auto& el : a) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
}