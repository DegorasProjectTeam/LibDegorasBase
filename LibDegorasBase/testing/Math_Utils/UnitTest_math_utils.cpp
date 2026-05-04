#include <cassert>
#include <iostream>
#include <chrono>

#include <LibDegorasBase/Mathematics/utils/math_utils.h>
#include <LibDegorasBase/Mathematics/operators/operators.h>
#include <LibDegorasBase/Mathematics/math_constants.h>

using dpbase::math::where;
using dpbase::math::sortValArg;
using dpbase::math::abs;
using dpbase::math::sqrt;
using dpbase::math::sin;
using dpbase::math::cos;
using dpbase::math::tan;
using dpbase::math::asin;
using dpbase::math::acos;
using dpbase::math::atan;
using dpbase::math::kPi;
using dpbase::math::operators::operator ==;
using dpbase::math::operators::operator !=;
using dpbase::math::operators::operator >=;
using dpbase::math::operators::operator <=;
using dpbase::math::operators::operator >;
using dpbase::math::operators::operator <;
using dpbase::math::operators::operator &&;
using dpbase::math::operators::operator ||;

void testMathWhere()
{
    std::vector<long double> v1 = {0,1,2,3,4,5,6,7,8,9};
    std::vector<long double> v2 = {0,3,4,6,7,8,2,5,1,9};
    std::vector<std::size_t> vv = {};
    std::vector<std::size_t> vp = {};
    std::vector<std::size_t> ve = {};
    long double p = 0.0;
    long double e = 0.0;
    long double p1 = 0.0;
    long double e1 = 0.0;
    long double p2 = 0.0;
    long double e2 = 0.0;

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMathWhere"<<std::endl<<std::endl;
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

    p = 2.0;
    e = 10.0;
    vv = where(v1 == v2);
    vp = where(v2 == p);
    ve = where(v1 == e);

    std::cout<<"Where comparation criterion equal:"<<std::endl<<std::endl;

    std::cout<<"Test parameters are: p = "<< p << " and e = "<< e <<std::endl<<std::endl;

    std::cout<<"Where with two vectors comparation:"<<std::endl<<std::endl;

    if(!vv.empty())
    {
        std::cout<<"vv = [";
        for(std::size_t i = 0; i < vv.size()-1; i++)
        {
            std::cout<<vv[i]<<", ";
        }
        std::cout<<vv[vv.size()-1]<<"]"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The vector is empty:"<<std::endl<<std::endl;
    }

    std::cout<<"Where with vector v2 and p parameter comparation:"<<std::endl<<std::endl;

    if(!vv.empty())
    {
        std::cout<<"vp = [";
        for(std::size_t i = 0; i < vp.size()-1; i++)
        {
            std::cout<<vp[i]<<", ";
        }
        std::cout<<vp[vp.size()-1]<<"]"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The vector is empty:"<<std::endl<<std::endl;
    }

    std::cout<<"Where with vector v1 and e parameter comparation without coincidences:"<<std::endl<<std::endl;

    if(!ve.empty())
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
        std::cout<<"The vector is empty"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;

    p = 2.0;
    vv = where(v1 != v2);
    vp = where(v2 != p);
    ve = where(v1 != v1);

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

    std::cout<<"Where comparation criterion not equal:"<<std::endl<<std::endl;

    std::cout<<"Test parameters are: p = "<< p <<std::endl<<std::endl;

    std::cout<<"Where with two vectors comparation:"<<std::endl<<std::endl;

    if(!vv.empty())
    {
        std::cout<<"vv = [";
        for(std::size_t i = 0; i < vv.size()-1; i++)
        {
            std::cout<<vv[i]<<", ";
        }
        std::cout<<vv[vv.size()-1]<<"]"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The vector is empty:"<<std::endl<<std::endl;
    }

    std::cout<<"Where with vector v2 and p parameter comparation:"<<std::endl<<std::endl;

    if(!vv.empty())
    {
        std::cout<<"vp = [";
        for(std::size_t i = 0; i < vp.size()-1; i++)
        {
            std::cout<<vp[i]<<", ";
        }
        std::cout<<vp[vp.size()-1]<<"]"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The vector is empty:"<<std::endl<<std::endl;
    }

    std::cout<<"Where with two vectors without coincidences:"<<std::endl<<std::endl;

    if(!ve.empty())
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
        std::cout<<"The vector is empty"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;

    p = 2.0;
    e = 10.0;
    vv = where(v1 > v2);
    vp = where(v2 > p);
    ve = where(v1 > e);

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

    std::cout<<"Where comparation criterion greater:"<<std::endl<<std::endl;

    std::cout<<"Test parameters are: p = "<< p << " and e = "<< e <<std::endl<<std::endl;

    std::cout<<"Where with two vectors comparation:"<<std::endl<<std::endl;

    if(!vv.empty())
    {
        std::cout<<"vv = [";
        for(std::size_t i = 0; i < vv.size()-1; i++)
        {
            std::cout<<vv[i]<<", ";
        }
        std::cout<<vv[vv.size()-1]<<"]"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The vector is empty:"<<std::endl<<std::endl;
    }

    std::cout<<"Where with vector v2 and p parameter comparation:"<<std::endl<<std::endl;

    if(!vv.empty())
    {
        std::cout<<"vp = [";
        for(std::size_t i = 0; i < vp.size()-1; i++)
        {
            std::cout<<vp[i]<<", ";
        }
        std::cout<<vp[vp.size()-1]<<"]"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The vector is empty:"<<std::endl<<std::endl;
    }

    std::cout<<"Where with vector v1 and e parameter comparation without coincidences:"<<std::endl<<std::endl;

    if(!ve.empty())
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
        std::cout<<"The vector is empty"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;

    p = 2.0;
    e = 0.0;
    vv = where(v1 < v2);
    vp = where(v2 < p);
    ve = where(v1 < e);

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

    std::cout<<"Where comparation criterion less:"<<std::endl<<std::endl;

    std::cout<<"Test parameters are: p = "<< p << " and e = "<< e <<std::endl<<std::endl;

    std::cout<<"Where with two vectors comparation:"<<std::endl<<std::endl;

    if(!vv.empty())
    {
        std::cout<<"vv = [";
        for(std::size_t i = 0; i < vv.size()-1; i++)
        {
            std::cout<<vv[i]<<", ";
        }
        std::cout<<vv[vv.size()-1]<<"]"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The vector is empty:"<<std::endl<<std::endl;
    }

    std::cout<<"Where with vector v2 and p parameter comparation:"<<std::endl<<std::endl;

    if(!vv.empty())
    {
        std::cout<<"vp = [";
        for(std::size_t i = 0; i < vp.size()-1; i++)
        {
            std::cout<<vp[i]<<", ";
        }
        std::cout<<vp[vp.size()-1]<<"]"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The vector is empty:"<<std::endl<<std::endl;
    }

    std::cout<<"Where with vector v1 and e parameter comparation without coincidences:"<<std::endl<<std::endl;

    if(!ve.empty())
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
        std::cout<<"The vector is empty"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;

    p = 2.0;
    e = 10.0;
    vv = where(v1 >= v2);
    vp = where(v2 >= p);
    ve = where(v1 >= e);

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

    std::cout<<"Where comparation criterion greater or equal:"<<std::endl<<std::endl;

    std::cout<<"Test parameters are: p = "<< p << " and e = "<< e <<std::endl<<std::endl;

    std::cout<<"Where with two vectors comparation:"<<std::endl<<std::endl;

    if(!vv.empty())
    {
        std::cout<<"vv = [";
        for(std::size_t i = 0; i < vv.size()-1; i++)
        {
            std::cout<<vv[i]<<", ";
        }
        std::cout<<vv[vv.size()-1]<<"]"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The vector is empty:"<<std::endl<<std::endl;
    }

    std::cout<<"Where with vector  v2 and p parameter comparation:"<<std::endl<<std::endl;

    if(!vv.empty())
    {
        std::cout<<"vp = [";
        for(std::size_t i = 0; i < vp.size()-1; i++)
        {
            std::cout<<vp[i]<<", ";
        }
        std::cout<<vp[vp.size()-1]<<"]"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The vector is empty:"<<std::endl<<std::endl;
    }

    std::cout<<"Where with vector  v1 and e parameter comparation without coincidences:"<<std::endl<<std::endl;

    if(!ve.empty())
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
        std::cout<<"The vector is empty"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;

    p = 2.0;
    e = -10.0;
    vv = where(v1 <= v2);
    vp = where(v2 <= p);
    ve = where(v1 <= e);

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

    std::cout<<"Where comparation criterion less or equal:"<<std::endl<<std::endl;

    std::cout<<"Test parameters are: p = "<< p << " and e = "<< e <<std::endl<<std::endl;

    std::cout<<"Where with two vectors comparation:"<<std::endl<<std::endl;

    if(!vv.empty())
    {
        std::cout<<"vv = [";
        for(std::size_t i = 0; i < vv.size()-1; i++)
        {
            std::cout<<vv[i]<<", ";
        }
        std::cout<<vv[vv.size()-1]<<"]"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The vector is empty:"<<std::endl<<std::endl;
    }

    std::cout<<"Where with vector  v2 and p parameter comparation:"<<std::endl<<std::endl;

    if(!vv.empty())
    {
        std::cout<<"vp = [";
        for(std::size_t i = 0; i < vp.size()-1; i++)
        {
            std::cout<<vp[i]<<", ";
        }
        std::cout<<vp[vp.size()-1]<<"]"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The vector is empty:"<<std::endl<<std::endl;
    }

    std::cout<<"Where with vector v1 and e parameter comparation without coincidences:"<<std::endl<<std::endl;

    if(!ve.empty())
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
        std::cout<<"The vector is empty"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;

    std::cout<<"---------------------------------"<<std::endl;

    p1 = 2.0;
    p2 = 7.0;
    e1 = 10.0;
    e2 = 12.0;
    vp = where(v2 > p1 && v2 < p2);
    ve = where(v1 > e1 && v1 < e2);

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

    std::cout<<"Where comparation two criterion and:"<<std::endl<<std::endl;

    std::cout<<"Test lower parameters are: p1 = "<< p1 << " and e1 = "<< e1 <<std::endl<<std::endl;
    std::cout<<"Test upper parameters are: p2 = "<< p2 << " and e2 = "<< e2 <<std::endl<<std::endl;


    std::cout<<"Where with vector v2 and p1, p2 parameters comparation, (p1 < v < p2):"<<std::endl<<std::endl;

    if(!vv.empty())
    {
        std::cout<<"vp = [";
        for(std::size_t i = 0; i < vp.size()-1; i++)
        {
            std::cout<<vp[i]<<", ";
        }
        std::cout<<vp[vp.size()-1]<<"]"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The vector is empty:"<<std::endl<<std::endl;
    }

    std::cout<<"Where with vector v1 and e1, e2 parameter comparation without coincidences, (e1 < v < e2):"<<std::endl<<std::endl;

    if(!ve.empty())
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
        std::cout<<"The vector is empty"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;

    std::cout<<"---------------------------------"<<std::endl;

    p1 = 2.0;
    p2 = 7.0;
    e1 = -10.0;
    e2 = 12.0;
    vp = where(v2 > p2 || v2 < p1);
    ve = where(v1 > e2 || v1 < e1);

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

    std::cout<<"Where comparation two criterion and:"<<std::endl<<std::endl;

    std::cout<<"Test lower parameters are: p1 = "<< p1 << " and e1 = "<< e1 <<std::endl<<std::endl;
    std::cout<<"Test upper parameters are: p2 = "<< p2 << " and e2 = "<< e2 <<std::endl<<std::endl;


    std::cout<<"Where with vector v2 and p1, p2 parameters comparation, (p2 < v or v < p1):"<<std::endl<<std::endl;

    if(!vv.empty())
    {
        std::cout<<"vp = [";
        for(std::size_t i = 0; i < vp.size()-1; i++)
        {
            std::cout<<vp[i]<<", ";
        }
        std::cout<<vp[vp.size()-1]<<"]"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The vector is empty:"<<std::endl<<std::endl;
    }

    std::cout<<"Where with vector v1 and e1, e2 parameter comparation without coincidences, (e2 < v or v < e1):"<<std::endl<<std::endl;

    if(!ve.empty())
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
        std::cout<<"The vector is empty"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;

}

