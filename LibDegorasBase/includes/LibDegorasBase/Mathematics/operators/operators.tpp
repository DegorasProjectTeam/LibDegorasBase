/***********************************************************************************************************************
 *   LibDegorasBase (Degoras Project SLR Library).                                                                      *
 *                                                                                                                     *
 *   A modern and efficient C++ base library for Satellite Laser Ranging (SLR) software and real-time hardware         *
 *   related developments. Developed as a free software under the context of Degoras Project for the Spanish Navy      *
 *   Observatory SLR station (SFEL) in San Fernando and, of course, for any other station that wants to use it!        *
 *                                                                                                                     *
 *   Copyright (C) 2024 Degoras Project Team                                                                           *
 *                      < Ángel Vera Herrera, avera@roa.es - angeldelaveracruz@gmail.com >                             *
 *                      < Jesús Relinque Madroñal >                                                                    *
 *                                                                                                                     *
 *   This file is part of LibDegorasBase.                                                                               *
 *                                                                                                                     *
 *   Licensed under the European Union Public License (EUPL), Version 1.2 or subsequent versions of the EUPL license   *
 *   as soon they will be approved by the European Commission (IDABC).                                                 *
 *                                                                                                                     *
 *   This project is free software: you can redistribute it and/or modify it under the terms of the EUPL license as    *
 *   published by the IDABC, either Version 1.2 or, at your option, any later version.                                 *
 *                                                                                                                     *
 *   This project is distributed in the hope that it will be useful. Unless required by applicable law or agreed to in *
 *   writing, it is distributed on an "AS IS" basis, WITHOUT ANY WARRANTY OR CONDITIONS OF ANY KIND; without even the  *
 *   implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the EUPL license to check specific   *
 *   language governing permissions and limitations and more details.                                                  *
 *                                                                                                                     *
 *   You should use this project in compliance with the EUPL license. You should have received a copy of the license   *
 *   along with this project. If not, see the license at < https://eupl.eu/ >.                                         *
 **********************************************************************************************************************/

// =====================================================================================================================
#pragma once
// =====================================================================================================================

// C++ INCLUDES
// =====================================================================================================================
#include <vector>
#include <cmath>
// =====================================================================================================================

