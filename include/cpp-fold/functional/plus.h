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
    constexpr unsigned char identity_element<unsigned char, plus> = '\0';

    template<>
    constexpr signed char identity_element<signed char, plus> = '\0';

    template<>
    constexpr wchar_t identity_element<wchar_t, plus> = L'\0';

    template<>
    constexpr char16_t identity_element<char16_t, plus> = u'\0';

    template<>
    constexpr char32_t identity_element<char32_t, plus> = U'\0';

    template<>
    constexpr unsigned short identity_element<unsigned short, plus> = 0U;

    template<>
    constexpr signed short identity_element<signed short, plus> = 0;

    template<>
    constexpr unsigned int identity_element<unsigned int, plus> = 0U;

    template<>
    constexpr signed int identity_element<signed int, plus> = 0;

    template<>
    constexpr unsigned long identity_element<unsigned long, plus> = 0UL;

    template<>
    constexpr signed long identity_element<signed long, plus> = 0L;

    template<>
    constexpr unsigned long long identity_element<unsigned long long, plus> = 0ULL;

    template<>
    constexpr signed long long identity_element<signed long long, plus> = 0LL;

    template<>
    constexpr float identity_element<float, plus> = 0.0F;

    template<>
    constexpr double identity_element<double, plus> = 0.0;

    template<>
    constexpr long double identity_element<long double, plus> = 0.0L;
}

#endif // CPPFOLD_FUNCTIONAL_PLUS_H_