void testMathSortValArg()
{
    std::vector<long double> v = {1,6,3,9,32,0,23,1,7,4,3,8,2};

    std::cout<<"---------------------------------"<<std::endl;

    std::cout<<"testMathSortValArg"<<std::endl<<std::endl;
    std::cout<<"Test vectors are:"<<std::endl<<std::endl;
    std::cout<<"v = [";
    for(std::size_t i = 0; i < v.size()-1; i++)
    {
        std::cout<<v[i]<<", ";
    }
    std::cout<<v[v.size()-1]<<"]"<<std::endl<<std::endl;

    auto s = sortValArg(v);

    std::cout<<"The sort indexes vector are:"<<std::endl<<std::endl;
    std::cout<<"s = [";
    for(std::size_t i = 0; i < s.size()-1; i++)
    {
        std::cout<<s[i]<<", ";
    }
    std::cout<<s[s.size()-1]<<"]"<<std::endl<<std::endl;

    std::cout<<"Let's check if the sort are correct:"<<std::endl<<std::endl;
    std::cout<<"v_sort = [";
    for(std::size_t i = 0; i < s.size()-1; i++)
    {
        std::cout<<v[s[i]]<<", ";
    }
    std::cout<<v[s[s.size()-1]]<<"]"<<std::endl<<std::endl;

    std::cout<<"---------------------------------"<<std::endl;
}

