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
 * @file string_helpers.tpp
 * @brief This file contains the function implementations related with the string helper tools.
 * @author Degoras Project Team
 * @copyright EUPL License
 2305.1
***********************************************************************************************************************/

// ========== C++ INCLUDES =============================================================================================
#include <algorithm>
#include <stdexcept>
#include <regex>
#include <random>
// =====================================================================================================================

// ========== DP INCLUDES ==============================================================================================
#include "LibDegorasBase/Helpers/string_helpers.h"
// =====================================================================================================================

// ========== DPBASE NAMESPACES =========================================================================================
namespace dpbase{
namespace helpers{
namespace strings{
// =====================================================================================================================

std::string toUpper(const std::string& str)
{
    // Aux string.
    std::string result;
    // Make the transformation and return the new string..
    std::transform(str.begin(), str.end(), std::back_inserter(result), ::toupper);
    return result;
}

std::string toLower(const std::string& str)
{
    // Aux string.
    std::string result;
    // Make the transformation and return the new string..
    std::transform(str.begin(), str.end(), std::back_inserter(result), ::tolower);
    return result;
}

std::string ltrim(const std::string &s)
{
    return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
}

std::string rtrim(const std::string &s)
{
    return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
}

std::string trim(const std::string &s)
{
    return ltrim(rtrim(s));
}

std::string rmLastLineBreak(const std::string &s)
{
    return s.substr(0, s.find_last_of('\n'));
}

std::string generateLoremIpsum(unsigned int paragraphs, unsigned int sentences, unsigned int words)
{
    std::vector<std::string> lorem_ipsum_words = {"Lorem", "ipsum", "dolor", "sit", "amet", "consectetur",
                                                 "adipiscing", "elit"};
    std::string result;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, lorem_ipsum_words.size() - 1);
    for (int p = 0; p < paragraphs; ++p)
    {
        for (int s = 0; s < sentences; ++s)
        {
            for (int w = 0; w < words; ++w)
                result += lorem_ipsum_words[dis(gen)] + " ";
            result += ". ";
        }
        result += "\n\n";
    }
    return result;
}

std::string replaceStr(const std::string& str, const std::string& target, const std::string& replacement)
{
    std::string result = str;
    size_t pos = 0;
    while ((pos = result.find(target, pos)) != std::string::npos)
    {
        result.replace(pos, target.length(), replacement);
        pos += replacement.length();
    }
    return result;
}

std::string fillStr(const std::string& fillChar, size_t width)
{
    std::string result;
    int fillSize = width / fillChar.size();
    int remainder = width % fillChar.size();

    for (int i = 0; i < fillSize; ++i) {
        result += fillChar;
    }

    if (remainder > 0) {
        result += fillChar.substr(0, remainder);
    }

    return result;
}

}}}// END NAMESPACES.
// =====================================================================================================================
