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
#include <signal.h>

#include "quadiron_tools.h"

double tot = 0;
double ok = 0;

void sigint(int signo)
{
    std::cerr << "total=" << tot << " ok=" << ok << " succ_rate=" <<
        ok / tot * 100 << "%\n";
    exit(1);
}

gmp_randclass r(gmp_randinit_default);

mpz_class rand_func(mpz_class n)
{
  return r.get_z_range(n);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "usage: find_primes n_bits\n";
        return 1;
    }

    int n_bits = std::stoi(argv[1]);

    signal(SIGINT, sigint);

    for (int i = 0; i < 100000; i++) {
        mpz_class n = r.get_z_bits(n_bits);
        if (n % 2 == 0) {
            continue;
        }
        bool result = quadiron::arith::solovay_strassen<mpz_class>(n, rand_func);
        tot++;
        if (result) {
            ok++;
            std::cout << n << "\n";
        }
    }
    return 0;
}
