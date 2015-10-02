/*
 * Copyright (C) 2014-2015 Morwenn
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
#ifndef CPPFOLD_FUNCTIONAL_DIVIDES_H_
#define CPPFOLD_FUNCTIONAL_DIVIDES_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <utility>
#include <cpp-fold/identity_element.h>

namespace cppfold
{
    struct divides
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& lhs, U&& rhs) const
            -> decltype(std::forward<T>(lhs) / std::forward<U>(rhs))
        {
            return std::forward<T>(lhs) / std::forward<U>(rhs);
        }
    };

    ////////////////////////////////////////////////////////////
    // Built-in types specializations

    template<>
    constexpr unsigned char right_identity_element<unsigned char, divides> = 1U;

    template<>
    constexpr signed char right_identity_element<signed char, divides> = 1;

    template<>
    constexpr wchar_t right_identity_element<wchar_t, divides> = 1;

    template<>
    constexpr char16_t right_identity_element<char16_t, divides> = 1;

    template<>
    constexpr char32_t right_identity_element<char32_t, divides> = 1;

    template<>
    constexpr unsigned short right_identity_element<unsigned short, divides> = 1U;

    template<>
    constexpr signed short right_identity_element<signed short, divides> = 1;

    template<>
    constexpr unsigned int right_identity_element<unsigned int, divides> = 1U;

    template<>
    constexpr signed int right_identity_element<signed int, divides> = 1;

    template<>
    constexpr unsigned long right_identity_element<unsigned long, divides> = 1UL;

    template<>
    constexpr signed long right_identity_element<signed long, divides> = 1L;

    template<>
    constexpr unsigned long long right_identity_element<unsigned long long, divides> = 1ULL;

    template<>
    constexpr signed long long right_identity_element<signed long long, divides> = 1LL;

    template<>
    constexpr float right_identity_element<float, divides> = 1.0F;

    template<>
    constexpr double right_identity_element<double, divides> = 1.0;

    template<>
    constexpr long double right_identity_element<long double, divides> = 1.0L;
}

#endif // CPPFOLD_FUNCTIONAL_DIVIDES_H_
