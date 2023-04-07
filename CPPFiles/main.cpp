#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

std::string koch_snowflake(int degree);
std::string snowflake(int degree);
std::string sierpinski_triangle(int degree, int len);

int main(){
    std::ofstream of("l-system.txt");

    int degree = 3;

    //of << koch_snowflake(degree);
    of << sierpinski_triangle(degree, std::pow(2, degree - 1));

    return 0;
}

std::string koch_snowflake(int degree){
    std::string commands = "";

    for(int i = 0; i < 3; i++){
        commands += snowflake(degree);
        commands += "+ + ";
    }

    return commands;
}

std::string snowflake(int degree){
    if(degree == 0){
        return "F ";
    }
    std::string commands = "";

    std::string snowflake1 = snowflake(degree - 1);
    for (char c : snowflake1) {
        if (c == 'F') {
            commands += "F+F--F+F ";
        } else {
            commands += c;
        }
    }

    return commands;
}

/*
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
    
 * One iteration should create: F - F - F
 *
 * Two: F - F + F + F - F - F F - F F
 *
 * Three: F - F + F + F - F - F F + F - F + F + F - F + F F - F - F + F + F - F - F F F F - F F F F
 *
 * Four: F - F + F + F - F - F F + F - F + F + F - F + F F - F - F + F + F - F - F F F F + F - F + F + F - F - F F + F - F + F + F - F + F F - F - F + F + F - F + F F F F - F - F + F + F - F - F F + F - F + F + F - F + F F - F - F + F + F - F - F F F F F F F F - F F F F F F F F

    Found repeating pattern 1: F - F + F + F - F   (realized removing F F from patterns caused them all to be identical lol tf)

    One uses... F - F closing formula //todo i mean i guess?

    closing formula:  -,  (F len number of times)

    Two uses pattern, closing formula, closing formula
    Three uses formula for 2 minus 1 closing formula, +, pattern, + half len # of F, -, pattern, closing formula, closing formula
    Four uses  formula for 3 minus closing 1 formula
    )
*/
std::string sierpinski_triangle(int degree, int len){
    if(degree == 0){
        return "";
    }


    std::string commands = "";
    std::cout<<len<<std::endl;
    // 3 sides to every triangle
    for(int i = 0; i < 3; i++){
        // Hint: Recurse here!
        sierpinski_triangle(degree-1,len);
        // Hint: Draw a line of the correct dimensions here!
        commands+="F - ";

    }
    for(int j=0;j<2;j++) {
        commands += '- ';
        for (int i = 0; i < len; i++) {
            commands += "F ";
        }
    }
    return commands;
}
