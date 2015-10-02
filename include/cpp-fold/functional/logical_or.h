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
#ifndef CPPFOLD_FUNCTIONAL_LOGICAL_OR_H_
#define CPPFOLD_FUNCTIONAL_LOGICAL_OR_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <utility>
#include <cpp-fold/identity_element.h>

namespace cppfold
{
    struct logical_or
    {
        template<typename T, typename U>
        constexpr auto operator()(T&& lhs, U&& rhs) const
            -> decltype(std::forward<T>(lhs) || std::forward<U>(rhs))
        {
            return std::forward<T>(lhs) || std::forward<U>(rhs);
        }
    };

    ////////////////////////////////////////////////////////////
    // Built-in types specializations

    template<>
    constexpr bool identity_element<bool, logical_or> = false;
}

#endif // CPPFOLD_FUNCTIONAL_LOGICAL_OR_H_
