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

std::string sierpinski_triangle(int degree, int len){
    if(degree == 0){
        return "";
    }

    std::string commands = "";

    for(int i = 0; i < 3; i++){
        commands += sierpinski_triangle(degree - 1, len / 2);
        commands += "F" + std::string(degree, '+') + " ";
    }

    return commands;
}
