#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

// Conversion constants
const double POUNDS_TO_KG = 0.45359237;
const double INCHES_TO_METERS = 0.0254;

class BMICalculator {
public:
    // Constructor
    BMICalculator() {}

    // Method to calculate BMI using pounds and inches
    double calculate_bmi(int height_ft, int height_inch, int weight_lb) {
        // Convert height to inches (height is already in inches)
        int total_height_inch = height_ft * 12 + height_inch;

        // Convert weight to kilograms
        double weight_kg = weight_lb * POUNDS_TO_KG;

        // Convert height to meters
        double height_meters = total_height_inch * INCHES_TO_METERS;

        // Calculate BMI (weight in kg divided by the square of height in meters)
        double bmi = weight_kg / (height_meters * height_meters);

        // Round to one decimal place
        return round(bmi * 10) / 10.0;
    }

    // Method to return the BMI category
    string get_bmi_category(double bmi) {
        if (bmi < 18.5) {
            return "Underweight";
        } else if (bmi >= 18.5 && bmi < 25) {
            return "Normal weight";
        } else if (bmi >= 25 && bmi < 30) {
            return "Overweight";
        } else {
            return "Obese";
        }
    }
};

int main() {
    BMICalculator bmi_calculator;

    // Input variables
    int height_ft, height_inch, weight_lb;

    // Prompt user for input
    cout << "Enter height in feet: ";
    cin >> height_ft;

    cout << "Enter height in inches: ";
    cin >> height_inch;

    cout << "Enter weight in pounds: ";
    cin >> weight_lb;

    // Calculate BMI
    double bmi = bmi_calculator.calculate_bmi(height_ft, height_inch, weight_lb);

    // Get BMI category
    string category = bmi_calculator.get_bmi_category(bmi);

    // Output result with one decimal precision
    cout << "Your BMI is: " << fixed << setprecision(1) << bmi << "\n";
    cout << "This is classified as: " << category << "\n";

    return 0;
}
