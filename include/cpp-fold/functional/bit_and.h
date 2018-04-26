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
#ifndef CPPFOLD_FUNCTIONAL_BIT_AND_H_
#define CPPFOLD_FUNCTIONAL_BIT_AND_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <functional>
#include "../identity_element.h"

namespace cppfold
{
    using bit_and = std::bit_and<>;

    ////////////////////////////////////////////////////////////
    // Built-in types specializations

    template<>
    struct identity_element<unsigned char, bit_and>
    {
        static constexpr unsigned char value = ~'\0';
    };

    template<>
    struct identity_element<signed char, bit_and>
    {
        static constexpr signed char value = ~'\0';
    };

    template<>
    struct identity_element<wchar_t, bit_and>
    {
        static constexpr wchar_t value = ~L'\0';
    };

    template<>
    struct identity_element<char16_t, bit_and>
    {
        static constexpr char16_t value = ~u'\0';
    };

    template<>
    struct identity_element<char32_t, bit_and>
    {
        static constexpr char32_t value = ~U'\0';
    };

    template<>
    struct identity_element<unsigned short, bit_and>
    {
        static constexpr unsigned short value
            = ~static_cast<unsigned short>(0U);
    };

    template<>
    struct identity_element<signed short, bit_and>
    {
        static constexpr signed short value = ~0;
    };

    template<>
    struct identity_element<unsigned int, bit_and>
    {
        static constexpr unsigned int value = ~0U;
    };

    template<>
    struct identity_element<signed int, bit_and>
    {
        static constexpr signed int value = ~0;
    };

    template<>
    struct identity_element<unsigned long, bit_and>
    {
        static constexpr unsigned long value = ~0UL;
    };

    template<>
    struct identity_element<signed long, bit_and>
    {
        static constexpr signed long value = ~0L;
    };

    template<>
    struct identity_element<unsigned long long, bit_and>
    {
        static constexpr unsigned long long value = ~0ULL;
    };

    template<>
    struct identity_element<signed long long, bit_and>
    {
        static constexpr signed long long value = ~0LL;
    };
}

#endif // CPPFOLD_FUNCTIONAL_BIT_AND_H_
