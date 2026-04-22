/***********************************************************************************************************************
 *   LibDegorasBase (Degoras Project SLR Library): A libre base library for Degoras Project developments.                        *                                      *
 *                                                                                                                     *
 *   Copyright (C) 2023 Degoras Project Team                                                                           *
 *                      < Ángel Vera Herrera, avera@roa.es - angeldelaveracruz@gmail.com >                             *
 *                      < Jesús Relinque Madroñal >                                                                    *
 *                                                                                                                     *
 *   This file is part of LibDegorasBase.                                                                                    *
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
 * @file measures.h
 * @author Degoras Project Team.
 * @brief This file contains the functions definition of several stadistics measures.
 * @copyright EUPL License
 2305.1
***********************************************************************************************************************/

// =====================================================================================================================
#pragma once
// =====================================================================================================================

// C++ INCLUDES
// =====================================================================================================================
#include <cmath>
#include <numeric>
#include <algorithm>
#include <vector>
#include <string>
// =====================================================================================================================

// LIBRARY INCLUDES
// =====================================================================================================================

// =====================================================================================================================

// LIBDPBASE NAMESPACES
// =====================================================================================================================
namespace dpbase{
namespace stats{
namespace measures{
// =====================================================================================================================

// ========== FUNCTIONS ===============================================================================================

/**
 * @brief Calculates the mean of a distribution.
 * @param x The input vector containing the distribution data.
 * @return The mean value.
 */template <typename T>
T mean(const std::vector<T> &x)
{
    return std::accumulate(x.begin(), x.end(), 0.0) / x.size();
}

/**
 * @brief Calculates the median of a distribution.
 * @param x The input vector containing the distribution data.
 * @return The median value.
 */
template <typename T>
T median(const std::vector<T>& x, bool sorted = false)
{
    if (x.empty())
        return 0;

    T med;

    // If x is sorted, avoid copy and sort. Once data is sort, choose median element:
    // centre if even elements, mean of two centre elements othersie)
    if (sorted)
    {
        med = (0 == x.size() % 2) ? (x[x.size() / 2] + x[(x.size() / 2) - 1]) / 2. : x[x.size() / 2];
    }
    else
    {
        auto x_sort = x;
        std::sort(x_sort.begin(), x_sort.end());
        med = (0 == x.size() % 2) ? (x_sort[x.size() / 2] + x_sort[(x.size() / 2) - 1]) / 2. : x_sort[x.size() / 2];
    }

    return med;
}

/**
 * @brief Calculates the variance of a distribution.
 * @param x The input vector containing the distribution data.
 * @return The variance value.
 */
template <typename T>
T var(const std::vector<T>& x)
{
    T m = mean(x);
    T u2 = 0.0;

    for (const auto& value : x)
    {
        T x_minus_mean = value - m;
        u2 += std::pow(x_minus_mean, 2);
    }

    return u2 / x.size();
}

/**
 * @brief Calculates the skewness of a distribution using the method of moments.
 * @param x The input vector containing the distribution data.
 * @param bias Flag indicating whether to apply bias correction. Default is true.
 * @return The skewness value.
 */
template <typename T>
T skew(const std::vector<T> &x, bool bias = true)
{
    T mean = mean(x);
    T u2 = 0.0;
    T u3 = 0.0;
    for (const auto& value : x)
    {
        T x_minus_mean = value - mean;
        u2 += std::pow(x_minus_mean, 2);
        u3 += std::pow(x_minus_mean, 3);
    }
    u2 /= x.size();
    u3 /= x.size();

    T res = u3 / std::pow(u2, 1.5);

    if (!bias && x.size() > 2)
    {
        T n = static_cast<T>(x.size());
        T sk_bias = std::sqrt((n * (n - 1))) / (n - 2);
        res *= sk_bias;
    }

    return res;
}

/**
 * @brief Compute the kurtosis (Fisher or Pearson) of a vector of values.
 *
 *        Kurtosis is the fourth central moment divided by the square of the variance. If Fisher’s definition
 *        is used, then 3.0 is subtracted from the result to give 0.0 for a normal distribution.
 *
 *        If bias is false, then the calculations are corrected using k statistics to eliminate bias coming from
 *        biased moment estimators
 *
 * @param x         The input vector containing the distribution data.
 * @param fisher    Flag indicating whether to apply Fisher's correction. Default is false.
 * @param bias      Flag indicating whether to apply bias correction. Default is true.
 * @return The kurtosis value.
 */
template <typename T>
T kurtosis(const std::vector<T> &x, bool fisher = false, bool bias = true)
{
    T mean = mean(x);
    T u2 = 0.0;
    T u4 = 0.0;
    for (const auto& value : x)
    {
        T x_minus_mean = value - mean;
        u2 += std::pow(x_minus_mean, 2);
        u4 += std::pow(x_minus_mean, 4);
    }
    u2 /= x.size();
    u4 /= x.size();

    T res =  u4 / std::pow(u2, 2);

    if(fisher)
        res -= 3;

    if (!bias && x.size() > 2)
    {
        T n = static_cast<T>(x.size());
        T k_bias = ((n - 1) * (n + 1)) * ((n - 2) * (n - 3));
        res = (n * (n + 1) * res - 3 * (n - 1) * (n - 1)) / k_bias;
    }

    return res;
}

/**
 * @brief Calculates the Standard Deviation of a distribution.
 * @param x The input vector containing the distribution data.
 * @return The standard deviation of the distribution.
 */
template <typename T>
T stddev(const std::vector<T>& x)
{
    return std::sqrt(var(x));
}

/**
 * @brief Calculates the Root Mean Squared of a distribution.
 * @param x The input vector containing the distribution data.
 * @return The Root Mean Squared calculation for data in x.
 */
template <typename T>
T rms(const std::vector<T>& x)
{
    return std::sqrt(std::inner_product(x.begin(), x.end(), x.begin(), T()) / x.size());
}

/**
 * @brief Calculates the leverage values for a distribution.
 * @param x The input vector containing the distribution data.
 * @return A vector with the leverage values.
 */
template <typename T, typename Ret = T>
std::vector<Ret> leverage(const std::vector<T>& x)
{
    // Leverage formula: hi = 1/n + ((xi - xm)^2 / sumsqr(x - xm))
    auto m = mean(x);
    std::vector<T> leverage_v;
    // First insert x minus mean
    std::transform(x.begin(), x.end(), std::back_inserter(leverage_v), [m](const auto& e){return e - m;});
    // Calculate deviations sum sqr
    auto devsqr = std::inner_product(leverage_v.begin(), leverage_v.end(), leverage_v.begin(), T());
    auto n_inv = 1./ x.size();
    std::transform(leverage_v.begin(), leverage_v.end(), leverage_v.begin(),
                   [devsqr, n_inv](const auto& e){return n_inv + (e*e / devsqr);});
    return leverage_v;
}

/**
 * @brief Calculates the discrete linear convolution of two one-dimensional sequences.
 * @param v1, The first vector.
 * @param v2, The second vector.
 * @param mode, The method using to calculate the convolution the modes are full, same or valid.
 * @note The predeterminate mode is full.
 * @return A vector with the convolution.
 */
template <typename T>
std::vector<T> convolve(const std::vector<T>& a, const std::vector<T>& b, std::string mode)
{
    // If no mode is given assign the full mode
    if(mode=="")
    {
        mode = "full";
    }

    // Initialize the vectors
    std::vector<long double> signal;
    std::vector<long double> kernel;
    // Assign the vectors
    if(a.size() >= b.size())
    {
        signal = a;
        kernel = b;
    }
    else
    {
        signal = b;
        kernel = a;
    }

    // Assing the size of vectors
    int M = signal.size();
    int N = kernel.size();
    int s = M + N - 1;
    // Initialize the convolutions vectors
    std::vector<long double> full;
    std::vector<long double> valid;
    std::vector<long double> same;

    // Perforn the calculation of 'full' an 'valid' convolution vectors
    for(int n = 0; n < s; n++)
    {
        long double sum = 0;
        int count = 0;

        for(int m = 0; m < M; m++)
        {
            if(n-m >= 0 && n-m < N)
            {
                sum += signal[m] * kernel[n-m];
                count++;
            }
        }
        full.push_back(sum);
        // Check if the element is valid
        if(count == N)
        {
            valid.push_back(sum);
        }
    }
    // Check the selected method
    if(mode == "full")
    {
        return full;
    }
    else if(mode == "valid")
    {
        return valid;
    }
    else if(mode == "same")
    {
        // Perform the calculation of 'same' convolution vector
        std::size_t clipper = std::floor((s - M)/2);

        for(int i = 0; i < M; i++)
        {
            same.push_back(full[i + clipper]);
        }
        return same;
    }
    // If an invalid mode is given show an error and return an empty vector
    std::cout<<mode<<" is not a valid mode, the valid modes are full, same or valid"<<std::endl<<std::endl;
    return same;
}

/**
 * @brief Find the first argument/index of the maximun value in a vector.
 * @param v, the vector.
 * @return The first index of maximun value.
 */
template <typename T>
std::size_t argmax(std::vector<T>& v)
{
    // Assign the maximun value
    long double M = *std::max_element(v.begin(), v.end());
    std::size_t arg;
    // Find the first index of maximun value
    for(std::size_t i = 0; i < v.size(); i++)
    {
        if(v[i]==M)
        {
            arg = i;
            break;
        }
    }
    return arg;
}

/**
 * @brief Find the first argument/index of the minimun value in a vector.
 * @param v, the vector.
 * @return The first index of minimun value.
 */
template <typename T>
std::size_t argmin(std::vector<T>& v)
{
    // Assign the minimun value
    long double m = *std::min_element(v.begin(), v.end());
    std::size_t arg;
    // Find the first index of minimun value
    for(std::size_t i = 0; i < v.size(); i++)
    {
        if(v[i]==m)
        {
            arg = i;
            break;
        }
    }
    return arg;
}

/**
 * @brief Find all arguments/indexes of the maximun value in a vector.
 * @param v, the vector.
 * @return A vector with all indexes of maximun value.
 */
template <typename T>
std::vector<std::size_t> argsmax(std::vector<T>& v)
{
    // Assign the maximun value
    long double M = *std::max_element(v.begin(), v.end());
    std::vector<std::size_t> arg;
    // Find all indexes of maximun value
    for(std::size_t i = 0; i < v.size(); i++)
    {
        if(v[i]==M)
        {
            arg.push_back(i);
        }
    }
    return arg;
}

/**
 * @brief Find all arguments/indexes of the minimun value in a vector.
 * @param v, the vector.
 * @return A vector with all indexes of minimun value.
 */
template <typename T>
std::vector<std::size_t> argsmin(std::vector<T>& v)
{
    // Assign the minimun value
    long double m = *std::min_element(v.begin(), v.end());
    std::vector<std::size_t> arg;
    // Find all indexes of minimun value
    for(std::size_t i = 0; i < v.size(); i++)
    {
        if(v[i]==m)
        {
            arg.push_back(i);
        }
    }
    return arg;
}

// -----------------------------------------------------------------------

std::vector<std::size_t> where(std::vector<bool> mask)
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

std::vector<std::size_t> where(std::vector<bool> mask1, std::vector<bool> mask2)
{
    std::vector<std::size_t> result = {};

    if(mask1.empty() || mask2.empty())
    {
        return result;
    }

    if(mask1.size() != mask2.size())
    {
        std::cout << "Invalids vector, the vectors haven't the same dimension" << std::endl;
        return result;
    }

    for(std::size_t i = 0; i < mask1.size(); i++)
    {
        if(mask1[i] && mask2[i])
        {
            result.push_back(i);
        }
    }

    return result;
}

template <typename T>
std::vector<bool> maskGE(std::vector<T> v1, std::vector<T> v2)
{
    std::vector<bool> result;
    if(v1.size() != v2.size())
    {
        std::cout<<"Invalid comparation, the vectors hasn't the same dimension"<<std::endl;
        return result;
    }

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
std::vector<bool> maskGE(std::vector<T> v, U l)
{
    std::vector<bool> result;
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
std::vector<bool> maskL(std::vector<T> v1, std::vector<T> v2)
{
    std::vector<bool> result;
    if(v1.size() != v2.size())
    {
        std::cout<<"Invalid comparation, the vectors hasn't the same dimension"<<std::endl;
        return result;
    }

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
std::vector<bool> maskL(std::vector<T> v, U l)
{
    std::vector<bool> result;
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
std::vector<bool> maskE(std::vector<T> v1, std::vector<T> v2)
{
    std::vector<bool> result;
    if(v1.size() != v2.size())
    {
        std::cout<<"Invalid comparation, the vectors hasn't the same dimension"<<std::endl;
        return result;
    }

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
std::vector<bool> maskE(std::vector<T> v, U l)
{
    std::vector<bool> result;
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

template <typename T, typename U>
std::vector<bool> maskGEandL(std::vector<T> v, U l1, U l2)
{
    return maskE(maskGE(v,l1),maskL(v,l2));
}

}}} // END NAMESPACES.
// =====================================================================================================================
