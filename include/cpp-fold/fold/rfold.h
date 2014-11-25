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
#ifndef CPPFOLD_FOLD_RFOLD_H_
#define CPPFOLD_FOLD_RFOLD_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <utility>
#include <cpp-fold/fold/empty_fold.h>

namespace cppfold
{
    template<typename BinaryFunction>
    auto rfold()
        -> empty_fold<BinaryFunction>
    {
        return {};
    }

    template<typename BinaryFunction, typename First>
    auto rfold(const First& first)
        -> First
    {
        return first;
    }

    template<typename BinaryFunction, typename First, typename Second>
    auto rfold(First&& first, Second&& second)
        -> decltype(auto)
    {
        return BinaryFunction{}(
            std::forward<First>(first),
            std::forward<Second>(second)
        );
    }

    template<typename BinaryFunction, typename First, typename Second, typename... Tail>
    auto rfold(First&& first, Second&& second, Tail&&... tail)
        -> decltype(auto)
    {
        return BinaryFunction{}(
            std::forward<First>(first),
            rfold<BinaryFunction>(
                std::forward<Second>(second),
                std::forward<Tail>(tail)...
            )
        );
    }
}

#endif // CPPFOLD_FOLD_RFOLD_H_
