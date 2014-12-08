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
#ifndef CPPFOLD_STD_STRING_H_
#define CPPFOLD_STD_STRING_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <string>
#include <cpp-fold/identity_element.h>
#include <cpp-fold/functional/plus.h>

namespace cppfold
{
    template<typename CharT, typename Traits, typename Alloc>
    struct identity_element<std::basic_string<CharT, Traits, Alloc>, plus>
    {
        static const std::basic_string<CharT, Traits, Alloc> value;
    };

    template<typename CharT, typename Traits, typename Alloc>
    const std::basic_string<CharT, Traits, Alloc>
    identity_element<std::basic_string<CharT, Traits, Alloc>, plus>::value = "";
}

#endif // CPPFOLD_STD_STRING_H_
