#include <iostream>
#include <iomanip>  

class DynamicMatrix {
private:
    int** data;
    size_t rows, cols;

    void allocate(size_t r, size_t c) {
        data = new int*[r];
        for (size_t i = 0; i < r; ++i) {
            data[i] = new int[c]{};
        }
    }

    void deallocate() {
        for (size_t i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

public:
    DynamicMatrix(size_t r, size_t c, int fill = 0) : rows(r), cols(c) {
        allocate(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                data[i][j] = fill;
    }

    ~DynamicMatrix() {
        deallocate();
    }

    void resize(size_t new_rows, size_t new_cols, int fill_value = 0) {
        int** new_data = new int*[new_rows];
        for (size_t i = 0; i < new_rows; ++i) {
            new_data[i] = new int[new_cols];
            for (size_t j = 0; j < new_cols; ++j) {
                if (i < rows && j < cols)
                    new_data[i][j] = data[i][j];
                else
                    new_data[i][j] = fill_value;
            }
        }

        deallocate();
        data = new_data;
        rows = new_rows;
        cols = new_cols;
    }

    void transpose() {
        int** transposed = new int*[cols];
        for (size_t i = 0; i < cols; ++i) {
            transposed[i] = new int[rows];
            for (size_t j = 0; j < rows; ++j) {
                transposed[i][j] = data[j][i];
            }
        }

        deallocate();
        data = transposed;
        std::swap(rows, cols);
    }

    int& at(size_t r, size_t c) {
        return data[r][c];
    }

    void print() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                size_t index_1d = i * cols + j;
                int value = data[i][j];
                if (index_1d % 2 == 1)
                    value += 2;

                std::cout << std::setw(4) << value;
            }
            std::cout << "\n";
        }
    }

    size_t num_rows() const { return rows; }
    size_t num_cols() const { return cols; }
};
int main() {
    DynamicMatrix mat(3, 3, 1);

    mat.at(0, 0) = 5;
    mat.at(1, 1) = 7;
    mat.at(2, 2) = 9;

    std::cout << "Original Matrix:\n";
    mat.print();

    mat.resize(4, 5, 0);
    std::cout << "\nAfter Resizing to 4x5:\n";
    mat.print();

    mat.transpose();
    std::cout << "\nAfter Transposing:\n";
    mat.print();

    return 0;
}
