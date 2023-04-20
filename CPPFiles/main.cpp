#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>

std::string koch_snowflake(int iteration);
std::string snowflake(int order);
std::string sierpinski_triangle(int order, bool type1);
std::string closing_time(int order);
std::string hilbert(int order, int sign);


int main() {

    std::string input = "";
    std::ofstream of("file");
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
        while (input != "1" && input != "2" && input != "3") {
            std::cout << "Enter 1, 2, or 3:" << std::endl;
            std::cin >> input;
        }
        if(input=="1"){
            std::cout<<"Enter degree of magnitude for the Koch Snowflake:"<<std::endl;
            int degree;
            std::cin>>degree;
            while (std::cin.fail() || (degree < 1 || degree > 10)) {
                std::cout << "Invalid input. Try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> degree;
            }
            std::string l_system = koch_snowflake(degree);
            of<<l_system;
        }
        else if(input=="2"){
            std::cout<<"Enter degree of magnitude for the Sierpinski Triangle:"<<std::endl;
            int degree;
            std::cin>>degree;
            while (std::cin.fail() || (degree < 1 || degree > 7)) {
                std::cout << "Invalid input. Try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> degree;
            }
            std::string l_system = sierpinski_triangle(degree, true);
            l_system+=closing_time(degree);
            of<<l_system;
        }

        else{
            std::cout<<"Enter degree of magnitude for the Hilbert Curve:"<<std::endl;
            int degree;
            std::cin>>degree;
            while (std::cin.fail() || (degree < 1 || degree > 7)) {
                std::cout << "Invalid input. Try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> degree;
            }
            std::string hil_string = hilbert(degree, 1);
            of<<hil_string;
        }
    }
    std::cout << "Thank you for using our program" << std::endl;
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
// Run plotter with 120

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

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>

std::string koch_snowflake(int iteration);
std::string snowflake(int order);
std::string sierpinski_triangle(int order, bool type1);
std::string closing_time(int order);
std::string hilbert(int order, int sign);


int main() {

    std::string input = "";
    std::ofstream of("file");
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
        while (input != "1" && input != "2" && input != "3") {
            std::cout << "Enter 1, 2, or 3:" << std::endl;
            std::cin >> input;
        }
        if(input=="1"){
            std::cout<<"Enter degree of magnitude for the Koch Snowflake:"<<std::endl;
            int degree;
            std::cin>>degree;
            while (std::cin.fail() || (degree < 1 || degree > 10)) {
                std::cout << "Invalid input. Try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> degree;
            }
            std::string l_system = koch_snowflake(degree);
            of<<l_system;
        }
        else if(input=="2"){
            std::cout<<"Enter degree of magnitude for the Sierpinski Triangle:"<<std::endl;
            int degree;
            std::cin>>degree;
            while (std::cin.fail() || (degree < 1 || degree > 7)) {
                std::cout << "Invalid input. Try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> degree;
            }
            std::string l_system = sierpinski_triangle(degree, true);
            l_system+=closing_time(degree);
            of<<l_system;
        }

        else{
            std::cout<<"Enter degree of magnitude for the Hilbert Curve:"<<std::endl;
            int degree;
            std::cin>>degree;
            while (std::cin.fail() || (degree < 1 || degree > 7)) {
                std::cout << "Invalid input. Try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> degree;
            }
            std::string hil_string = hilbert(degree, 1);
            of<<hil_string;
        }
    }
    std::cout << "Thank you for using our program" << std::endl;
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
// Run plotter with 120

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
//
std::string hilbert(int order, int sign) {
    if (order == 0) {
        return "F ";
    } else {
        std::string sub = hilbert(order - 1, -sign);
        std::string result = "";
        if (sign == 1) {
            result += "+ ";
        } else {
            result += "- ";
        }
        result += "F ";
        if (sign == 1) {
            result += "";
        } else {
            result += "- ";
        }
        result += sub;
        result += "F ";
        if (sign == 1) {
            result += "- ";
        } else {
            result += "";
        }
        result += "F ";
        result += sub;
        if (sign == 1) {
            result += "";
        } else {
            result += "- ";
        }
        result += "F ";
        if (sign == 1) {
            result += "- ";
        } else {
            result += "+ ";
        }
        result += sub;
        if (sign == 1) {
            result += "+ ";
        } else {
            result += "- ";
        }
        if (sign == 1) {
            result += "F ";
        } else {
            result += "";
        }
        return result;
    }
}

//90 degrees
//First order: F - F - F
// Second: - F + F + F - F F - F - F + F + F - F - F F - F + F + F
//           F - F - F + F F + F + F - F - F + F + F F + F - F - F
// F - F - F + F
// F + F + F - F
//Inverse, Regular, Regular, inverse
// Third: F - F - F + F F + F + F - F - F + F + F F + F - F - F F - F + F + F - F F - F - F + F + F - F - F F - F + F + F F F + F + F - F F - F - F + F + F - F - F F - F + F + F - F F - F - F + F F + F + F - F - F + F + F F + F - F - F
  //     1            1 2      1      2                        F -
  //     L -> +RF-LFL-FR+, R -> -LF+RFR+FL-                                                       - F
std::string hilbert(bool pattern, int order) {
    // base case
    if (order == 0) {
        return "";
    }
    // call the recursive method based on the boolean flag
    std::string pattern1;
    std::string pattern2;
    if (pattern) {
        pattern1 = hilbert(true, order - 1);
        pattern2 = hilbert(false, order - 1);
        return "+ "+pattern2 + "F - " + pattern1 + "F " + pattern1 + "- F " + pattern2+"+ ";
    } else {
        pattern1 = hilbert(true, order - 1);
        pattern2 = hilbert(false, order - 1);
        return "- "+ pattern1 + "F + " + pattern2 + "F " + pattern2 + "+ F " + pattern1+"- ";
    }
}
