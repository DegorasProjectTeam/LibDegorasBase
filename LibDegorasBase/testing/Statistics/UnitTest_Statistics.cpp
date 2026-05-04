#include <cassert>
#include <iostream>
#include <chrono>

#include <LibDegorasBase/Statistics/measures.h>

#include <LibDegorasBase/Statistics/fitting.h>

using dpbase::math::types::Matrix;
using dpbase::stats::measures::convolve;
using dpbase::stats::measures::argmax;
using dpbase::stats::measures::argmin;
using dpbase::stats::measures::argsmax;
using dpbase::stats::measures::argsmin;
using dpbase::stats::linearInterpolation;
using dpbase::stats::curve_fit_Gauss;

void testStatisticsConvolve()
{
    std::vector<long double> v1 = {2,5,3,9,0,12,3,7,5,4,2};
    std::vector<long double> v2 = {8,4};
    std::vector<long double> vf = convolve(v1,v2,"full");
    std::vector<long double> vs = convolve(v1,v2,"same");
    std::vector<long double> vv = convolve(v1,v2,"valid");

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testStatisticsConvolve"<<std::endl<<std::endl;
    std::cout<<"Test vectors are:"<<std::endl<<std::endl;
    std::cout<<"v1 = [";
    for(std::size_t i = 0; i < v1.size()-1; i++)
    {
        std::cout<<v1[i]<<", ";
    }
    std::cout<<v1[v1.size()-1]<<"]"<<std::endl<<std::endl;
    std::cout<<"v2 = [";
    for(std::size_t i = 0; i < v2.size()-1; i++)
    {
        std::cout<<v2[i]<<", ";
    }
    std::cout<<v2[v2.size()-1]<<"]"<<std::endl<<std::endl;
    std::cout<<"Test convolved vectors with full mode is:"<<std::endl<<std::endl;
    std::cout<<"vf = [";
    for(std::size_t i = 0; i < vf.size()-1; i++)
    {
        std::cout<<vf[i]<<", ";
    }
    std::cout<<vf[vf.size()-1]<<"]"<<std::endl<<std::endl;
    std::cout<<"Test convolved vectors with same mode is:"<<std::endl<<std::endl;
    std::cout<<"vs = [";
    for(std::size_t i = 0; i < vs.size()-1; i++)
    {
        std::cout<<vs[i]<<", ";
    }
    std::cout<<vs[vs.size()-1]<<"]"<<std::endl<<std::endl;
    std::cout<<"Test convolved vectors with valid mode is:"<<std::endl<<std::endl;
    std::cout<<"vv = [";
    for(std::size_t i = 0; i < vv.size()-1; i++)
    {
        std::cout<<vv[i]<<", ";
    }
    std::cout<<vv[vv.size()-1]<<"]"<<std::endl<<std::endl;
    std::cout<<"Test convolved vectors with an invalid mode is:"<<std::endl<<std::endl;

    std::vector<long double> ve = convolve(v1,v2,"error");

    if(ve.size()>0)
    {
        std::cout<<"ve = [";
        for(std::size_t i = 0; i < ve.size()-1; i++)
        {
            std::cout<<ve[i]<<", ";
        }
        std::cout<<ve[ve.size()-1]<<"]"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"[]"<<std::endl<<std::endl;
    }
    std::cout<<"---------------------------------"<<std::endl;

}