// DPBASE NAMESPACES
// =====================================================================================================================
namespace dpbase{
namespace math{
namespace operators{
// =====================================================================================================================

template <typename T, typename U>
std::vector<std::common_type_t<T,U>> operator +(const std::vector<T>& a, const std::vector<U>& b)
{
    size_t min_size = std::min(a.size(), b.size());
    std::vector<std::common_type_t<T,U>> result;
    for (size_t i = 0; i < min_size; i++)
        result.push_back(a[i] + b[i]);
    return result;
}

template <typename T, typename U>
std::vector<std::common_type_t<T,U>> operator +(const std::vector<T>& a, const U& b)
{
    std::vector<std::common_type_t<T,U>> result;
    for (size_t i = 0; i < a.size(); i++)
        result.push_back(a[i] + b);
    return result;
}

template <typename T>
std::vector<T> operator -(const std::vector<T>& a)
{
    std::vector<T> result;
    for (const auto& element : a)
        result.push_back(-element);
    return result;
}

template <typename T, typename U>
std::vector<std::common_type_t<T,U>> operator -(const std::vector<T>& a, const std::vector<U>& b) {return a + (-b);}

template <typename T, typename U>
std::vector<std::common_type_t<T,U>> operator -(const std::vector<T>& a, const U& b) {return a + (-b);}

template <typename T, typename U>
std::vector<std::common_type_t<T,U>> operator *(const std::vector<T>& a, const std::vector<U>& b)
{
    size_t min_size = std::min(a.size(), b.size());
    std::vector<std::common_type_t<T,U>> result;
    for (size_t i = 0; i < min_size; i++)
        result.push_back(a[i] * b[i]);
    return result;
}

template <typename T, typename U>
std::vector<std::common_type_t<T,U>> operator *(const std::vector<T>& a, const U& b)
{
    std::vector<std::common_type_t<T,U>> result;
    for (size_t i = 0; i < a.size(); i++)
        result.push_back(a[i] * b);
    return result;
}

template <typename T, typename U>
std::vector<std::common_type_t<T,U>> operator /(const std::vector<T>& a, const std::vector<U>& b)
{
    size_t min_size = std::min(a.size(), b.size());
    std::vector<std::common_type_t<T,U>> result;
    for (size_t i = 0; i < min_size; i++)
        if(b[i] == 0)
        {
            return {};
        }
        else
        {
            result.push_back(a[i] / b[i]);
        }
    return result;
}

template <typename T, typename U>
std::vector<std::common_type_t<T,U>> operator /(const std::vector<T>& a, const U& b)
{
    if(b == 0)
    {
        return {};
    }
    std::vector<std::common_type_t<T,U>> result;
    for (size_t i = 0; i < a.size(); i++)
        result.push_back(a[i] / b);
    return result;
}

template <typename T>
std::vector<T> sqrt(const std::vector<T>& a)
{
    std::vector<T> result;
    for (size_t i = 0; i < a.size(); i++)
        result.push_back(std::sqrt(a[i]));
    return result;
}

template <typename T>
std::vector<T> cos(const std::vector<T>& a)
{
    std::vector<T> result;
    for (size_t i = 0; i < a.size(); i++)
        result.push_back(std::cos(a[i]));
    return result;
}

template <typename T>
std::vector<T> sin(const std::vector<T>& a)
{
    std::vector<T> result;
    for (size_t i = 0; i < a.size(); i++)
        result.push_back(std::sin(a[i]));
    return result;
}

template <typename T>
std::vector<T> tan(const std::vector<T>& a)
{
    std::vector<T> result;
    for (size_t i = 0; i < a.size(); i++)
        result.push_back(std::tan(a[i]));
    return result;
}

template <typename T>
std::vector<T> acos(const std::vector<T>& a)
{
    std::vector<T> result;
    for (size_t i = 0; i < a.size(); i++)
        result.push_back(std::acos(a[i]));
    return result;
}

template <typename T>
std::vector<T> asin(const std::vector<T>& a)
{
    std::vector<T> result;
    for (size_t i = 0; i < a.size(); i++)
        result.push_back(std::asin(a[i]));
    return result;
}

template <typename T>
std::vector<T> atan(const std::vector<T>& a)
{
    std::vector<T> result;
    for (size_t i = 0; i < a.size(); i++)
        result.push_back(std::atan(a[i]));
    return result;
}

template <typename T>
std::vector<bool> operator ==(std::vector<T> v1, std::vector<T> v2)
{
    std::vector<bool> result;

    if(v1.size() != v2.size())
    {
        std::cout<<"Invalid comparation, the vectors hasn't the same dimension"<<std::endl;
        return result;
    }

    result.reserve(v1.size());

    for(std::size_t i = 0; i < v1.size(); i++)
    {
        if(v1[i] == v2[i])
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }
    return result;
}

template <typename T, typename U>
std::vector<bool> operator ==(std::vector<T> v, U l)
{
    std::vector<bool> result;
    result.reserve(v.size());

    for(std::size_t i = 0; i < v.size(); i++)
    {
        if(v[i] == l)
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }
    return result;
}

template <typename T>
std::vector<bool> operator !=(std::vector<T> v1, std::vector<T> v2)
{
    std::vector<bool> result;

    if(v1.size() != v2.size())
    {
        std::cout<<"Invalid comparation, the vectors hasn't the same dimension"<<std::endl;
        return result;
    }

    result.reserve(v1.size());

    for(std::size_t i = 0; i < v1.size(); i++)
    {
        if(v1[i] != v2[i])
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }
    return result;
}

template <typename T, typename U>
std::vector<bool> operator !=(std::vector<T> v, U l)
{
    std::vector<bool> result;
    result.reserve(v.size());

    for(std::size_t i = 0; i < v.size(); i++)
    {
        if(v[i] != l)
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }
    return result;
}

template <typename T>
    std::vector<bool> operator >(std::vector<T> v1, std::vector<T> v2)
{
    std::vector<bool> result;

    if(v1.size() != v2.size())
    {
        std::cout<<"Invalid comparation, the vectors hasn't the same dimension"<<std::endl;
        return result;
    }

    result.reserve(v1.size());

    for(std::size_t i = 0; i < v1.size(); i++)
    {
        if(v1[i] > v2[i])
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }
    return result;
}

template <typename T, typename U>
std::vector<bool> operator >(std::vector<T> v, U l)
{
    std::vector<bool> result;
    result.reserve(v.size());

    for(std::size_t i = 0; i < v.size(); i++)
    {
        if(v[i] > l)
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }
    return result;
}

template <typename T>
std::vector<bool> operator <(std::vector<T> v1, std::vector<T> v2)
{
    std::vector<bool> result;

    if(v1.size() != v2.size())
    {
        std::cout<<"Invalid comparation, the vectors hasn't the same dimension"<<std::endl;
        return result;
    }

    result.reserve(v1.size());

    for(std::size_t i = 0; i < v1.size(); i++)
    {
        if(v1[i] < v2[i])
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }
    return result;
}

template <typename T, typename U>
std::vector<bool> operator <(std::vector<T> v, U l)
{
    std::vector<bool> result;
    result.reserve(v.size());

    for(std::size_t i = 0; i < v.size(); i++)
    {
        if(v[i] < l)
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }
    return result;
}

template <typename T>
std::vector<bool> operator >=(std::vector<T> v1, std::vector<T> v2)
{
    std::vector<bool> result;

    if(v1.size() != v2.size())
    {
        std::cout<<"Invalid comparation, the vectors hasn't the same dimension"<<std::endl;
        return result;
    }

    result.reserve(v1.size());

    for(std::size_t i = 0; i < v1.size(); i++)
    {
        if(v1[i] >= v2[i])
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }
    return result;
}

template <typename T, typename U>
std::vector<bool> operator >=(std::vector<T> v, U l)
{
    std::vector<bool> result;
    result.reserve(v.size());

    for(std::size_t i = 0; i < v.size(); i++)
    {
        if(v[i] >= l)
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }
    return result;
}

template <typename T>
std::vector<bool> operator <=(std::vector<T> v1, std::vector<T> v2)
{
    std::vector<bool> result;

    if(v1.size() != v2.size())
    {
        std::cout<<"Invalid comparation, the vectors hasn't the same dimension"<<std::endl;
        return result;
    }

    result.reserve(v1.size());

    for(std::size_t i = 0; i < v1.size(); i++)
    {
        if(v1[i] <= v2[i])
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }
    return result;
}

template <typename T, typename U>
std::vector<bool> operator <=(std::vector<T> v, U l)
{
    std::vector<bool> result;
    result.reserve(v.size());
    for(std::size_t i = 0; i < v.size(); i++)
    {
        if(v[i] <= l)
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }
    return result;
}

std::vector<bool> operator &&(const std::vector<bool>& a, const std::vector<bool>& b)
{
    if(a.size() != b.size())
    {
        return {};
    }

    std::vector<bool> result;
    result.reserve(a.size());
    for(std::size_t i = 0; i < a.size(); i++)
    {
        if(a[i] && b[i])
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }

    return result;
}

std::vector<bool> operator ||(const std::vector<bool>& a, const std::vector<bool>& b)
{
    if(a.size() != b.size())
    {
        return {};
    }

    std::vector<bool> result;
    result.reserve(a.size());
    for(std::size_t i = 0; i < a.size(); i++)
    {
        if(a[i] || b[i])
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }

    return result;
}

}}} // END NAMESPACES
// =====================================================================================================================
