#include "bmi_calculator.h"
#include <cmath>
#include <string>

using namespace std;

BMICalculator::BMICalculator() {}

double BMICalculator::calculate_bmi(int height_ft, int height_inch, int weight_lb) {
    // Convert height to inches (height is already in inches)
    int total_height_inch = height_ft * 12 + height_inch;

    // Step 1: Convert weight to kilograms (1 lb = 0.45 kg)
    double weight_kg = weight_lb * 0.45;

    // Step 2: Convert height to meters (1 inch = 0.0254 meters)
    double height_meters = total_height_inch * 0.0254;

    // Step 3: Square the height in meters
    double height_squared = height_meters * height_meters;

    // Step 4: Calculate BMI
    double bmi = weight_kg / height_squared;

    return round(bmi * 10) / 10.0; // Round to one decimal place
}

string BMICalculator::get_bmi_category(double bmi) {
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
