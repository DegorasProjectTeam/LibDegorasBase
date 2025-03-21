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
 * @file time_utils.h
 * @brief
 * @author Degoras Project Team
 * @copyright EUPL License
 2402.1
***********************************************************************************************************************/

// =====================================================================================================================
#pragma once
// =====================================================================================================================

// C++ INCLUDES
// =====================================================================================================================
#include <string>
#include <chrono>
// =====================================================================================================================

// LIBRARY INCLUDES
// =====================================================================================================================
#include "LibDegorasBase/Timing/dates/datetime_types.h"
#include "LibDegorasBase/libdegorasbase_global.h"
#include "LibDegorasBase/Timing/types/base_time_types.h"
// =====================================================================================================================

// DPBASE NAMESPACES
// =====================================================================================================================
namespace dpbase{
namespace timing{
// =====================================================================================================================

// TIME STRING FUNCTIONS
// =====================================================================================================================

/**
 * Converts a time point to a string representation with specified format and resolution.
 *
 * This function formats a given time point according to the specified strftime-compatible
 * format string. The function allows specifying the time resolution for the fractional part
 * of the seconds.It supports displaying the time in either UTC or local time.
 *
 * @warning This function relies on std::gmtime and std::localtime, which are based on the
 * time_t type. Consequently, it may not correctly handle dates before January 1, 1970, on
 * all systems due to the limitations of time_t and these functions. Users requiring support
 * for dates before the Unix epoch should consider alternative solutions or verify behavior
 * on their target platforms.
 *
 * @param tp The time point to format.
 * @param format The strftime format string for the date and time part.
 * @param resolution The resolution (seconds, milliseconds, microseconds, nanoseconds) for the time part.
 * @param utc Boolean flag to use UTC (true) or local time (false) for formatting.
 * @return A string representation of the time point according to the specified format and resolution.
 *
 * @throws std::runtime_error If there's an error during formatting.
 */
LIBDPBASE_EXPORT std::string timePointToString(const types::HRTimePointStd& tp,
                                              const std::string& format = "%Y-%m-%dT%H:%M:%S",
                                              types::TimeResolution resolution = types::TimeResolution::MILLISECONDS,
                                              bool utc = true, bool rm_trailing_zeros = true);

/**
 * Converts a high-resolution time point to an ISO 8601 formatted string.
 *
 * This function formats a given time point into a string following the ISO 8601 standard. The function
 * allows specifying the time resolution for the fractional part of the seconds. If the `utc`
 * flag is set to true, the formatted string is suffixed with 'Z' to indicate that the time is in
 * Coordinated Universal Time (UTC). If `utc` is false, the function does not qualify the time zone,
 * and the resulting string represents local time, unqualified by a specific time zone.
 *
 * @param tp The high-resolution time point to format.
 * @param resolution The desired resolution for the fractional part of the seconds in the output.
 * @param utc A boolean flag indicating whether the output should be in UTC (true) or
 *            local time (false). Default is true, appending 'Z' to the formatted string.
 * @return A std::string containing the formatted date and time in ISO 8601 format.
 *
 * @warning If `utc` is false, the resulting string represents local time without specifying the
 * time zone. This means that the time zone qualification (e.g., 'Z' for UTC) is omitted, and the time is assumed
 * to be undefined local.
 *
 * @throws std::runtime_error If there's an error during formatting.
 */
LIBDPBASE_EXPORT types::Iso8601Str timePointToIso8601(const types::HRTimePointStd& tp,
                                        types::TimeResolution resolution = types::TimeResolution::MILLISECONDS,
                                        bool utc = true, bool rm_trailing_zeros = true);


LIBDPBASE_EXPORT types::Iso8601Str modifiedJulianDateTimeToIso8601(const dates::MJDateTime& mjdt,
                                        types::TimeResolution resolution = types::TimeResolution::MILLISECONDS,
                                        bool utc = true, bool rm_trailing_zeros = true);

/**
 * @brief Generates the current date and time as a string formatted according to ISO 8601.
 *
 * This function captures the current system time and formats it into a standardized
 * ISO 8601 date and time string. The function allows specifying the time resolution for the
 * fractional part of the seconds. If the `utc` flag is set to true, the formatted string is
 * suffixed with 'Z' to indicate that the time is in Coordinated Universal Time (UTC). If `utc`
 * is false, the function does not qualify the time zone, and the resulting string represents
 * local time, unqualified by a specific time zone.
 *
 * @param resolution The desired resolution for the fractional part of the seconds in the output.
 * @param utc A boolean flag indicating whether the output should be in UTC (true) or
 *            local time (false). Default is true, appending 'Z' to the formatted string.
 * @return A std::string containing the formatted date and time in ISO 8601 format.
 *
 * @warning The precision of the system clock and the resolution parameter may affect the
 * accuracy and granularity of the output. Additionally, when using local time (utc=false),
 * the output string does not include timezone information, and users must be aware of
 * the local timezone context.
 */
LIBDPBASE_EXPORT std::string currentISO8601Date(types::TimeResolution resolution = types::TimeResolution::MILLISECONDS,
                                               bool utc = true, bool rm_trailing_zeros = true);

/**
 * @brief Converts a duration in milliseconds to an ISO 8601 duration string.
 *
 * This function takes a duration represented as milliseconds and formats it
 * into a string following the ISO 8601 duration format. The output format
 * is restricted to hours, minutes, and seconds (including fractional seconds),
 * to provide a precise representation of time intervals without introducing
 * complexities associated with longer time units like days or months.
 *
 * The decision to exclude days, months, and years from the format is to avoid
 * potential inaccuracies due to variable durations of these units, such as leap
 * seconds, leap years, and differences in month lengths.
 *
 * @param msecs The duration in milliseconds to be converted into an ISO 8601 duration string.
 * @return A std::string representing the formatted duration as per ISO 8601, including hours,
 *         minutes, and seconds. Fractional seconds are included if the duration includes partial
 *         seconds, and are represented without trailing zeros.
 *
 * @note The function returns "PT0H0M0S" for a duration of 0 milliseconds.
 *
 * @warning The function does not account for durations in terms of days, months, or years due
 * to the potential for leap seconds to introduce discrepancies. As such, it is ideal when precise
 * control over hours, minutes, and seconds is required.
 */
LIBDPBASE_EXPORT std::string millisecondsToISO8601Duration(const std::chrono::milliseconds& msecs);

/**
 * @brief Converts a duration in seconds to an ISO 8601 duration string.
 *
 * This function takes a duration represented as seconds and formats it into a string
 * following the ISO 8601 duration format. The output format is restricted to hours,
 * minutes, and seconds, to provide a precise representation of time intervals without
 * introducing complexities associated with longer time units like days or months.
 *
 * The decision to exclude days, months, and years from the format is to avoid
 * potential inaccuracies due to variable durations of these units, such as leap
 * seconds, leap years, and differences in month lengths.
 *
 * @param msecs The duration in seconds to be converted into an ISO 8601 duration string.
 * @return A std::string representing the formatted duration as per ISO 8601, including hours,
 *         minutes, and seconds.
 *
 * @note The function returns "PT0H0M0S" for a duration of 0 seconds.
 *
 * @warning The function does not account for durations in terms of days, months, or years due
 * to the potential for leap seconds to introduce discrepancies. As such, it is ideal when precise
 * control over hours, minutes, and seconds is required.
 */
LIBDPBASE_EXPORT std::string secondsToISO8601Duration(const std::chrono::seconds& secs);

/**
 * @brief Parses an ISO 8601 UTC datetime string and converts it to a HRTimePointStd.
 *
 * This function parses a UTC datetime string formatted according to ISO 8601, supporting both extended
 * and basic formats, including up to nanosecond precision, and converts it into a HRTimePointStd time point.
 * The input string must conform to the ISO 8601 formats:
 * - Extended format: "YYYY-MM-DDTHH:MM:SS.sssZ"
 * - Basic format: "YYYYMMDDTHHMMSS.sssZ"
 * In both formats, the fractional seconds (".sss") are optional and can represent milliseconds up to nanoseconds.
 *
 * @param datetime The ISO 8601 UTC datetime string to be parsed, in either extended or basic format.
 * @return HRTimePointStd A time point representing the specified datetime.
 *
 * @throws std::invalid_argument If the input string does not match the ISO 8601 format.
 *
 * @warning This function uses regular expressions, which may not be fully supported or performant on some older
 * compiler versions. Ensure compatibility with your compiler's regex implementation when using this function.
 */
LIBDPBASE_EXPORT types::HRTimePointStd iso8601DatetimeToTimePoint(const types::Iso8601Str& datetime);

// =====================================================================================================================

// TIMEPOINT CONVERSION FUNCTIONS
// =====================================================================================================================
/**
 * @brief Converts a HRTimePointStd to Julian Datetime with precision up to milliseconds.
 *
 * This function calculates the Julian Date corresponding to a given time point represented in terms of nanoseconds
 * since the Unix epoch (1970-01-01T00:00:00Z). The precision of the Julian Date returned by this function is limited
 * by the precision of the 'long double' type used in the calculation. Typically provide precision up to milliseconds
 * approximately but deppends how far is the date from the epoch. See the **Note** and **Warning** sections for more
 * details and how to avoid this limitation.
 *
 * @param tp The time point to convert, represented as a HRTimePointStd time point.
 * @return The Julian Date Time corresponding to the given time point (it can loss precision).
 *
 * @note The precision of the Julian Date returned by this function is limited by the precision of the 'long double'
 * type used in the calculation. On systems where 'std::numeric_limits<long double>::digits10' reports 18, this
 * function can typically provide precision up to milliseconds. However, the precision may degrade for time points
 * representing dates far from the Unix epoch, due to the limits in floating-point representation of large numbers
 * combined with small fractional parts.
 *
 * @warning This function typically offers precision up to milliseconds under usual circumstances. For applications
 * requiring full nanosecond precision under usual use circumstances, you can use the function
 * 'timePointToModifiedJulianDatetime' and work with Modified Julian Date Time (that usually fits in long double types)
 * or the function 'timePointToJulianDate' to separately handle integer and fractional parts of the Julian Date Time.
 * These approaches can help mitigate precision limitations by dividing the calculation into parts that can be more
 * accurately represented within the available precision.
 *
 * @see julianDatetimeToTimePoint for the reverse conversion.
 */
LIBDPBASE_EXPORT dates::JDateTime timePointToJulianDateTime(const types::HRTimePointStd &tp);

/**
 * @brief Converts a HRTimePointStd to Julian Date and the fractional part of the day.
 *
 * This function calculates the Julian Date corresponding to a given time point, along with the fractional part
 * of the day expressed as a fraction of a day. It provides nanosecond precision in determining the fractional
 * part of the day, suitable for applications requiring high temporal accuracy.
 *
 * @param [in] tp The high-resolution time point to convert, represented as HRTimePointStd.
 * @param [out] jd The Julian Date corresponding to the time point with adjustments for the day starting from noon.
 * @param [out] fraction A reference to a DayFraction variable where the fractional part of the day will be stored.
 *                       This fraction is a long double value that represents the fraction of a day that has passed.
 *
 * @note The function provides nanosecond precision for the fractional part of the day, ensuring accurate time
 * representation for applications that require such detail.
 *
 * @warning This function assumes that the input time point is based on the Unix epoch (1970-01-01T00:00:00Z). It may
 * not accurately represent times before the Unix epoch.
 *
 * @see julianDateToTimePoint for the reverse conversion.
 */

/**
 * TODO CHAGE DOC
 * @brief Converts a HRTimePointStd to Julian Date without considering the fractional part of the day.
 *
 * This function calculates the Julian Date for a given time point without returning the fractional part of the day.
 * It is suitable for applications where only the Julian Date is required, and the time of day (fractional part) is
 * not needed. This function provides an integer representation of the Julian Date.
 *
 * @param [in] tp The high-resolution time point to convert, represented as HRTimePointStd.
 * @return JDate The Julian Date corresponding to the given time point. The returned Julian Date represents the
 *         number of days since the beginning of the Julian period (January 1, 4713 BC) and starts from noon
 *
 * @warning This function assumes that the input time point is based on the Unix epoch (1970-01-01T00:00:00Z).
 *          It may not accurately represent times before the Unix epoch or provide the time of day precision.
 *
 * @see timePointToJulianDate(const HRTimePointStd &tp, DayFraction& fraction) for a version of this function that
 *      also returns the fractional part of the Julian day.
 */
LIBDPBASE_EXPORT dates::JDateTime timePointToJulianDateTime(const types::HRTimePointStd &tp);

/**
 * @brief Converts a timepoint to a Modified Julian DateTime.
 * @param tp The timepoint.
 * @return A MJDateTime representing tp.
 */
LIBDPBASE_EXPORT dates::MJDateTime timePointToModifiedJulianDateTime(const types::HRTimePointStd &tp);


/**
 * @brief Converts a timepoint to a J2000 DateTime.
 * @param tp The timepoint.
 * @return A J2000DateTime representing tp.
 */
LIBDPBASE_EXPORT dates::J2000DateTime timePointToJ2000DateTime(const types::HRTimePointStd &tp);

/**
 * @brief Get seconds of day from timepoint
 * @param tp The timepoint.
 * @return The seconds elapsed since day start with fraction.
 */
LIBDPBASE_EXPORT long double timePointToSecsDay(const types::HRTimePointStd& tp);

// =====================================================================================================================

// JULIAN DATETIME CONVERSION FUNCTIONS
// =====================================================================================================================
/**
 * @brief Converts JDateTime to a HRTimePointStd with precision up to milliseconds.
 *
 * This function converts a given Julian Date Time (JDT) to a high-resolution time point (HRTimePointStd),
 * represented as the number of nanoseconds since the Unix epoch (1970-01-01T00:00:00Z). The precision of the time
 * point returned by this function is limited by the precision of the 'long double' type used in the calculation.
 * Typically provide precision up to milliseconds approximately but deppends how far is the date from the epoch. See
 * the **Note** and **Warning** sections for more details and how to avoid this limitation.
 *
 * @param jdt The Julian Date Time to be converted.
 * @return A HRTimePointStd The time in terms of nanoseconds since the Unix epoch (it can loss precision).
 *
 * @throws std::invalid_argument If the calculated time point is before the Unix epoch, indicating an error in
 *         conversion or an out-of-range input value.
 *
 * @note The precision of the time point returned by this function is limited by the precision of the 'long double'
 * type used in the calculation. On systems where 'std::numeric_limits<long double>::digits10' reports 18, this
 * function can typically provide precision up to milliseconds. However, the precision may degrade for time points
 * representing dates far from the Unix epoch, due to the limits in floating-point representation of large numbers
 * combined with small fractional parts.
 *
 * @warning This function typically offers precision up to milliseconds under usual circumstances. For applications
 * requiring full nanosecond precision under usual use circumstances, you can use the function
 * 'modifiedJulianDatetimeToTimePoint' and work with Modified Julian Date Time (that usually fits in long double types)
 * or the function 'julianDateToTimePoint' to separately handle integer and fractional parts of the Julian Date Time.
 * These approaches can help mitigate precision limitations by dividing the calculation into parts that can be more
 * accurately represented within the available precision.
 *
 * @see timePointToJulianDatetime for the reverse conversion.
 */

LIBDPBASE_EXPORT types::HRTimePointStd julianDateTimeToTimePoint(const dates::JDateTime& jdt);
// =====================================================================================================================

// MODIFIED JULIAN DATETIME CONVERSIONS
// =====================================================================================================================
/**
 * @brief Converts a Modified Julian Datetime to a TimePoint.
 * @param mjdt Modified Julian Datetime in days. Precission up to ns. Must be within TimePoint era.
 * @return A TimePoint.
 */
LIBDPBASE_EXPORT types::HRTimePointStd modifiedJulianDateTimeToTimePoint(const dates::MJDateTime &mjdt);

/**
 * @brief Converts a Modified Julian Datetime to a J2000 Datetime.
 * @param mjdt Modified Julian Datetime in days. Precission up to ns.
 * @return A J2000DateTime.
 */
LIBDPBASE_EXPORT dates::J2000DateTime modifiedJulianDateToJ2000DateTime(const dates::MJDateTime &mjdt);
// =====================================================================================================================

// WIN32 TICKS CONVERSION FUNCTIONS
// =====================================================================================================================
/**
 * @brief Converts Windows32Ticks to a HRTimePointStd with nanosecond precision.
 *
 * Windows32Ticks ticks are defined as the number of 100-nanosecond intervals since January 1, 1601 (UTC). This
 * function converts those ticks into a `std::chrono::time_point` of the high-resolution clock, which represents the
 * corresponding time in the POSIX epoch (i.e., the number of seconds that have elapsed since January 1, 1970, UTC).
 * The conversion provides nanosecond precision, suitable for high-resolution time measurements.
 *
 * @param ticks The number of Windows32Ticks ticks to convert.
 * @return A HRTimePointStd representing the time in the POSIX epoch, with nanosecond precision.
 *
 * @throws std::invalid_argument If the calculated time point is before the Unix epoch, indicating an error in
 *         conversion or an out-of-range input value.
 *
 * @note This function assumes that the ticks are based on the Win32 epoch starting from January 1, 1601 (UTC). It is
 * important to ensure that input tick values are within a reasonable range to prevent erroneous conversions.
 *
 * @see common::kNsPerWin32Tick, common::kWin32EpochToPosixEpoch for constants used in conversions.
 */
LIBDPBASE_EXPORT types::HRTimePointStd win32TicksToTimePoint(types::Windows32Ticks ticks);
// =====================================================================================================================

// TLE DATE CONVERSION FUNCTIONS
// =====================================================================================================================
/**
 * @brief Converts a timepoint to a TLE Date.
 * @param tp The timepoint.
 * @param cent_year The last two digits of the year.
 * @param day_with_fract The day of the year with the fraction
 */
LIBDPBASE_EXPORT void timePointToTLEDate(const types::HRTimePointStd& tp, int& cent_year, long double& day_with_fract);

/**
 * @brief Converts a TLE date to a timepoint.
 * @param cent_year The last two digits of the year
 * @param day_with_fract The day of the year with the fractionary part.
 * @return A timepoint representing the TLE date.
 */
LIBDPBASE_EXPORT types::HRTimePointStd tleDateToTimePoint(unsigned int cent_year, long double day_with_fract);
// =====================================================================================================================


// HELPER FUNCTIONS
// =====================================================================================================================

/**
 * @brief Transform hh:mm::ss hour to nanoseconds of day.
 * @param hour The hours.
 * @param min The minutes.
 * @param sec The seconds.
 * @param ns The nanoseconds.
 * @return Nanoseconds elapsed since start of day.
 */
LIBDPBASE_EXPORT long long hhmmssnsToNsDay(unsigned int hour, unsigned int min, unsigned int sec, unsigned int ns);

/**
 * @brief Transforms nanoseconds elapsed since start of day to hh:mm:ss hour.
 * @param ns_in The nanoseconds elapsed since start of day.
 * @param hour_out The hours.
 * @param min_out The minutes.
 * @param sec_out The seconds.
 * @param ns_out The nanoseconds.
 * @return The number of days elapsed since start of day.
 */
LIBDPBASE_EXPORT long long nsDayTohhmmssns(long long ns_in, unsigned int& hour_out, unsigned int& min_out,
                                        unsigned int& sec_out, unsigned int& ns_out);

/**
 * @brief Transforms the day of the year to the month and day of the month.
 * @param year The year.
 * @param yday The day of the year.
 * @param month [out] The resulting month.
 * @param mday [out] The resulting day of the month.
 *
 * @warning This function does not work correctly for years like 2100, etc.
 *          It is not designed to handle leap years after the year 2000.
 *          Use with caution for such cases.
 */
LIBDPBASE_EXPORT void ydtomd(int year, unsigned int yday, unsigned int& month, unsigned int& mday);

/**
 * @brief Converts a Gregorian Date to Julian.
 *
 * @param year, Gregorian year.
 * @param month, in range [1,12].
 * @param day, in range [1,31].
 * @param hour, in range [0,23].
 * @param minute, in range [0,59].
 * @param second, in range [0,59].
 * @param jd_day, Julian day. Output.
 * @param jd_fract, Julian fraction of day. Output.
 *
 * @warning Not works with the 2100, etc year (but we will be dead xD).
 */
LIBDPBASE_EXPORT void grtojd(int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute,
                            unsigned int sec, long long &jd_day, long double &jd_fract);

/**
 * @brief Converts a Julian Date to Gregorian
 *
 * @param jd_day, Julian day
 * @param jd_fract, Julian fraction of day
 * @param year, Gregorian year. Output.
 * @param month, in range [1,12]. Output.
 * @param day, in range [1,31]. Output.
 * @param hour, in range [0,23]. Output.
 * @param minute, in range [0,59]. Output.
 * @param second, in range [0,59]. Output.
 *
 * @warning Not works with the 2100, etc year (but we will be dead xD).
 */
LIBDPBASE_EXPORT void jdtogr(long long jd_day, long double jd_fract,int &year, unsigned int &month,
                            unsigned int &day, unsigned int &hour, unsigned int &minute, unsigned int &second);


/**
 * @brief Calculates the number of days since the civil date of 1970-01-01.
 *
 * This function computes the number of days from the Gregorian calendar date
 * specified by the year (y), month (m), and day (d) parameters to the epoch date
 * of 1970-01-01. Negative return values indicate dates prior to 1970-01-01. The
 * input date must be in the civil (Gregorian) calendar.
 *
 * @param y The year of the date, can be any integer representing the year.
 * @param m The month of the date, must be in the range [1, 12].
 * @param d The day of the month, must be in the valid range for the given month and year.
 *
 * @return The number of days since 1970-01-01. Negative values indicate dates before 1970-01-01.
 *
 * @warning The function uses static_assert to ensure that the size of unsigned and int types
 * meets the minimum requirements for the calculation.
 */
LIBDPBASE_EXPORT long long daysFromCivil(int y, unsigned m, unsigned d);

/**
 * @brief Convert a given date and time to a HRTimePointStd.
 *
 * This function converts the provided date and time components to a HRTimePointStd
 * based on the high_resolution_clock clock.
 *
 * @param y   The year.
 * @param m   The month (1-12).
 * @param d   The day of the month.
 * @param h   The hour of the day.
 * @param min The minute of the hour.
 * @param s   The second of the minute.
 * @return The HRTimePointStd representing the specified date and time.
 */
LIBDPBASE_EXPORT types::HRTimePointStd dateAndTimeToTp(int y, int m, int d, int h=0, int min=0, int s=0);

// =====================================================================================================================


// TODO AND NON-EXPORTED FUNCTIONS
// =====================================================================================================================

// Conversions for RJ DateTime
/**
 * @brief Converts a high-resolution time point to a reduced Julian datetime.
 * @param tp The high-resolution time point.
 * @return The reduced Julian datetime corresponding to the given time point.
 */
//LIBDPBASE_EXPORT RJDateTime timePointToReducedJulianDatetime(const HRTimePointStd &tp);

// Astronomical time functions
//LIBDPBASE_EXPORT long double jdtToGmst(long double jd);
//LIBDPBASE_EXPORT long double jdtToLmst(long double jdt, long double lon);





// =====================================================================================================================




// =====================================================================================================================














}} // END NAMESPACES.
// =====================================================================================================================
