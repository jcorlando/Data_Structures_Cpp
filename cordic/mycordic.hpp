#ifndef MYCORDIC_H
#define MYCORDIC_H


// Change this to create a more precise algortihm
#define LUT_PRECISION 20


namespace mycordic
{
    // scaling factor for x and y coordinates
    const double K = 0.6072529350088812561694;

    // declare x, y and d
    double x;
    double y;
    double d;
    double counter;

    // LUT that holds inverse tangents of powers 2^-1
    std::array<double, LUT_PRECISION> lut;

    // Populate array with values !!!! Multiply by *(180/M_PI) to convert to degrees
    void populate_lut() { for(int i = 0; i < LUT_PRECISION; i++) lut[i] = atan(std::pow(2, -i))*(180/M_PI); }



    void x_y_calculation()
    {
        double x_temp = x;
        double y_temp = y;
        std::cout << "  x   is  : " << x << std::endl;
        std::cout << "  y   is  : " << y << std::endl;
        std::cout << "x_temp is : " << x_temp << std::endl;
        std::cout << "y_temp is : " << y_temp << std::endl;
        std::cout << "  d   is  : " << d << std::endl;
        x = K*( x_temp - ( (d)*(y_temp)*(std::pow(2, -counter)) ) );
        y = K*( y_temp + ( (d)*(x_temp)*(std::pow(2, -counter)) ) );
    }



    void calc_cordic(double angle)
    {
        // Initialize x and y values
        counter = 0;  x = 1.0;  y = 0.0;
        
        for(auto each : lut)
        {
            std::cout << std::endl << "iteration : " << counter + 1 << std::endl << std::endl;
            if(angle >= 0)
            {
                d = 1.0;
                angle = angle - each;
            }
            else
            {
                d = -1.0;
                angle = angle + each;
            }
            
            x_y_calculation();
            counter++;
        }

    }





}
#endif // MYCORDIC_H
