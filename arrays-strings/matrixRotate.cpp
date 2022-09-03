#include <iostream>
#include <vector>

template <typename T>
void transposMatrix(std::vector <std::vector <T>>&);

template <typename T>
void reverseMatrix(std::vector <std::vector <T>> &);

template <typename T>
void rotateMatrix(std::vector <std::vector <T> >&);

template <typename T>
void rotateMatrix(std::vector <std::vector <T> >&, int);

int main()
{
    std::vector <std::vector <int>> matrix {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {8, 9, 10, 11},
        {12, 13, 14, 15}
    };
    std::vector <std::vector <std::string>> matrix1 {
        {"aa", "bb", "cc", "dd"},
        {"ee", "ff", "gg", "hh"},
        {"ii", "jj", "kk", "ll"},
        {"mm", "nn", "oo", "pp"}
    };
    
    rotateMatrix(matrix1, 90);
    for(auto a: matrix1) {
        for(auto b : a) {
            std::cout << b << ",";
        }
        std::cout << std::endl;
    }

    return 0;
}

template <typename T>
void rotateMatrix(std::vector <std::vector <T> >& matrix) {
    transposMatrix(matrix);
    reverseMatrix(matrix);
};

template <typename T>
void rotateMatrix(std::vector <std::vector <T> >& matrix, int angle) {
    for(int i{}; i < angle / 90; i++) {
        transposMatrix(matrix);
        reverseMatrix(matrix);
    }
};

template <typename T>
void transposMatrix(std::vector<std::vector<T>>& matrix) {
    for (int x{}; x < matrix.size() - 1; x ++) {
        for (int y = x ; y < matrix[x].size(); y++) {
            std::swap(matrix[x][y], matrix[y][x]);
        }
    }
}

template <typename T>
void reverseMatrix(std::vector<std::vector<T>> & matrix) {
    for (int x{}; x < matrix.size(); x ++) {
        for (int y{}; y < matrix[x].size() / 2; y++) {
            std::swap(matrix[x][y], matrix[x][matrix[x].size() - 1 - y]);
        }
    }
}