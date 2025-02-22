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
 * @file euclidean_div_result.h
 * @author Degoras Project Team.
 * @brief
 * @copyright EUPL License
***********************************************************************************************************************/

// =====================================================================================================================
#pragma once
// =====================================================================================================================

// C++ INCLUDES
// =====================================================================================================================
// =====================================================================================================================

// LIBRARY INCLUDES
// =====================================================================================================================
#include <LibDegorasBase/helpers/type_traits.h>
// =====================================================================================================================

// DPBASE NAMESPACES
// =====================================================================================================================
namespace dpbase{
namespace math{
namespace types{
// =====================================================================================================================

/**
 * @brief Provides signed and unsigned type equivalents for a given type T.
 *
 * This struct template generates type aliases for both the signed and unsigned versions of a given integral type T.
 * It is intended to be used in contexts where you need to explicitly work with both the signed and unsigned variants
 * of a numeric type.
 *
 * @tparam T The base type for which signed and unsigned versions are to be derived.
 */
template <typename T>
struct TypeSigns
{
    using SignedT = typename std::make_signed<T>::type;
    using UnsignedT = typename std::make_unsigned<T>::type;
};

/**
 * @brief Stores the result of an euclidean division, including quotient and remainder.
 *
 * This struct extends TypeSigns<T> to include two members, q and r, which represent the quotient and remainder of
 * an euclidean division, respectively. The quotient is stored as a signed type, and the remainder is stored as an
 * unsigned type. This struct is constrained to be used only with numeric types.
 *
 * @tparam T The base numeric type for the division.
 */
template <typename T, typename = typename std::enable_if<helpers::traits::is_numeric_v<T>>::type>
struct EuclideanDivResult : public TypeSigns<T>
{
    typename TypeSigns<T>::SignedT q;
    typename TypeSigns<T>::UnsignedT r;
};

// ====================================================================================================================

}}} // END NAMESPACES
// =====================================================================================================================
