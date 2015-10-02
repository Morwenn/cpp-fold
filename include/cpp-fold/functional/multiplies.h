/*
 * Copyright (C) 2014 Morwenn
 *
 * cpp-fold is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * cpp-fold is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program. If not,
 * see <http://www.gnu.org/licenses/>.
 */
#ifndef CPPFOLD_FUNCTIONAL_MULTIPLIES_H_
#define CPPFOLD_FUNCTIONAL_MULTIPLIES_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <utility>
#include <cpp-fold/identity_element.h>

namespace cppfold
{
    struct multiplies
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& lhs, U&& rhs) const
            -> decltype(std::forward<T>(lhs) * std::forward<U>(rhs))
        {
            return std::forward<T>(lhs) * std::forward<U>(rhs);
        }
    };

    ////////////////////////////////////////////////////////////
    // Built-in types specializations

    template<>
    constexpr unsigned char identity_element<unsigned char, multiplies> = 1U;

    template<>
    constexpr signed char identity_element<signed char, multiplies> = 1;

    template<>
    constexpr wchar_t identity_element<wchar_t, multiplies> = 1;

    template<>
    constexpr char16_t identity_element<char16_t, multiplies> = 1;

    template<>
    constexpr char32_t identity_element<char32_t, multiplies> = 1;

    template<>
    constexpr unsigned short identity_element<unsigned short, multiplies> = 1U;

    template<>
    constexpr signed short identity_element<signed short, multiplies> = 1;

    template<>
    constexpr unsigned int identity_element<unsigned int, multiplies> = 1U;

    template<>
    constexpr signed int identity_element<signed int, multiplies> = 1;

    template<>
    constexpr unsigned long identity_element<unsigned long, multiplies> = 1UL;

    template<>
    constexpr signed long identity_element<signed long, multiplies> = 1L;

    template<>
    constexpr unsigned long long identity_element<unsigned long long, multiplies> = 1ULL;

    template<>
    constexpr signed long long identity_element<signed long long, multiplies> = 1LL;

    template<>
    constexpr float identity_element<float, multiplies> = 1.0F;

    template<>
    constexpr double identity_element<double, multiplies> = 1.0;

    template<>
    constexpr long double identity_element<long double, multiplies> = 1.0L;
}

#endif // CPPFOLD_FUNCTIONAL_MULTIPLIES_H_
