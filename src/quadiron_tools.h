/*
 * Copyright 2018 the QUADIRON authors
 *
 * This file is part of the QUADIRON tools.
 *
 * The QUADIRON tools are free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * The QUADIRON tools are distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * the QUADIRON tools.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __QUADIRON_TOOLS_H__
#define __QUADIRON_TOOLS_H__ 1

#include <gmpxx.h>
#include <quadiron/core.h>

template <>
struct quadiron::DoubleSize<mpz_class> {
    typedef mpz_class T;
};

template <>
struct quadiron::SignedDoubleSize<mpz_class> {
    typedef mpz_class T;
};

#include <quadiron/quadiron.h>

#endif
