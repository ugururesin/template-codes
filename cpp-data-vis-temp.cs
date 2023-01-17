using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using System.IO;

class Program
{
    static void Main(string[] args)
    {
        string method;
        List<double> x = new List<double>();
        List<double> y = new List<double>();
        List<string> labels = new List<string>();

        Console.WriteLine("Please enter the name of the file to import data from: ");
        string fileName = Console.ReadLine();

        try
        {
            using (StreamReader sr = new StreamReader(fileName))
            {
                Console.WriteLine("Please enter a visualization method (line, scatter, bar, hist, pie): ");
                method = Console.ReadLine();

                if (method == "line" || method == "scatter" || method == "bar")
                {
                    string line;
                    while ((line = sr.ReadLine()) != null)
                    {
                        var values = line.Split(',');
                        x.Add(Convert.ToDouble(values[0]));
                        y.Add(Convert.ToDouble(values[1]));
                    }
                }
                else if (method == "hist" || method == "pie")
                {
                    string line;
                    while ((line = sr.ReadLine()) != null)
                    {
                        x.Add(Convert.ToDouble(line));
                    }
                }
            }
        }
        catch (Exception e)
        {
            Console.WriteLine("Error reading the file: " + e.Message);
        }

        if (method == "pie")
        {
            Console.WriteLine("Enter labels for each data value (separated by spaces): ");
            string label;
            while ((label = Console.ReadLine()) != null)
            {
                labels.Add(label);
            }
        }

        // Visualizing the data
        Visualize(method, x, y, labels);
    }

    static void Visualize(string method, List<double> x, List<double> y, List<string> labels)
    {
        // Checking the selected method
        if (method == "line")
        {
            // Plotting line graph
            // code for plotting line graph
        }
        else if (method == "scatter")
        {
            // Plotting scatter graph
            // code for plotting scatter graph
        }
        else if (method == "bar")
        {
            // Plotting bar graph
            // code for plotting bar graph
        }
        else
			static void Visualize(string method, List<double> x, List<double> y, List<string> labels)
    {
        // Checking the selected method
        if (method == "line")
        {
            // Plotting line graph
            // code for plotting line graph
        }
        else if (method == "scatter")
        {
            // Plotting scatter graph
            // code for plotting scatter graph
        }
        else if (method == "bar")
        {
            // Plotting bar graph
            // code for plotting bar graph
        }
        else if (method == "hist")
        {
            // Plotting histogram
            // code for plotting histogram
        }
        else if (method == "pie")
        {
            // Plotting pie chart
            // code for plotting pie chart
        }
        else
        {
            Console.WriteLine("Invalid visualization method selected.");
        }
    }
}

