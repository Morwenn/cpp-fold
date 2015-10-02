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
#include <utility>
#include <cpp-fold/identity_element.h>

namespace cppfold
{
    struct minus
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& lhs, U&& rhs) const
            -> decltype(std::forward<T>(lhs) - std::forward<U>(rhs))
        {
            return std::forward<T>(lhs) - std::forward<U>(rhs);
        }
    };

    ////////////////////////////////////////////////////////////
    // Built-in types specializations

    template<>
    constexpr unsigned char right_identity_element<unsigned char, minus> = '\0';

    template<>
    constexpr signed char right_identity_element<signed char, minus> = '\0';

    template<>
    constexpr wchar_t right_identity_element<wchar_t, minus> = L'\0';

    template<>
    constexpr char16_t right_identity_element<char16_t, minus> = u'\0';

    template<>
    constexpr char32_t right_identity_element<char32_t, minus> = U'\0';

    template<>
    constexpr unsigned short right_identity_element<unsigned short, minus> = 0U;

    template<>
    constexpr signed short right_identity_element<signed short, minus> = 0;

    template<>
    constexpr unsigned int right_identity_element<unsigned int, minus> = 0U;

    template<>
    constexpr signed int right_identity_element<signed int, minus> = 0;

    template<>
    constexpr unsigned long right_identity_element<unsigned long, minus> = 0UL;

    template<>
    constexpr signed long right_identity_element<signed long, minus> = 0L;

    template<>
    constexpr unsigned long long right_identity_element<unsigned long long, minus> = 0ULL;

    template<>
    constexpr signed long long right_identity_element<signed long long, minus> = 0LL;

    template<>
    constexpr float right_identity_element<float, minus> = 0.0F;

    template<>
    constexpr double right_identity_element<double, minus> = 0.0;

    template<>
    constexpr long double right_identity_element<long double, minus> = 0.0L;
}

#endif // CPPFOLD_FUNCTIONAL_MINUS_H_
