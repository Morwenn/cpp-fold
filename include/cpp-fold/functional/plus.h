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
#ifndef CPPFOLD_FUNCTIONAL_PLUS_H_
#define CPPFOLD_FUNCTIONAL_PLUS_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <utility>
#include <cpp-fold/identity_element.h>

namespace cppfold
{
    struct plus
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& lhs, U&& rhs) const
            -> decltype(std::forward<T>(lhs) + std::forward<U>(rhs))
        {
            return std::forward<T>(lhs) + std::forward<U>(rhs);
        }
    };

    ////////////////////////////////////////////////////////////
    // Built-in types specializations

    template<>
    struct identity_element<unsigned char, plus>
    {
        static constexpr unsigned char value = '\0';
    };

    template<>
    struct identity_element<signed char, plus>
    {
        static constexpr signed char value = '\0';
    };

    template<>
    struct identity_element<wchar_t, plus>
    {
        static constexpr wchar_t value = L'\0';
    };

    template<>
    struct identity_element<char16_t, plus>
    {
        static constexpr char16_t value = u'\0';
    };

    template<>
    struct identity_element<char32_t, plus>
    {
        static constexpr char32_t value = U'\0';
    };

    template<>
    struct identity_element<unsigned short, plus>
    {
        static constexpr unsigned short value = 0U;
    };

    template<>
    struct identity_element<signed short, plus>
    {
        static constexpr signed short value = 0;
    };

    template<>
    struct identity_element<unsigned int, plus>
    {
        static constexpr unsigned int value = 0U;
    };

    template<>
    struct identity_element<signed int, plus>
    {
        static constexpr signed int value = 0;
    };

    template<>
    struct identity_element<unsigned long, plus>
    {
        static constexpr unsigned long value = 0UL;
    };

    template<>
    struct identity_element<signed long, plus>
    {
        static constexpr signed long value = 0L;
    };

    template<>
    struct identity_element<unsigned long long, plus>
    {
        static constexpr unsigned long long value = 0ULL;
    };

    template<>
    struct identity_element<signed long long, plus>
    {
        static constexpr signed long long value = 0LL;
    };

    template<>
    struct identity_element<float, plus>
    {
        static constexpr float value = 0.0F;
    };

    template<>
    struct identity_element<double, plus>
    {
        static constexpr double value = 0.0;
    };

    template<>
    struct identity_element<long double, plus>
    {
        static constexpr long double value = 0.0L;
    };
}

#endif // CPPFOLD_FUNCTIONAL_PLUS_H_
