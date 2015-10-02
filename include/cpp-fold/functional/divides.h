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
#include <functional>
#include <cpp-fold/identity_element.h>

namespace cppfold
{
    using divides = std::divides<>;

    ////////////////////////////////////////////////////////////
    // Built-in types specializations

    template<>
    struct right_identity_element<unsigned char, divides>
    {
        static constexpr unsigned char value = 1U;
    };

    template<>
    struct right_identity_element<signed char, divides>
    {
        static constexpr signed char value = 1;
    };

    template<>
    struct right_identity_element<wchar_t, divides>
    {
        static constexpr wchar_t value = 1;
    };

    template<>
    struct right_identity_element<char16_t, divides>
    {
        static constexpr char16_t value = 1;
    };

    template<>
    struct right_identity_element<char32_t, divides>
    {
        static constexpr char32_t value = 1;
    };

    template<>
    struct right_identity_element<unsigned short, divides>
    {
        static constexpr unsigned short value = 1U;
    };

    template<>
    struct right_identity_element<signed short, divides>
    {
        static constexpr signed short value = 1;
    };

    template<>
    struct right_identity_element<unsigned int, divides>
    {
        static constexpr unsigned int value = 1U;
    };

    template<>
    struct right_identity_element<signed int, divides>
    {
        static constexpr signed int value = 1;
    };

    template<>
    struct right_identity_element<unsigned long, divides>
    {
        static constexpr unsigned long value = 1UL;
    };

    template<>
    struct right_identity_element<signed long, divides>
    {
        static constexpr signed long value = 1L;
    };

    template<>
    struct right_identity_element<unsigned long long, divides>
    {
        static constexpr unsigned long long value = 1ULL;
    };

    template<>
    struct right_identity_element<signed long long, divides>
    {
        static constexpr signed long long value = 1LL;
    };

    template<>
    struct right_identity_element<float, divides>
    {
        static constexpr float value = 1.0F;
    };

    template<>
    struct right_identity_element<double, divides>
    {
        static constexpr double value = 1.0;
    };

    template<>
    struct right_identity_element<long double, divides>
    {
        static constexpr long double value = 1.0L;
    };
}

#endif // CPPFOLD_FUNCTIONAL_DIVIDES_H_
