#ifndef MYCORDIC_H
#define MYCORDIC_H


// Change this to create a more precise algortihm
#define LUT_PRECISION 20


namespace mycordic
{
    // scaling factor for x and y coordinates
    const double K = 0.6072529350088812561694;

    // angle to calculate SIN or COS of
    double angle = 30.0;

    // LUT that holds inverse tangents of powers 2^-1
    std::array<double, LUT_PRECISION> lut;

    // Populate array with values !!!! Multiply by *(180/M_PI) to convert to degrees
    void populate_lut() { for(int i = 0; i < LUT_PRECISION; i++) lut[i] = atan(std::pow(2, -i))*(180/M_PI); }


    void calc_cordic()
    {
        for(auto each : lut)
        {
            if(angle >= 0)
            {
                // std::cout << "  - " << std::endl;
                angle = angle - each;
            }
            else
            {
                // std::cout << "  + " << std::endl;
                angle = angle + each;
            }
        }
    }





}

#endif // MYCORDIC_H
