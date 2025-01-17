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
 * @file time_types.h
 * @brief This file contains several timing definitions.
 * @author Degoras Project Team
 * @copyright EUPL License
***********************************************************************************************************************/

// =====================================================================================================================
#pragma once
// =====================================================================================================================

// C++ INCLUDES
// =====================================================================================================================
#include <chrono>
#include <string>
// =====================================================================================================================

// LIBRARY INCLUDES
// =====================================================================================================================
#include"LibDegorasBase/Mathematics/types/numeric_strong_type.h"
// =====================================================================================================================

// DPBASE NAMESPACES
// =====================================================================================================================
namespace dpbase{
namespace timing{
namespace types{
// =====================================================================================================================

// CONVENIENT TYPES
// =====================================================================================================================

/// High resolution clock.
using HRClock = std::chrono::high_resolution_clock;

/// High resolution time point to store datetimes (uses Unix Time).
using HRTimePointStd = std::chrono::time_point<std::chrono::high_resolution_clock>;

/// Steady clock time point for measuring intervals.
using SCTimePointStd =  std::chrono::steady_clock::time_point;

/// Short way of referring to seconds.
using SecStd = std::chrono::seconds;

/// Short way of referring to milliseconds.
using MsStd = std::chrono::milliseconds;

/// Short way of referring to microseconds.
using UsStd = std::chrono::microseconds;

/// Short way of referring to nanoseconds.
using NsStd = std::chrono::nanoseconds;

/// Alias for Windows Ticks.
using Windows32Ticks = math::types::NumericStrongType<unsigned long long, struct Windows32TicksTag>;

/// Alias for second of day with decimals (always < 86400, picoseconds precision).
using SoD = math::types::NumericStrongType<long double, struct SoDTag>;

/// Alias for fraction of day with decimals (always < 0, nanoseconds precision in the sense of fraction of the day).
using DayFraction = math::types::NumericStrongType<long double, struct DayFractionTag>;

/// Alias for ISO 8601 string.
using Iso8601Str = std::string;

/**
 * Enum class for specifying the time resolution in string representations.
 */
enum class TimeResolution
{
    SECONDS,        ///< Represents the seconds.
    MILLISECONDS,   ///< Represents the milliseconds.
    MICROSECONDS,   ///< Represents the microseconds.
    NANOSECONDS     ///< Represents the nanoseconds.
};

// =====================================================================================================================

}}} // END NAMESPACES.
// =====================================================================================================================
