#ifndef BMI_CALCULATOR_H
#define BMI_CALCULATOR_H

#include <string>

class BMICalculator {
public:
    
    BMICalculator();

   
    double calculate_bmi(int height_ft, int height_inch, int weight_lb);

    
    string get_bmi_category(double bmi);
};

#endif
