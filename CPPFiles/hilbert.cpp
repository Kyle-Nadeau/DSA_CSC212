#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>


// Function to generate a Hilbert curve of order n
void hilbertCurve(int x, int y, int dir, int order) {
    // start filestream with output file
    std::ofstream file;
    file.open("output.txt");
    // begin main fcn
    if (order == 0) {
        // base case: draw a line
        std::cout << "(" << x << ", " << y << ")" << std::endl;
        file << "F ";
    } else {
        int length = pow(2, order - 1);
        int newOrder = order - 1;
        if (dir == 0) {
            // draw a line upwards
            hilbertCurve(x, y + length, 1, newOrder);
            // draw a line to the right
            hilbertCurve(x + length, y, 0, newOrder);
            file <<  "+ ";
            // draw a line downwards
            hilbertCurve(x + length, y + length, 0, newOrder);
            // draw a line to the left
            hilbertCurve(x, y, 3, newOrder);
            file <<  "- ";
        } else if (dir == 1) {
            // draw a line to the right
            hilbertCurve(x + length, y, 0, newOrder);
            file <<  "+ ";
            // draw a line upwards
            hilbertCurve(x, y + length, 1, newOrder);
            // draw a line to the left
            hilbertCurve(x, y, 1, newOrder);
            file <<  "- ";
            // draw a line downwards
            hilbertCurve(x + length, y + length, 2, newOrder);
        } else if (dir == 2) {
            // draw a line downwards
            hilbertCurve(x + length, y + length, 2, newOrder);
            // draw a line to the left
            hilbertCurve(x, y, 3, newOrder);
            file <<  "- ";
            // draw a line upwards
            hilbertCurve(x, y + length, 1, newOrder);
            // draw a line to the right
            hilbertCurve(x + length, y, 2, newOrder);
            file <<  "+ ";
        } else {
            // draw a line to the left
            hilbertCurve(x, y, 3, newOrder);
            file <<  "- ";
            // draw a line downwards
            hilbertCurve(x + length, y + length, 0, newOrder);
            // draw a line to the right
            hilbertCurve(x + length, y, 2, newOrder);
            file <<  "+ ";
            // draw a line upwards
            hilbertCurve(x, y + length, 3, newOrder);
        }
    }
    file.close();
}

// main function
int main() {
    int order;
    std::cout << "Enter the order of Hilbert curve: ";
    std::cin >> order;
    hilbertCurve(0, 0, 0, order);
    return 0;
}