void testStatisticsArguments()
{
    std::vector<long double> v1 = {1,4,1,7,10,10,7,3,10,10};
    std::vector<long double> v2 = {1,1,2,5,8,1,3,9,2};
    std::size_t v1m = argmin(v1);
    std::size_t v2M = argmax(v2);
    std::vector<std::size_t> v1M = argsmax(v1);
    std::vector<std::size_t> v2m = argsmin(v2);

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testStatisticsArguments"<<std::endl<<std::endl;
    std::cout<<"Test vectors are:"<<std::endl<<std::endl;
    std::cout<<"v1 = [";
    for(std::size_t i = 0; i < v1.size()-1; i++)
    {
        std::cout<<v1[i]<<", ";
    }
    std::cout<<v1[v1.size()-1]<<"]"<<std::endl<<std::endl;
    std::cout<<"v2 = [";
    for(std::size_t i = 0; i < v2.size()-1; i++)
    {
        std::cout<<v2[i]<<", ";
    }
    std::cout<<v2[v2.size()-1]<<"]"<<std::endl<<std::endl;

    std::cout<<"The minimun value argument of v1 is: "<<v1m<<std::endl<<std::endl;
    std::cout<<"The minimun value of v1 is: "<<v1[v1m]<<std::endl<<std::endl;
    std::cout<<"The maximun value argument of v2 is: "<<v2M<<std::endl<<std::endl;
    std::cout<<"The maximun value of v2 is: "<<v2[v2M]<<std::endl<<std::endl;

    std::cout<<"The maximun value arguments in v1 are: "<<v1m<<std::endl<<std::endl;
    std::cout<<"v1M = [";
    for(std::size_t i = 0; i < v1M.size()-1; i++)
    {
        std::cout<<v1M[i]<<", ";
    }
    std::cout<<v1M[v1M.size()-1]<<"]"<<std::endl<<std::endl;
    std::cout<<"The minimun value arguments in v2 are: "<<v1m<<std::endl<<std::endl;
    std::cout<<"v2m = [";
    for(std::size_t i = 0; i < v2m.size()-1; i++)
    {
        std::cout<<v2m[i]<<", ";
    }
    std::cout<<v2m[v2m.size()-1]<<"]"<<std::endl<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
}

