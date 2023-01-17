#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <matplotlibcpp.h>
#include <string>

namespace plt = matplotlibcpp;

/**
 * Function to visualize the data using the selected method
 * @param method : string containing the selected visualization method.
 * @param x : vector containing the x-axis data.
 * @param y : vector containing the y-axis data.
 * @param labels : vector containing the labels for each data value.
 */
void visualize(std::string method, std::vector<double> x, std::vector<double> y, std::vector<std::string> labels) {
    // Checking the selected method
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

    // Show the plot
    plt::show();
}

int main() {
    std::string method, fileName;
    std::vector<double> x, y;
    std::vector<std::string> labels;

    // Getting the file name from the user
    std::cout << "Please enter the name of the file to import data from: ";
    std::cin >> fileName;

    // Opening the file
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }

    // Getting the visualization method from the user
    std::cout << "Please enter a visualization method (line, scatter, bar, hist, pie): ";
    std::cin >> method;

    // Reading the data from the file
    if (method == "line" || method == "scatter" || method == "bar") {
        std::string line;
        // Reading the file line by line
        while (std::getline(file, line)) {
            std::string x_str, y_str;
            // Split the line by ','
            size_t pos = line.find(",");
            if (pos != std::string::npos) {
                x_str = line.substr(0, pos);
                y_str = line.substr(pos + 1);
                x.push_back(std::stod(x_str));
                y.push_back(std::stod(y_str));
            }
        }
    } else if (method == "hist" || method == "pie") {
        std::string line;
        // Reading the file line by line
        while (std::getline(file, line)) {
            x.push_back(std::stod(line));
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

    // Calling the visualize function to create the visualization
    visualize(method, x, y, labels);

    return 0;
}

