#include <iostream>

int main() {
    const int numberOfRows = 5;

    int length[numberOfRows] = {6, 3, 4, 2, 7};
    int **irregularArray = new int *[numberOfRows];

    for (int i = 0; i != numberOfRows; ++i) {
        irregularArray[i] = new int[length[i]];
    }

    irregularArray[2][3] = 5;
    irregularArray[4][6] = irregularArray[2][5] + 2;
    irregularArray[1][1] = 3;

    std::cout << irregularArray[2][3] << std::endl;
    std::cout << irregularArray[4][6] << std::endl;
    std::cout << irregularArray[1][1] << std::endl;

    for (int i = 0; i != numberOfRows; ++i) {
        delete[] irregularArray[i];
    }
    delete[] irregularArray;

    return 0;
}
