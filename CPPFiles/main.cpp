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
    std::ofstream of("C:\\Users\\amade\\OneDrive\\Desktop\\School\\Programming\\C++\\DSA\\sierpinski.txt");
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
            //std::string l_system = sierpinski_triangle(degree, true);
            //l_system+=closing_time(degree);
            //
            // of<<l_system;
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
