#ifndef MYCORDIC_H
#define MYCORDIC_H


// Change this to create a more precise algortihm
#define LUT_PRECISION 50



// declare x, y and d
double x;
double y;
bool d;
double counter;

// LUT that holds inverse tangents of powers 2^-1
std::array<double, LUT_PRECISION> lut;

// Populate array with values !!!! Multiply by *(180/M_PI) to convert to degrees
void populate_lut() { for(int i = 0; i < LUT_PRECISION; i++) lut[i] = atan(std::pow(2, -i))*(180/M_PI); }



void x_y_calculation()
{
    double x_temp = x;
    double y_temp = y;
    double divisor = std::pow(2, counter);
    if(d) x = ( x_temp -  (y_temp/divisor) );
    else  x = ( x_temp +  (y_temp/divisor) );
    if(d) y = ( y_temp +  (x_temp/divisor) );
    else  y = ( y_temp -  (x_temp/divisor) );
}



void calc_cordic(double angle)
{
    // Initialize x and y values
    counter = 0;
    x = 0.6072529350088812561694;
    y = 0.0;
    double original_angle = angle;

    if(angle > 270.0) angle = angle - 360;
    else if(angle > 90.0)  angle = angle - 180;
    else if(angle < -270.0) angle = angle + 360;
    else if(angle < -90.0) angle = angle + 180;
    
    
    for(auto each : lut)
    {
        if(angle >= 0)
        {
            d = true;
            angle = angle - each;
        }
        else
        {
            d = false;
            angle = angle + each;
        }
        
        x_y_calculation();
        counter++;
    }


    if(original_angle > 270.0)
    {
        ;
    }
    else if(original_angle > 90.0)
    {
        x = -1*x;
        y = -1*y;
    }
    else if(original_angle < -270.0)
    {
        ;
    }
    else if(original_angle < -90.0)
    {
        ;
    }

    // std::cout << " Cosine of " << original_angle << "\u02DA is : " << x << std::endl;
    // std::cout << " Sine of   " << original_angle << "\u02DA is : " << y << std::endl;

}
#endif // MYCORDIC_H
