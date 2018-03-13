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
#include <string>

#include <gmpxx.h>

#include <nttec/nttec.h>

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
        if (nttec::arith::solovay_strassen(n)) {
            // number is probably prime: double-check
            if (nttec::arith::is_prime(n)) {
                std::vector<mpz_class> primes;
                std::vector<mpz_class> exponents;

                nttec::arith::factor_prime(n-1, &primes, &exponents);
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