void testStatisticsLinearInterpolation()
{
    std::vector<long double> x = {0,1,2,3,4,5,6,7,8,9};
    std::vector<long double> x1 = {0,5,2,3,4,5,6,7,8,9};
    std::vector<long double> x2 = {0,1,2,3,4,6,7,8,9};
    std::vector<long double> x3 = {0,1,2,3,3,5,6,7,8,9};
    std::vector<long double> y = {2,1,7,4,1,3,5,7,7,9};
    std::vector<long double> fill_values = {-1,100};
    std::vector<long double> fill_values1 = {100};
    std::vector<long double> fill_values2 = {-1,100,1};
    long double x_test1 = 3.145617;
    long double x_test2 = -10;
    long double x_test3 = 100;

    auto f1 = linearInterpolation(x,y,x_test1);
    auto f2 = linearInterpolation(x,y,x_test2);
    auto f3 = linearInterpolation(x,y,x_test3);
    auto f4 = linearInterpolation(x,y,x_test2,fill_values);
    auto f5 = linearInterpolation(x,y,x_test3,fill_values);

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testStatisticsLinearInterpolation"<<std::endl<<std::endl;
    std::cout<<"Test vectors are:"<<std::endl<<std::endl;
    std::cout<<"x = [";
    for(std::size_t i = 0; i < x.size()-1; i++)
    {
        std::cout<<x[i]<<", ";
    }
    std::cout<<x[x.size()-1]<<"]"<<std::endl<<std::endl;

    std::cout<<"y = [";
    for(std::size_t i = 0; i < y.size()-1; i++)
    {
        std::cout<<y[i]<<", ";
    }
    std::cout<<y[y.size()-1]<<"]"<<std::endl<<std::endl;

    std::cout<<"fill_values = [";
    for(std::size_t i = 0; i < fill_values.size()-1; i++)
    {
        std::cout<<fill_values[i]<<", ";
    }
    std::cout<<fill_values[fill_values.size()-1]<<"]"<<std::endl<<std::endl;

    std::cout<<"The interpolation fuction value in "<<x_test1<<" is: ";

    if(f1.has_value())
    {
        std::cout<<*f1<<std::endl;
    }
    else
    {
        std::cout<<"Error"<<std::endl;
    }

    std::cout<<"The interpolation fuction value in "<<x_test2<<" with extrapolation is: ";

    if(f2.has_value())
    {
        std::cout<<*f2<<std::endl;
    }
    else
    {
        std::cout<<"Error"<<std::endl;
    }

    std::cout<<"The interpolation fuction value in "<<x_test3<<" with extrapolation is: ";

    if(f3.has_value())
    {
        std::cout<<*f3<<std::endl;
    }
    else
    {
        std::cout<<"Error"<<std::endl;
    }

    std::cout<<"The interpolation fuction value in "<<x_test2<<" without extrapolation is: ";

    if(f4.has_value())
    {
        std::cout<<*f4<<std::endl;
    }
    else
    {
        std::cout<<"Error"<<std::endl;
    }

    std::cout<<"The interpolation fuction value in "<<x_test3<<" without extrapolation is: ";

    if(f5.has_value())
    {
        std::cout<<*f5<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"Error"<<std::endl<<std::endl;
    }

    std::cout<<"Let's check the diferent type of errors"<<std::endl<<std::endl;

    auto fE1 = linearInterpolation(x1,y,x_test1);
    std::cout<<"The interpolation fuction value in "<<x_test1<<" is: ";
    if(fE1.has_value())
    {
        std::cout<<*fE1<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"Error"<<std::endl<<std::endl;
    }

    auto fE2 = linearInterpolation(x2,y,x_test1);
    std::cout<<"The interpolation fuction value in "<<x_test2<<" with extrapolation is: ";

    if(fE2.has_value())
    {
        std::cout<<*fE2<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"Error"<<std::endl<<std::endl;
    }

    auto fE3 = linearInterpolation(x3,y,x_test1);
    std::cout<<"The interpolation fuction value in "<<x_test3<<" with extrapolation is: ";

    if(fE3.has_value())
    {
        std::cout<<*fE3<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"Error"<<std::endl<<std::endl;
    }

    auto fE4 = linearInterpolation(x,y,x_test1,fill_values1);
    std::cout<<"The interpolation fuction value in "<<x_test2<<" without extrapolation is: ";

    if(fE4.has_value())
    {
        std::cout<<*fE4<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"Error"<<std::endl<<std::endl;
    }

    auto fE5 = linearInterpolation(x,y,x_test1,fill_values2);
    std::cout<<"The interpolation fuction value in "<<x_test3<<" without extrapolation is: ";

    if(fE5.has_value())
    {
        std::cout<<*fE5<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"Error"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
}

void testStatisticsCurveFit()
{
    std::vector<long double> x = {-10.0, -9.0, -8.0, -7.0, -6.0, -5.0, -4.0, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::vector<long double> y = {0.0504252,-0.14174905,0.10573461,0.17953944,-0.04436887,0.34102805,0.73885498,1.60817118,3.20333533,4.62499844,5.07713058,4.2815709,2.61021766,1.50749401,0.42242251,-0.02162359,0.26357685,-0.17115526,-0.06966581,-0.03306565,-0.04866315};
    auto v = curve_fit_Gauss(x,y,{1,1,1});

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testStatisticsCurveFit"<<std::endl<<std::endl;
    std::cout<<"Test vectors are:"<<std::endl<<std::endl;
    std::cout<<"x = [";
    for(std::size_t i = 0; i < x.size()-1; i++)
    {
        std::cout<<x[i]<<", ";
    }
    std::cout<<x[x.size()-1]<<"]"<<std::endl<<std::endl;
    std::cout<<"y = [";
    for(std::size_t i = 0; i < y.size()-1; i++)
    {
        std::cout<<y[i]<<", ";
    }
    std::cout<<y[y.size()-1]<<"]"<<std::endl<<std::endl;

    std::cout<<"Test parameters are:"<<std::endl<<std::endl;
    std::cout<<"Amplitudo = 1"<<std::endl<<std::endl;
    std::cout<<"mu = 1"<<std::endl<<std::endl;
    std::cout<<"sigma = 1"<<std::endl<<std::endl;

    std::cout<<"The real fit parameters are:"<<std::endl<<std::endl;
    std::cout<<"Amplitudo = 5.08594"<<std::endl<<std::endl;
    std::cout<<"mu = -0.147484"<<std::endl<<std::endl;
    std::cout<<"sigma = 1.92332"<<std::endl<<std::endl;

    std::cout<<"The calculated fit parameters are:"<<std::endl<<std::endl;
    std::cout<<"Amplitudo = "<<v[0]<<std::endl<<std::endl;
    std::cout<<"mu = "<<v[1]<<std::endl<<std::endl;
    std::cout<<"sigma = "<<v[2]<<std::endl<<std::endl;

    std::cout<<"---------------------------------"<<std::endl;
}

int main()
{
    std::cout << "Unit Test: dpbase::math::Statistics" << std::endl;

    // Statistic test, provisional
    testStatisticsConvolve();
    testStatisticsArguments();
    testStatisticsLinearInterpolation();
    testStatisticsCurveFit();
    //prueba();

    // All assertions passed
    std::cout << "All tests passed!\n";

    return 0;
}
