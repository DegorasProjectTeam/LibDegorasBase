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
 * @file container_helpers.cpp
 * @brief This file contains several helper tools related with containers.
 * @author Degoras Project Team
 * @copyright EUPL License
 2305.1
***********************************************************************************************************************/

// LIBRARY INCLUDES
// =====================================================================================================================
#include "LibDegorasBase/Helpers/container_helpers.h"
// =====================================================================================================================

// LIBDPBASE NAMESPACES
// =====================================================================================================================
namespace dpbase{
namespace helpers{
namespace containers{
// =====================================================================================================================

BoolString::BoolString(const std::string &s) : std::string(s)
{
    if (s != "0" && s != "1")
        throw std::invalid_argument(s);
}

BoolString::operator bool() const {return *this == "1";}

}}}// END NAMESPACES.
// =====================================================================================================================
