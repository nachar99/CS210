// Abdulrahman Al-Nachar

// I added the necessary libraries to open the and close the file
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// this is the function to convert from fahrenheit to celsius
double Conversion(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {

    // these two lines of code is to open and input from a file and output to another file
    ifstream inputFile("C:\\Users\\Abdulrahman\\source\\repos\\FahrenheitConversion\\FahrenheitConversion\\FahrenheitTemperature.txt");
    ofstream outputFile("CelsiusTemperature.txt");

    // I know these variables are repetitive but its what the instructions said so I am following instructions
    string city1;
    string city2;
    string city3;
    string city4;
    string city5;
    string city6;
    double fahrenheit1;
    double fahrenheit2;
    double fahrenheit3;
    double fahrenheit4;
    double fahrenheit5;
    double fahrenheit6;
    double celsius1;
    double celsius2;
    double celsius3;
    double celsius4;
    double celsius5;
    double celsius6;

    // this is to input the data from the input file
    inputFile >> city1 >> fahrenheit1;
    inputFile >> city2 >> fahrenheit2;
    inputFile >> city3 >> fahrenheit3;
    inputFile >> city4 >> fahrenheit4;
    inputFile >> city5 >> fahrenheit5;
    inputFile >> city6 >> fahrenheit6;

    // this to convert the fahrenheit data from the file to celsius 
    celsius1 = Conversion(fahrenheit1);
    celsius2 = Conversion(fahrenheit2);
    celsius3 = Conversion(fahrenheit3);
    celsius4 = Conversion(fahrenheit4);
    celsius5 = Conversion(fahrenheit5);
    celsius6 = Conversion(fahrenheit6);

    // this to close the file
    inputFile.close();

    // this to output the city name and the converted data into the new file
    outputFile << fixed << city1 << " " << celsius1 << endl;
    outputFile << fixed << city2 << " " << celsius2 << endl;
    outputFile << fixed << city3 << " " << celsius3 << endl;
    outputFile << fixed << city4 << " " << celsius4 << endl;
    outputFile << fixed << city5 << " " << celsius5 << endl;
    outputFile << fixed << city6 << " " << celsius6 << endl;

    // this to close the output file after it had been edited
    outputFile.close();


    return 0;
}
