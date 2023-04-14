#include <iostream>
#include <cmath>



// Function to generate a Hilbert curve of order n
void hilbertCurve(int x, int y, int dir, int order) {
    if (order == 0) {
        // base case: draw a line
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    } else {
        int length = pow(2, order - 1);
        int newOrder = order - 1;
        if (dir == 0) {
            // draw a line upwards
            hilbertCurve(x, y + length, 1, newOrder);
            // draw a line to the right
            hilbertCurve(x + length, y, 0, newOrder);
            // draw a line downwards
            hilbertCurve(x + length, y + length, 0, newOrder);
            // draw a line to the left
            hilbertCurve(x, y, 3, newOrder);
        } else if (dir == 1) {
            // draw a line to the right
            hilbertCurve(x + length, y, 0, newOrder);
            // draw a line upwards
            hilbertCurve(x, y + length, 1, newOrder);
            // draw a line to the left
            hilbertCurve(x, y, 1, newOrder);
            // draw a line downwards
            hilbertCurve(x + length, y + length, 2, newOrder);
        } else if (dir == 2) {
            // draw a line downwards
            hilbertCurve(x + length, y + length, 2, newOrder);
            // draw a line to the left
            hilbertCurve(x, y, 3, newOrder);
            // draw a line upwards
            hilbertCurve(x, y + length, 1, newOrder);
            // draw a line to the right
            hilbertCurve(x + length, y, 2, newOrder);
        } else {
            // draw a line to the left
            hilbertCurve(x, y, 3, newOrder);
            // draw a line downwards
            hilbertCurve(x + length, y + length, 0, newOrder);
            // draw a line to the right
            hilbertCurve(x + length, y, 2, newOrder);
            // draw a line upwards
            hilbertCurve(x, y + length, 3, newOrder);
        }
    }
}

// main function
int main() {
    int order;
    std::cout << "Enter the order of Hilbert curve: ";
    std::cin >> order;
    hilbertCurve(0, 0, 0, order);
    return 0;
}
