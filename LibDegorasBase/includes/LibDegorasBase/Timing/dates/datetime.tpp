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
 * @file datetime.tpp
 * @brief
 * @author Degoras Project Team
 * @copyright EUPL License
***********************************************************************************************************************/

// =====================================================================================================================
#pragma once
// =====================================================================================================================

// C++ INCLUDES
// =====================================================================================================================
#include <omp.h>
// =====================================================================================================================

// LIBRARY INCLUDES
// =====================================================================================================================
#include "LibDegorasBase/Timing/dates/datetime.h"
#include <LibDegorasBase/Timing/time_constants.h>
#include <LibDegorasBase/Timing/types/base_time_types.h>
#include <LibDegorasBase/Mathematics/utils/math_utils.h>
// =====================================================================================================================

// DPBASE NAMESPACES
// =====================================================================================================================
namespace dpbase{
namespace timing{
namespace dates{
// =====================================================================================================================

template <typename DateType>
DateTime<DateType>::DateTime() :
    date_(DateType()),
    fract_(types::DayFraction()),
    sod_(types::SoD())
{}

template <typename DateType>
DateTime<DateType>::DateTime(const DateType &date, const types::SoD &sod) :
    date_(date),
    sod_(sod)
{
    // Normalize.
    this->normalize();
}

template<typename DateType>
DateTime<DateType>::DateTime(long double dt)
{
    long double day;
    this->sod_ = std::modf(dt, &day) * timing::kSecsPerDayL;
    this->date_ = day;

    this->normalize();
}

template <typename DateType>
DateType DateTime<DateType>::date() const
{
    return this->date_;
}

template <typename DateType>
types::DayFraction DateTime<DateType>::fract() const
{
    return this->fract_;
}

template <typename DateType>
types::SoD DateTime<DateType>::sod() const
{
    return this->sod_;
}

template <typename DateType>
long double DateTime<DateType>::datetime() const
{
    return static_cast<long double>(this->date_) + this->fract_;
}

template <typename DateType>
void DateTime<DateType>::add(const math::units::Seconds& seconds)
{
    sod_ += seconds;
    normalize();
}

template <typename DateType>
DateTimeV<DateType> DateTime<DateType>::linspaceStep(const DateTime& start, const DateTime& end,
                                                     const math::units::Seconds& step)
{
    DateTimeV<DateType> result;

    if (math::isFloatingZeroOrMinor(step))
        return result;

    size_t num = static_cast<size_t>(std::ceil((end - start) / step));

    result.resize(num);

    #pragma omp parallel for
    for (size_t i = 0; i < num; i++)
    {
        DateTime value = start + step * static_cast<long double>(i);
        result[i] = value;
    }

    return result;
}

template <typename DateType>
bool DateTime<DateType>::operator==(const DateTime &other) const
{
    return this->date_ == other.date() && math::compareFloating(this->sod_, other.sod()) == 0;
}

template <typename DateType>
bool DateTime<DateType>::operator!=(const DateTime &other) const
{
    return this->date_ != other.date() || math::compareFloating(this->sod_, other.sod()) != 0;
}

template <typename DateType>
bool DateTime<DateType>::operator<(const DateTime& other) const
{
    return (this->date() < other.date()) ||
           (this->date() == other.date() && math::compareFloating(this->sod(), other.sod()) < 0);
}

template <typename DateType>
bool DateTime<DateType>::operator<=(const DateTime &other) const
{
    return (this->date() < other.date()) ||
           (this->date() == other.date() && math::compareFloating(this->sod(), other.sod()) <= 0);
}

template <typename DateType>
bool DateTime<DateType>::operator>(const DateTime &other) const
{
    return (this->date() > other.date()) ||
           (this->date() == other.date() && math::compareFloating(this->sod(), other.sod()) > 0);
}

template <typename DateType>
bool DateTime<DateType>::operator>=(const DateTime &other) const
{
    return (this->date() > other.date()) ||
           (this->date() == other.date() && math::compareFloating(this->sod(), other.sod()) >= 0);
}

template <typename DateType>
DateTime<DateType> DateTime<DateType>::operator+(const math::units::Seconds &seconds) const
{
    DateTime result = *this;
    result.add(seconds);
    return result;
}

template <typename DateType>
DateTime<DateType>& DateTime<DateType>::operator+=(const math::units::Seconds& seconds)
{
    return *this = *this + seconds;
}

template <typename DateType>
DateTime<DateType>& DateTime<DateType>::operator+=(const DateTime<DateType>& other)
{
    return *this = *this + other;
}

template <typename DateType>
DateTime<DateType> DateTime<DateType>::operator-(const math::units::Seconds& seconds) const
{
    return *this + (-seconds);
}

template <typename DateType>
DateTime<DateType>& DateTime<DateType>::operator-=(const math::units::Seconds& seconds)
{
    return *this = *this - seconds;
}

template <typename DateType>
DateTime<DateType>& DateTime<DateType>::operator-=(const DateTime<DateType>& other)
{
    return *this = *this - other;
}

template <typename DateType>
void DateTime<DateType>::normalize()
{
    // Normalize the second of day input (decrement).
    while(math::compareFloating(this->sod_, types::SoD(timing::kSecsPerDayL)) < 0)
    {
        this->sod_ += timing::kSecsPerDayL;
        this->date_--;
    }

    // Normalize the second of day input (increment).
    while(math::compareFloating(this->sod_, types::SoD(timing::kSecsPerDayL)) >= 0)
    {
        this->sod_ -= timing::kSecsPerDayL;
        this->date_++;
    }

    // Calculate the fractional part of the day
    this->fract_ = this->sod_ / timing::kSecsPerDayL;
}


template <typename DateType>
math::units::Seconds operator-(const DateTime<DateType> &a, const DateTime<DateType> &b)
{
    math::units::Seconds result;
    result = (a.date()-b.date()) * math::units::Seconds(kSecsPerDayL) + (a.sod() - b.sod());
    return result;
}

template <typename DateType>
math::units::Seconds operator+(const DateTime<DateType> &a, const DateTime<DateType> &b)
{
    math::units::Seconds result;
    result = (a.date()+b.date()) * math::units::Seconds(kSecsPerDayL) + (a.sod() + b.sod());
    return result;
}

}}} // END NAMESPACES.
// =====================================================================================================================
