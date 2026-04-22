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

/** ********************************************************************************************************************
 * @file math.tpp
 * @brief This file contains the template implementation of the mathematical functions.
 * @author Degoras Project Team
 * @copyright EUPL License
***********************************************************************************************************************/

// =====================================================================================================================
#pragma once
// =====================================================================================================================

// C++ INCLUDES
// =====================================================================================================================
#include <cmath>
#include <omp.h>
#include <numeric>
// =====================================================================================================================

// LIBRARY INCLUDES
// =====================================================================================================================
#include "LibDegorasBase/Helpers/string_helpers.h"
// =====================================================================================================================

// ========== DPBASE NAMESPACES =========================================================================================
namespace dpbase{
namespace math{
// =====================================================================================================================

template<typename T>
double truncToDouble(T x, unsigned int prec, unsigned int dec_places)
{
    return std::stod(dpbase::helpers::strings::numberToStr(x, prec, dec_places));
}

template<typename T>
double roundToDouble(T x, unsigned int dec_places)
{
    const long double multiplier = std::pow(10.0L, dec_places);
    return std::round(x * multiplier) / multiplier;
}

template <typename T>
T normalizeVal(T x, T x_min, T x_max)
{
    return std::fmod(((std::fmod((x - x_min),(x_max - x_min)))+(x_max - x_min)), (x_max - x_min)) + x_min;
}

inline std::vector<std::size_t> where(std::vector<bool> mask)
{
    std::vector<std::size_t> result;

    if(mask.empty())
    {
        return result;
    }

    for(std::size_t i = 0; i < mask.size(); i++)
    {
        if(mask[i])
        {
            result.push_back(i);
        }
    }

    return result;
}

inline std::vector<long double> arange(long double start,long double stop,long double step)
{
    if(step == 0.0)
    {
        return {};
    }
    else if(step < 0)
    {
        if(start < stop)
        {
            return {};
        }
    }
    else
    {
        if(start > stop)
        {
            return {};
        }
    }
    std::vector<long double> x;
    long double itr = 0;
    for(std::size_t i = 0; ; i++)
    {
        itr = start + i*step;
        if(itr >= stop && step > 0)
        {
            break;
        }
        else if(itr <= stop && step < 0)
        {
            break;
        }
        x.push_back(itr);
    }
    return x;
}

template <typename T>
inline std::vector<T> SortValues(const std::vector<T>& v)
{
    std::vector<T> aux = v;
    std::sort(aux.begin(), aux.end());
    return aux;
}

template <typename T>
std::vector<std::size_t> Argsort(const std::vector<T>& v)
{
    std::vector<std::size_t> idx(v.size());
    std::iota(idx.begin(), idx.end(), 0);

    std::stable_sort(idx.begin(), idx.end(),
                     [&v](std::size_t i, std::size_t j) {
                         return v[i] < v[j];
                     });

    return idx;
}

}} // END NAMESPACES.
// =====================================================================================================================
