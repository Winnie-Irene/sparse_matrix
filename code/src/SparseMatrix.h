#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <string>

class SparseMatrix {
private:
    int rows;
    int cols;
    struct Node {
        int row, col, val;
        Node* next;
    };
    Node* head;

public:
    SparseMatrix(const std::string& filePath);
    SparseMatrix(int rows, int cols);
    ~SparseMatrix();

    int getElement(int row, int col);
    void setElement(int row, int col, int value);

    SparseMatrix add(const SparseMatrix& other);
    SparseMatrix subtract(const SparseMatrix& other);
    SparseMatrix multiply(const SparseMatrix& other);

    void print();
};

#endif