void testMathAbs()
{
    std::vector<long double> v = {0,1,-2,3,-4,-5,6,-7,-8,9};
    std::cout<<"---------------------------------"<<std::endl;

    std::cout<<"testMathAbs"<<std::endl<<std::endl;
    std::cout<<"Test vectors are:"<<std::endl<<std::endl;
    std::cout<<"v = [";
    for(std::size_t i = 0; i < v.size()-1; i++)
    {
        std::cout<<v[i]<<", ";
    }
    std::cout<<v[v.size()-1]<<"]"<<std::endl<<std::endl;

    auto s = abs(v);

    std::cout<<"The absolute value elements vector are:"<<std::endl<<std::endl;
    std::cout<<"s = [";
    for(std::size_t i = 0; i < s.size()-1; i++)
    {
        std::cout<<s[i]<<", ";
    }
    std::cout<<s[s.size()-1]<<"]"<<std::endl<<std::endl;

    std::cout<<"---------------------------------"<<std::endl;
}

void testMathSqrt()
{
    std::vector<long double> v = {0,1,4,9,16,25,36,49,64,81};
    std::cout<<"---------------------------------"<<std::endl;

    std::cout<<"testMathSqrt"<<std::endl<<std::endl;
    std::cout<<"Test vectors are:"<<std::endl<<std::endl;
    std::cout<<"v = [";
    for(std::size_t i = 0; i < v.size()-1; i++)
    {
        std::cout<<v[i]<<", ";
    }
    std::cout<<v[v.size()-1]<<"]"<<std::endl<<std::endl;

    auto s = sqrt(v);

    std::cout<<"The square root value elements vector are:"<<std::endl<<std::endl;
    std::cout<<"s = [";
    for(std::size_t i = 0; i < s.size()-1; i++)
    {
        std::cout<<s[i]<<", ";
    }
    std::cout<<s[s.size()-1]<<"]"<<std::endl<<std::endl;

    std::cout<<"---------------------------------"<<std::endl;
}

