#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>

std::string koch_snowflake(int iteration);
std::string snowflake(int order);
std::string sierpinski_triangle(int order, bool type1);
std::string closing_time(int order);
std::string hilbert(bool pattern, int order);
std::string dragon(int order, bool type);
std::string peano_gosper(int order, bool type);
std::string hilbert_curve2(int order, bool type);
std::string square(int order);
std::string schrad( int order);

int main() {

    std::string input = "";
    std::ofstream of("file");

    std::cout << "Enter the corresponding number to the Recursive Graphic you would like to use:" << std::endl;
    std::cout << "1. Koch Snowflake"      << std::endl;
    std::cout << "2. Sierpinski Triangle" << std::endl;
    std::cout << "3. Hilbert Curve"       << std::endl;
    std::cout << "4. Dragon Curve"        << std::endl;
    std::cout << "5. Peano Gosper"        << std::endl;
    std::cout << "6. Hilbert Curve II"    << std::endl;
    std::cout << "7. Square Curve"        << std::endl;
    std::cout << "8. Schraders Structure" << std::endl;

    std::cin >> input;

    while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "7" && input != "8") {
        std::cout << "Enter 1, 2, 3, 4, 5, 6, 7, or 8:" << std::endl;
        std::cin >> input;
    }
    // Runs Koch Snowflake if user enters 1
    if (input == "1") {
        std::cout << "Enter a degree of magnitude that is any integer from 0 to 10 for the Koch Snowflake:" << std::endl;
        int degree;
        std::cin >> degree;
        while (std::cin.fail() || (degree < 0 || degree > 10)) {
            std::cout << "Invalid input. The magnitude should be an integer that is in the range of 0 to 10. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> degree;
        }
        std::string l_system = koch_snowflake(degree);
        of << l_system;
    }
    // Runs Sierpinski Triangle if user enters 2
    else if (input == "2") {
        std::cout << "Enter a degree of magnitude that is any integer from 1 to 7 for the Sierpinski Triangle:" << std::endl;
        int degree;
        std::cin >> degree;
        while (std::cin.fail() || (degree < 1 || degree > 7)) {
            std::cout << "Invalid input. The magnitude should be an integer that is in the range of 1 to 7. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> degree;
        }
        std::string l_system = sierpinski_triangle(degree, true);
        l_system += closing_time(degree);
        of << l_system;
    } 
    // Runs Hilbert Curve if user enters 3
    else if (input == "3") {
        std::cout << "Enter a degree of magnitude that is any integer from 1 to 7 for the Hilbert Curve:" << std::endl;
        int degree;
        std::cin >> degree;
        while (std::cin.fail() || (degree < 1 || degree > 7)) {
            std::cout << "Invalid input. The magnitude should be an integer that is in the range of 1 to 7. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> degree;
        }
        std::string hil_string = hilbert(1, degree);
        of << hil_string;
    }
    // Runs Dragon Curve if user enters 4
    else if (input == "4") {
        std::cout << "Enter a degree of magnitude that is any integer from 10 to 20 for the Dragon Curve:" << std::endl;
        int degree;
        std::cin >> degree;
        while (std::cin.fail() || (degree < 10 || degree > 20)) {
            std::cout << "Invalid input. The magnitude should be an integer is in the range of 10 to 20. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> degree;
        }
        std::string output = dragon(degree, true);
        of << output;
    } 
    // Runs Peano Gosper if user enters 5
    else if (input == "5") {
        std::cout << "Enter a degree of magnitude that is any integer from 0 to 10 for the Peano Gosper:" << std::endl;
        int degree;
        std::cin >> degree;
        while (std::cin.fail() || (degree < 0 || degree > 10)) {
            std::cout << "Invalid input. The magnitude should be an integer that is in the range of 0 to 10. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> degree;
        }
        std::string output = peano_gosper(degree, true);
        of << output;
    } 
    // Runs Hilbert Curve II if user enters 6
    else if (input == "6") {
        std::cout << "Enter a degree of magnitude that is any intenger from 0 to 6 for the Hilbert Curve II:" << std::endl;
        int degree;
        std::cin >> degree;
        while (std::cin.fail() || (degree < 0 || degree > 6)) {
            std::cout << "Invalid input. The magnitude should be an integer that is in the range of 0 to 6. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> degree;
        }
        std::string output = hilbert_curve2(degree, true);
        of << output;
    }
    // Runs Square Curve if user enters 7
    else if (input == "7") {
        std::cout << "Enter a degree of magnitude that is any integer from 4 to 8 for the Square curve:" << std::endl;
        int degree;
        std::cin >> degree;
        while (std::cin.fail() || (degree < 4 || degree > 8)) {
            std::cout << "Invalid input. The magnitude should be an integer that is in the range of 4 to 8. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> degree;
        }
        std::string output = square(degree);
        of << output;
    }
    // Runs Schraders Structure if user enters 8
    else if (input == "8") {
        std::cout << "Enter a degree of magnitude that is any integer from 1 to 8 for the Schraders Structure:" << std::endl;
        int degree;
        std::cin >> degree;
        while (std::cin.fail() || (degree < 4 || degree > 8)) {
            std::cout << "Invalid input. The magnitude should be an integer that is in the range of 1 to 8. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> degree;
        }
        std::string output = schrad(degree);
        of << output;
    }

    // Tells the user what degree to enter when using the plotter based off their chosen graphic
    if (input == "1"){
        std::cout << "Run the plotter with 60 degrees" << std::endl;
    } else if (input == "2"){
        std::cout << "Run the plotter with 120 degrees" << std::endl;
    } else if (input == "3"){
        std::cout << "Run the plotter with 90 degrees" << std::endl;
    } else if (input == "4"){
        std::cout << "Run the plotter with 90 degrees" << std::endl;
    } else if (input == "5"){
        std::cout << "Run the plotter with 60 degrees" << std::endl;
    } else if (input == "6"){
        std::cout << "Run the plotter with 90 degrees" << std::endl;
    } else if (input == "7"){
        std::cout << "Run the plotter with 90 degrees" << std::endl;
    } else if (input == "8"){
        std::cout << "Run the plotter with 60 degrees" << std::endl;
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

        // Generate the repeating pattern for the current side(which should be the iteration of the loop in the koch_snowflake function)

        //Left 60 degrees
        commands += snowflake(order - 1);
        commands += "+ ";
        //Right 120 degrees
        commands += snowflake(order - 1);
        commands += "- - ";
        //Left 60 degrees
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

std::string dragon(int order, bool type){
    if (order == 0) return "";
    std::string pattern1;
    std::string pattern2;

    if (type){
        pattern1 = dragon(order - 1, true);
        pattern2 = dragon(order - 1, false);
        return pattern1 + "+" + pattern2 + "F + ";
    }
    else{
        pattern1 = dragon(order - 1, true);
        pattern2 = dragon(order - 1,false);
        return "- F " + pattern1 + "-" + pattern2;
    }
}

//60 degree plotter
//(X -> X+YF++YF-FX--FXFX-YF+, Y -> -FX+YFYF++YF+FX--FX-Y, 60°):
std::string peano_gosper(int order, bool type) {
    if (order == 0) {
        return "";
    }
    std::string pattern1;
    std::string pattern2;
    if (type) {
        pattern1 = peano_gosper(order - 1, true);
        pattern2 = peano_gosper(order - 1, false);
        return pattern1 + "+" + pattern2 + "F++" + pattern2 + "F-F" + pattern1 + "--F" + pattern1 + "F" + pattern1 + "-" + pattern2 + "F+";
    }
    else{
        pattern1 = peano_gosper(order - 1, true);
        pattern2 = peano_gosper(order - 1, false);
        return "-F" + pattern1 + "+" + pattern2 + "F" + pattern2 + "F++" + pattern2 + "F+F" + pattern1 + "--F" + pattern1 + "-" + pattern2;
    }
}

//90 degree plotter
//X -> XFYFX+F+YFXFY-F-XFYFX, Y -> YFXFY-F-XFYFX+F+YFXFY):
std::string hilbert_curve2(int order, bool type){
    if (order == 0) return "";

    std::string pattern1;
    std::string pattern2;
    if (type){
        pattern1 = hilbert_curve2(order - 1, true);
        pattern2 = hilbert_curve2(order - 1, false);
        return pattern1 + "F" + pattern2 + "F" + pattern1 + "+F+" + pattern2 + "F" + pattern1 + "F" + pattern2 + "-F-" + pattern1 + "F" + pattern2 + "F" + pattern1;
    }
    else{
        pattern1 = hilbert_curve2(order - 1, true);
        pattern2 = hilbert_curve2(order - 1, false);
        return pattern2 + "F" + pattern1 + "F" + pattern2 + "-F-" + pattern1 + "F" + pattern2 + "F" + pattern1 + "+F+" + pattern2 + "F" + pattern1 + "F" + pattern2;
    }
}

//X -> XF-F+F-XF+F+XF-F+F-X
//90 Degree Plotter
std::string square(int order) {
    std::string pattern1;
    if (order == 0) {
        return "";
    }
    else{
        pattern1 = square(order -1);
        return pattern1 + "F-F+F-" + pattern1 + "F+F+" + pattern1 + "F-F+F-" + pattern1;
    }
}

//60 Degree plotter
std::string schrad( int order) {
    if ( order == 0){
        return "F";
    }
    std::string prev = schrad(order -1);
    std::string result  = "";
    for( int i =0; i < prev.length(); i++){
        if(prev[i] == 'F'){
            result += "FF++F-F-F--F+F+F";
        }
        else{
            result += prev[i];
        }
    }
    return result;
}
