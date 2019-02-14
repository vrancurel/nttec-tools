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
#include <string>

#include "quadiron_tools.h"

gmp_randclass r(gmp_randinit_default);

mpz_class rand_func(mpz_class n)
{
  return r.get_z_range(n);
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cerr << "usage: find_pminus1_compo start_n min_n_factors\n";
        return 1;
    }

    mpz_class n(argv[1]);
    int min_n_factors(std::stoi(argv[2]));

    while (true) {
        if (n % 2 == 0) {
            n++;
            continue;
        }
        if (quadiron::arith::solovay_strassen<mpz_class>(n, rand_func)) {
            // number is probably prime: double-check
            if (quadiron::arith::is_prime(n)) {
                std::vector<mpz_class> primes;
                std::vector<int> exponents;

                quadiron::arith::factor_prime<mpz_class>(n-1, &primes, &exponents);
                typename std::vector<mpz_class>::size_type i;
                mpz_class n_factors = 0;
                for (i = 0; i != primes.size(); i++) {
                    n_factors += exponents.at(i);
                }
                if (n_factors > min_n_factors) {
                    std::cout << n << "-1=";
                    for (i = 0; i != primes.size(); i++) {
                        std::cout << primes.at(i)    << '^'
                                  << exponents.at(i) << ' ';
                    }
                    std::cout << '\n';
                }
            }
        }
        n++;
    }
}
