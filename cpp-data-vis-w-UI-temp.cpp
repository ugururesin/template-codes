#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <matplotlibcpp.h>

namespace plt = matplotlibcpp;

/*This program prompts the user to enter the name of a file to import data from,
 and then prompts the user to select a visualization method.
 It then reads the data from the file and stores it in the appropriate data structures (x, y, and labels)
 based on the selected method. Finally, it calls the visualize function to create the visualization.*/

/* In this code, the std::getline function reads the file line by line, 
and the std::stod function converts a string to a double. 

The code then checks the selected visualization method, and reads the data from the file accordingly. 
If the method is "pie", it prompts the user to enter labels for each data value. 
Finally, it calls the visualize function to create the visualization.*/


void visualize(std::string method, std::vector<double> x, std::vector<double> y, std::vector<std::string> labels) {
    if (method == "line") {
        plt::plot(x, y);
    } else if (method == "scatter") {
        plt::scatter(x, y);
    } else if (method == "bar") {
        plt::bar(x, y);
    } else if (method == "hist") {
        plt::hist(x);
    } else if (method == "pie") {
        plt::pie(x, labels);
    } else {
        std::cout << "Invalid visualization method selected." << std::endl;
    }

    plt::show();
}

int main() {
    std::string method, fileName;
    std::vector<double> x, y;
    std::vector<std::string> labels;

    std::cout << "Please enter the name of the file to import data from: ";
    std::cin >> fileName;

    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }

    std::cout << "Please enter a visualization method (line, scatter, bar, hist, pie): ";
    std::cin >> method;

    if (method == "line" || method == "scatter" || method == "bar") {
        while (file >> x >> y) {
            x.push_back(x);
            y.push_back(y);
        }
    } else if (method == "hist" || method == "pie") {
        double data;
        while (file >> data) {
            x.push_back(data);
        }
    }

    if (method == "pie") {
        std::cout << "Enter labels for each data value (separated by spaces): ";
        std::string label;
        while (std::cin >> label) {
            labels.push_back(label);
        }
        std::cin.clear();
    }

    visualize(method, x, y, labels);

    return 0;
}