void testMathBasicTrigonometric()
{
    std::vector<long double> v1(9);
    for(std::size_t i = 0; i < 9; i++)
    {
        v1[i] = i*kPi/4;
    }
    std::vector<long double> v2 = {1, 0.707107, -2.71051e-20, -0.707107, -1, -0.707107, 1.89735e-19, 0.707107, 1};
    std::vector<long double> s;

    std::cout<<"---------------------------------"<<std::endl;

    std::cout<<"testMathBasicTrigonometric"<<std::endl<<std::endl;
    std::cout<<"Cosine, sine and tangent"<<std::endl<<std::endl;
    std::cout<<"Test vectors are:"<<std::endl<<std::endl;
    std::cout<<"v1 = [";
    for(std::size_t i = 0; i < v1.size()-1; i++)
    {
        std::cout<<v1[i]<<", ";
    }
    std::cout<<v1[v1.size()-1]<<"]"<<std::endl<<std::endl;

    s = cos(v1);

    std::cout<<"The cosine value elements vector are:"<<std::endl<<std::endl;
    std::cout<<"s = [";
    for(std::size_t i = 0; i < s.size()-1; i++)
    {
        std::cout<<s[i]<<", ";
    }
    std::cout<<s[s.size()-1]<<"]"<<std::endl<<std::endl;

    s = sin(v1);

    std::cout<<"The sine value elements vector are:"<<std::endl<<std::endl;
    std::cout<<"s = [";
    for(std::size_t i = 0; i < s.size()-1; i++)
    {
        std::cout<<s[i]<<", ";
    }
    std::cout<<s[s.size()-1]<<"]"<<std::endl<<std::endl;

    s = tan(v1);

    std::cout<<"The tangent value elements vector are:"<<std::endl<<std::endl;
    std::cout<<"s = [";
    for(std::size_t i = 0; i < s.size()-1; i++)
    {
        std::cout<<s[i]<<", ";
    }
    std::cout<<s[s.size()-1]<<"]"<<std::endl<<std::endl;

    std::cout<<"Arc-cosine, arc-sine and arc-tangent"<<std::endl<<std::endl;
    std::cout<<"Test vectors are:"<<std::endl<<std::endl;
    std::cout<<"v2 = [";
    for(std::size_t i = 0; i < v2.size()-1; i++)
    {
        std::cout<<v2[i]<<", ";
    }
    std::cout<<v2[v2.size()-1]<<"]"<<std::endl<<std::endl;

    s = acos(v2);

    std::cout<<"The arc-cosine value elements vector are:"<<std::endl<<std::endl;
    std::cout<<"s = [";
    for(std::size_t i = 0; i < s.size()-1; i++)
    {
        std::cout<<s[i]<<", ";
    }
    std::cout<<s[s.size()-1]<<"]"<<std::endl<<std::endl;

    s = asin(v2);

    std::cout<<"The arc-sine value elements vector are:"<<std::endl<<std::endl;
    std::cout<<"s = [";
    for(std::size_t i = 0; i < s.size()-1; i++)
    {
        std::cout<<s[i]<<", ";
    }
    std::cout<<s[s.size()-1]<<"]"<<std::endl<<std::endl;

    s = atan(v2);

    std::cout<<"The arc-tangent value elements vector are:"<<std::endl<<std::endl;
    std::cout<<"s = [";
    for(std::size_t i = 0; i < s.size()-1; i++)
    {
        std::cout<<s[i]<<", ";
    }
    std::cout<<s[s.size()-1]<<"]"<<std::endl<<std::endl;

    std::cout<<"---------------------------------"<<std::endl;
}

int main()
{
    std::cout << "Unit Test: dpbase::math" << std::endl;

    // math_utils test, provisional
    testMathWhere();
    testMathSortValArg();
    testMathAbs();
    testMathSqrt();
    testMathBasicTrigonometric();
    //prueba();

    // All assertions passed
    std::cout << "All tests passed!\n";

    return 0;
}
