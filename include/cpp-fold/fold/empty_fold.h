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
#ifndef CPPFOLD_FOLD_EMPTY_FOLD_H_
#define CPPFOLD_FOLD_EMPTY_FOLD_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <cpp-fold/identity_element.h>

namespace cppfold
{
    template<typename BinaryFunction>
    struct empty_fold
    {
        template<typename T>
        constexpr operator T() const
        {
            return identity_element<T, BinaryFunction>::value;
        }
    };
}

#endif // CPPFOLD_FOLD_EMPTY_FOLD_H_
