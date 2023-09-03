#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

bool serch(std::vector<int>& vector, int numb) {
    for (int i{}; i < vector.size(); ++i) {
        if (vector[i] == numb) {
            return true;
        }
    }
    return false;
}

void dfs(int** matrix, int i, int size, std::vector<int>& result) {
    for (int j{}; j < size; ++j) {
        if (matrix[i][j] != 0) {
            if (!serch(result, j)) {
                result.push_back(j);
            }
            matrix[i][j] = 0;
            matrix[j][i] = 0;
            dfs(matrix, j, size, result);
        }
    }
}

int main() {
    std::fstream f_in("input.txt");
    int size{};
    if (f_in.is_open()) {
        f_in >> size;
        int** matrix = new int*[size];
        for (int i{}; i < size; ++i) {
            matrix[i] = new int[size];
        }
        for (int i{}; i < size; ++i) {
            for (int j{}; j < size; ++j) {
                f_in >> matrix[i][j];
            }
        }
        std::vector<int> result {0};
        for (int i{}; i < size; ++i) {
            for (int j{}; j < size; ++j) {
               if (matrix[i][j] != 0) {
                dfs(matrix, i, size, result);
               }
            }
            //std::cout << "\n";
        }
        for (auto i: result) {
            std::cout << i +1<< " ";
        }
        for (int i{}; i < size; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    f_in.close();
}