#include <iostream>
#include "SparseMatrix.h"

int main() {
    int choice;
    std::string file1, file2;

    std::cout << "Select operation:\n";
    std::cout << "1. Addition\n2. Subtraction\n3. Multiplication\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    std::cout << "Enter path to first matrix file: ";
    std::cin >> file1;
    std::cout << "Enter path to second matrix file: ";
    std::cin >> file2;

    try {
        SparseMatrix A(file1);
        SparseMatrix B(file2);
        SparseMatrix result = (choice == 1) ? A.add(B) :
                      (choice == 2) ? A.subtract(B) :
                      A.multiply(B);

        if (choice == 1)
            result = A.add(B);
        else if (choice == 2)
            result = A.subtract(B);
        else if (choice == 3)
            result = A.multiply(B);
        else {
            std::cout << "Invalid choice.\n";
            return 1;
        }

        std::cout << "\nResult printed on screen:\n";
        result.print();

        std::string outputFilename = "result.txt";
        result.printToFile(outputFilename);
        std::cout << "\nResult also written to file: " << outputFilename << "\n";

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
