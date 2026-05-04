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
#include <vector>
#include <cmath>
#include <omp.h>
#include <algorithm>
#include <numeric>
#include <execution>
#include <functional>
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

    result.reserve(std::count(mask.begin(), mask.end(), true));

    for(std::size_t i = 0; i < mask.size(); i++)
    {
        if(mask[i])
        {
            result.push_back(i);
        }
    }

    return result;
}

// TODO refactor name
template <typename T, typename Compare>
std::vector<std::size_t> sortValArg(const std::vector<T>& v, Compare comp)
{
    std::vector<std::size_t> idx(v.size());
    std::iota(idx.begin(), idx.end(), 0);

    std::stable_sort(idx.begin(), idx.end(),
                     [&v, &comp](std::size_t i, std::size_t j) {
                         return comp(v[i], v[j]);});

    return idx;
}

template <typename Container>
Container abs(const Container& a)
{
    Container result;
    result.reserve(a.size());
    std::transform(a.begin(), a.end(), std::back_inserter(result), [](auto val){
        return std::abs(val);});

    return result;
}

template <typename Container>
Container sqrt(const Container& a)
{
    Container result;
    result.reserve(a.size());
    std::transform(a.begin(), a.end(), std::back_inserter(result), [](auto val){
        return std::sqrt(val);});

    return result;
}

template <typename Container>
Container exp(const Container& a)
{
    Container result(a.size());

    std::transform(a.begin(), a.end(), result.begin(), [](auto val){
        return std::exp(val);
    });

    return result;
}

template <typename Container>
Container cos(const Container& a)
{
    Container result;
    result.reserve(a.size());
    std::transform(a.begin(), a.end(), std::back_inserter(result), [](auto val){
        return std::cos(val);});

    return result;
}

template <typename Container>
Container sin(const Container& a)
{
    Container result;
    result.reserve(a.size());
    std::transform(a.begin(), a.end(), std::back_inserter(result), [](auto val){
        return std::sin(val);});

    return result;
}

template <typename Container>
Container tan(const Container& a)
{
    Container result;
    result.reserve(a.size());
    std::transform(a.begin(), a.end(), std::back_inserter(result), [](auto val){
        return std::tan(val);});

    return result;
}

template <typename Container>
Container acos(const Container& a)
{
    Container result;
    result.reserve(a.size());
    std::transform(a.begin(), a.end(), std::back_inserter(result), [](auto val){
        return std::acos(val);});

    return result;
}

template <typename Container>
Container asin(const Container& a)
{
    Container result;
    result.reserve(a.size());
    std::transform(a.begin(), a.end(), std::back_inserter(result), [](auto val){
        return std::asin(val);});

    return result;
}

template <typename Container>
Container atan(const Container& a)
{
    Container result;
    result.reserve(a.size());
    std::transform(a.begin(), a.end(), std::back_inserter(result), [](auto val){
        return std::atan(val);});

    return result;
}

}} // END NAMESPACES.
// =====================================================================================================================
