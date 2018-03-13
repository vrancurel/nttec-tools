/*
 * Copyright 2018 the NTTEC authors
 *
 * This file is part of the NTTEC tools.
 *
 * The NTTEC tools are free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * The NTTEC tools are distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * the NTTEC tools.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <gmpxx.h>

#include <nttec/nttec.h>

int main(int argc, char **argv)
{
    nttec::gf::Prime<mpz_class> gfp(3);
    if (argc != 2) {
        std::cerr << "usage: is_prime n\n";
        return 1;
    }

    mpz_class n(argv[1]);
    if (n % 2 == 0) {
        std::cerr << "please choose an odd number\n";
        return 1;
    }

    bool is_prime = gfp.is_prime(n);
    std::cerr << is_prime << "\n";
    return !is_prime;
}
