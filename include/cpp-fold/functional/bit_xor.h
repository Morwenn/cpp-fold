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
#ifndef CPPFOLD_FUNCTIONAL_BIT_XOR_H_
#define CPPFOLD_FUNCTIONAL_BIT_XOR_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <utility>

namespace cppfold
{
    struct bit_xor
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& lhs, U&& rhs) const
            -> decltype(std::forward<T>(lhs) ^ std::forward<U>(rhs))
        {
            return std::forward<T>(lhs) ^ std::forward<U>(rhs);
        }
    };

    ////////////////////////////////////////////////////////////
    // Built-in types specializations

    template<>
    struct identity_element<unsigned char, bit_xor>
    {
        static constexpr unsigned char value = '\0';
    };

    template<>
    struct identity_element<signed char, bit_xor>
    {
        static constexpr signed char value = '\0';
    };

    template<>
    struct identity_element<wchar_t, bit_xor>
    {
        static constexpr wchar_t value = L'\0';
    };

    template<>
    struct identity_element<char16_t, bit_xor>
    {
        static constexpr char16_t value = u'\0';
    };

    template<>
    struct identity_element<char32_t, bit_xor>
    {
        static constexpr char32_t value = U'\0';
    };

    template<>
    struct identity_element<unsigned short, bit_xor>
    {
        static constexpr unsigned short value = 0U;
    };

    template<>
    struct identity_element<signed short, bit_xor>
    {
        static constexpr signed short value = 0;
    };

    template<>
    struct identity_element<unsigned int, bit_xor>
    {
        static constexpr unsigned int value = 0U;
    };

    template<>
    struct identity_element<signed int, bit_xor>
    {
        static constexpr signed int value = 0;
    };

    template<>
    struct identity_element<unsigned long, bit_xor>
    {
        static constexpr unsigned long value = 0UL;
    };

    template<>
    struct identity_element<signed long, bit_xor>
    {
        static constexpr signed long value = 0L;
    };

    template<>
    struct identity_element<unsigned long long, bit_xor>
    {
        static constexpr unsigned long long value = 0ULL;
    };

    template<>
    struct identity_element<signed long long, bit_xor>
    {
        static constexpr signed long long value = 0LL;
    };
}

#endif // CPPFOLD_FUNCTIONAL_BIT_XOR_H_
