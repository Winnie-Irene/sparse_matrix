#include "SparseMatrix.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <algorithm>

SparseMatrix::SparseMatrix(int r, int c) {
    rows = r;
    cols = c;
    head = nullptr;
}

SparseMatrix::~SparseMatrix() {
    Node* curr = head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

SparseMatrix::SparseMatrix(const std::string& filePath) {
    head = nullptr;
    std::ifstream inFile(filePath);
    if (!inFile.is_open()) {
        throw std::invalid_argument("Cannot open input file");
    }

    std::string line;
    std::getline(inFile, line);
    if (line.find("rows=") != 0) throw std::invalid_argument("Input file has wrong format");
    rows = std::stoi(line.substr(5));

    std::getline(inFile, line);
    if (line.find("cols=") != 0) throw std::invalid_argument("Input file has wrong format");
    cols = std::stoi(line.substr(5));

    while (std::getline(inFile, line)) {
        if (line.empty()) continue;

        // Remove whitespace
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());

        if (line.front() != '(' || line.back() != ')') {
            throw std::invalid_argument("Input file has wrong format");
        }

        line = line.substr(1, line.size() - 2); // remove ()
        std::stringstream ss(line);
        std::string r, c, v;
        if (!std::getline(ss, r, ',') || !std::getline(ss, c, ',') || !std::getline(ss, v)) {
            throw std::invalid_argument("Input file has wrong format");
        }

        int row = std::stoi(r);
        int col = std::stoi(c);
        int val = std::stoi(v);
        setElement(row, col, val);
    }
}

void SparseMatrix::setElement(int row, int col, int value) {
    if (value == 0) return;

    Node* newNode = new Node{row, col, value, nullptr};

    if (!head || (row < head->row) || (row == head->row && col < head->col)) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next && (curr->next->row < row || (curr->next->row == row && curr->next->col < col))) {
        curr = curr->next;
    }

    if (curr->next && curr->next->row == row && curr->next->col == col) {
        curr->next->val = value;
        delete newNode;
        return;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

int SparseMatrix::getElement(int row, int col) {
    Node* curr = head;
    while (curr) {
        if (curr->row == row && curr->col == col) return curr->val;
        curr = curr->next;
    }
    return 0;
}

void SparseMatrix::print() {
    std::cout << "rows=" << rows << "\n";
    std::cout << "cols=" << cols << "\n";

    Node* curr = head;
    while (curr) {
        std::cout << "(" << curr->row << ", " << curr->col << ", " << curr->val << ")\n";
        curr = curr->next;
    }
}

SparseMatrix SparseMatrix::add(const SparseMatrix& other) {
    if (rows != other.rows || cols != other.cols)
        throw std::invalid_argument("Matrix dimensions must match for addition");

    SparseMatrix result(rows, cols);

    for (Node* a = head; a; a = a->next)
        result.setElement(a->row, a->col, a->val);

    for (Node* b = other.head; b; b = b->next) {
        int existing = result.getElement(b->row, b->col);
        result.setElement(b->row, b->col, existing + b->val);
    }

    return result;
}

SparseMatrix SparseMatrix::subtract(const SparseMatrix& other) {
    if (rows != other.rows || cols != other.cols)
        throw std::invalid_argument("Matrix dimensions must match for subtraction");

    SparseMatrix result(rows, cols);

    for (Node* a = head; a; a = a->next)
        result.setElement(a->row, a->col, a->val);

    for (Node* b = other.head; b; b = b->next) {
        int existing = result.getElement(b->row, b->col);
        result.setElement(b->row, b->col, existing - b->val);
    }

    return result;
}

SparseMatrix SparseMatrix::multiply(const SparseMatrix& other) {
    if (cols != other.rows)
        throw std::invalid_argument("Invalid dimensions for multiplication");

    SparseMatrix result(rows, other.cols);

    for (Node* a = head; a; a = a->next) {
        for (Node* b = other.head; b; b = b->next) {
            if (a->col == b->row) {
                int val = result.getElement(a->row, b->col);
                result.setElement(a->row, b->col, val + (a->val * b->val));
            }
        }
    }

    return result;
}
