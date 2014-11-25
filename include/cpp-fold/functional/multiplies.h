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
    struct identity_element<unsigned char, multiplies>
    {
        static constexpr unsigned char value = 1U;
    };

    template<>
    struct identity_element<signed char, multiplies>
    {
        static constexpr signed char value = 1;
    };

    template<>
    struct identity_element<wchar_t, multiplies>
    {
        static constexpr wchar_t value = 1;
    };

    template<>
    struct identity_element<char16_t, multiplies>
    {
        static constexpr char16_t value = 1;
    };

    template<>
    struct identity_element<char32_t, multiplies>
    {
        static constexpr char32_t value = 1;
    };

    template<>
    struct identity_element<unsigned short, multiplies>
    {
        static constexpr unsigned short value = 1U;
    };

    template<>
    struct identity_element<signed short, multiplies>
    {
        static constexpr signed short value = 1;
    };

    template<>
    struct identity_element<unsigned int, multiplies>
    {
        static constexpr unsigned int value = 1U;
    };

    template<>
    struct identity_element<signed int, multiplies>
    {
        static constexpr signed int value = 1;
    };

    template<>
    struct identity_element<unsigned long, multiplies>
    {
        static constexpr unsigned long value = 1UL;
    };

    template<>
    struct identity_element<signed long, multiplies>
    {
        static constexpr signed long value = 1L;
    };

    template<>
    struct identity_element<unsigned long long, multiplies>
    {
        static constexpr unsigned long long value = 1ULL;
    };

    template<>
    struct identity_element<signed long long, multiplies>
    {
        static constexpr signed long long value = 1LL;
    };

    template<>
    struct identity_element<float, multiplies>
    {
        static constexpr float value = 1.0F;
    };

    template<>
    struct identity_element<double, multiplies>
    {
        static constexpr double value = 1.0;
    };

    template<>
    struct identity_element<long double, multiplies>
    {
        static constexpr long double value = 1.0L;
    };
}

#endif // CPPFOLD_FUNCTIONAL_MULTIPLIES_H_
