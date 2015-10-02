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
#ifndef CPPFOLD_FUNCTIONAL_MINUS_H_
#define CPPFOLD_FUNCTIONAL_MINUS_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <functional>
#include <cpp-fold/identity_element.h>

namespace cppfold
{
    using minus = std::minus<>;

    ////////////////////////////////////////////////////////////
    // Built-in types specializations

    template<>
    struct right_identity_element<unsigned char, minus>
    {
        static constexpr unsigned char value = '\0';
    };

    template<>
    struct right_identity_element<signed char, minus>
    {
        static constexpr signed char value = '\0';
    };

    template<>
    struct right_identity_element<wchar_t, minus>
    {
        static constexpr wchar_t value = L'\0';
    };

    template<>
    struct right_identity_element<char16_t, minus>
    {
        static constexpr char16_t value = u'\0';
    };

    template<>
    struct right_identity_element<char32_t, minus>
    {
        static constexpr char32_t value = U'\0';
    };

    template<>
    struct right_identity_element<unsigned short, minus>
    {
        static constexpr unsigned short value = 0U;
    };

    template<>
    struct right_identity_element<signed short, minus>
    {
        static constexpr signed short value = 0;
    };

    template<>
    struct right_identity_element<unsigned int, minus>
    {
        static constexpr unsigned int value = 0U;
    };

    template<>
    struct right_identity_element<signed int, minus>
    {
        static constexpr signed int value = 0;
    };

    template<>
    struct right_identity_element<unsigned long, minus>
    {
        static constexpr unsigned long value = 0UL;
    };

    template<>
    struct right_identity_element<signed long, minus>
    {
        static constexpr signed long value = 0L;
    };

    template<>
    struct right_identity_element<unsigned long long, minus>
    {
        static constexpr unsigned long long value = 0ULL;
    };

    template<>
    struct right_identity_element<signed long long, minus>
    {
        static constexpr signed long long value = 0LL;
    };

    template<>
    struct right_identity_element<float, minus>
    {
        static constexpr float value = 0.0F;
    };

    template<>
    struct right_identity_element<double, minus>
    {
        static constexpr double value = 0.0;
    };

    template<>
    struct right_identity_element<long double, minus>
    {
        static constexpr long double value = 0.0L;
    };
}

#endif // CPPFOLD_FUNCTIONAL_MINUS_H_
