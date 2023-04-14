#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

std::string koch_snowflake(int order);
std::string snowflake(int order);
std::string sierpinski_triangle(int order, bool type1);
std::string closing_time(int order);


int main() {

    std::string input = "";

    while (input != "Exit") {
        std::cout << "Enter the corresponding number to the Recursive Graphic you would like to use:" << std::endl;
        std::cout << "1. Koch Snowflake" << std::endl;
        std::cout << "2. Sierpinski Triangle" << std::endl;
        std::cout << "3. Hilbert Curve" << std::endl;
        std::cout << "Type Exit to end program." << std::endl;
        std::cin >> input;

        if (input == "Exit") {
            break;
        }
        else if (input == "1") {
            //Insert Koch Snowflake functions here
            //of << koch_snowflake(order);
        }
        else if (input == "2") {
            std::ofstream of("C:\\Users\\amade\\OneDrive\\Desktop\\School\\Programming\\C++\\DSA\\sierpinski.txt");

            bool valid_input = false;
            std::string deg;
            int order;

            while (valid_input == false) {
                std::cout << "Enter the desired order of triangle you would like displayed" << std::endl;

                std::cin >> deg;

                bool check = true;

                for (int i = 0; i < deg.length(); i++) {
                    if (deg[i] != '0' && deg[i] != '1' && deg[i] != '2' && deg[i] != '3' && deg[i] != '4' && deg[i] != '5' && deg[i] != '6' && deg[i] != '7' && deg[i] != '8' && deg[i] != '9') {
                        check = false;
                    }
                }
                if (check == false || deg.length() > 2) {
                    std::cout << std::endl << "Invalid input, please try again\n" << std::endl;
                }
                else {
                    order = stoi(deg);
                    valid_input = true;
                }
            }

            std::string l_system = sierpinski_triangle(order, true);
            l_system += closing_time(order);


            of << l_system;
            //of<<drawTriangle(order);
        }
        else if (input == "3") {
            //Insert Hilbert Curve functions here
        }
        else {
            std::cout << std::endl << "Invalid input, please try again\n" << std::endl;
        }
    }

    std::cout << "Thank you for using our program" << std::endl;

    return 0;
}

std::string koch_snowflake(int iteration) {
    std::string commands = "";

    // This handles generating the 3 'sides' of the snowflake.
    for (int i = 0; i < 3; i++) {
        commands += snowflake(iteration);
        commands += "- - ";

    }

    return commands;
}

//Run plotter with 60 instead of 120
std::string snowflake(int order) {
    std::string curve;
    if (order == 0) {
        return "F ";
    }
    else {

        std::string commands = "";

        // Generate the repeating pattern for 60 orders

        //Left 60 orders
        commands += snowflake(order - 1);
        commands += "+ ";
        //Right 120 orders
        commands += snowflake(order - 1);
        commands += "- - ";
        //Left 60 orders
        commands += snowflake(order - 1);
        commands += "+ ";
        //Going through the function another time
        commands += snowflake(order - 1);

        // Return the generated commands.
        return commands;
    }
}
/* Run plotter with 120
 *
 * One iteration should create: F - F - F -
 *
 * Two: F - F + F + F - F - F F - F F
 *
 * Three: F - F + F + F - F - F F + F - F + F + F - F + F F - F - F + F + F - F - F F F F - F F F F
 *
 * Four: F - F + F + F - F - F F + F - F + F + F - F + F F - F - F + F + F - F - F F F F + F - F + F + F - F - F F + F - F + F + F - F + F F - F - F + F + F - F + F F F F - F - F + F + F - F - F F + F - F + F + F - F + F F - F - F + F + F - F - F F F F F F F F - F F F F F F F F
    Found repeating pattern 1: F - F + F + F - F - F F
    Other repeating pattern 2: F - F + F + F - F + F F
                            3: F F - F - F + F + F - F Inverse of first pattern
                            4: F F + F - F + F + F - F Inverse of second pattern
    Two uses pattern 1,  - , len # of F
    Three uses pattern 1, +, pattern 2, -, pattern 1, "F F - F F F F" (half of len # of F, -, len # of F)
    Four uses pattern 1, +, pattern 2, -, pattern 1, pattern 2 inverse, -, pattern 2 inverse, +, pattern 1 inverse,
    To close triangle:  - len # of F (?)
 bruh
    Found repeating pattern 1: F - F + F + F - F   (realized removing F F from patterns caused them all to be identical lol)
    closing formula:  -,  (F len number of times)
    Two uses pattern, closing formula, closing formula
    Three uses formula for 2 minus 1 closing formula, +, pattern, + half len # of F, -, pattern, closing formula, closing formula
    Four uses  formula for 3 minus closing 1 formula
*/
std::string sierpinski_triangle(int order, bool type) {
    //base
    if (order == 0) {
        return "F ";
    }

    // recursive case
    std::string pattern1;
    std::string pattern2;
    if (type) {
        pattern1 = sierpinski_triangle(order - 1, true);
        pattern2 = sierpinski_triangle(order - 1, false);
        return pattern1 + "- " + pattern2 + "+ " + pattern1 + "+ " + pattern2 + "- " + pattern1;
    }
    else {
        pattern2 = sierpinski_triangle(order - 1, false);
        return pattern2 + pattern2;
    }

}


//closing formula, not sure how to include it into recursion so its here instead
std::string closing_time(int order) {
    std::string closing = "";
    int len = std::pow(2, order);
    for (int j = 0; j < 2; j++) {
        closing += "- ";
        for (int i = 0; i < len; i++) {
            closing += "F ";
        }
    }
    return closing;
}
