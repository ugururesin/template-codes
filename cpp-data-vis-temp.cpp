#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <matplotlibcpp.h>

namespace plt = matplotlibcpp;

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
    std::string method;
    std::vector<double> x, y;
    std::vector<std::string> labels;

    std::cout << "Please enter a visualization method (line, scatter, bar, hist, pie): ";
    std::cin >> method;

    if (method == "line" || method == "scatter" || method == "bar") {
        std::cout << "Enter x values (separated by spaces): ";
        for (double value; std::cin >> value;) {
            x.push_back(value);
        }
        std::cin.clear();

        std::cout << "Enter y values (separated by spaces): ";
        for (double value; std::cin >> value;) {
            y.push_back(value);
        }
        std::cin.clear();

    } else if (method == "hist" || method == "pie") {
        std::cout << "Enter data values (separated by spaces): ";
        for (double value; std::cin >> value;) {
            x.push_back(value);
        }
        std::cin.clear();
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
