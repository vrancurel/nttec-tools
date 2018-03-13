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

#include <signal.h>

#include <gmpxx.h>

#include <nttec/nttec.h>

double tot = 0;
double ok = 0;

void sigint(int signo)
{
    std::cerr << "total=" << tot << " ok=" << ok << " succ_rate=" <<
        ok / tot * 100 << "%\n";
    exit(1);
}

int main(int argc, char **argv)
{
    nttec::gf::Prime<mpz_class> gfp(3);
    if (argc != 2) {
        std::cerr << "usage: find_primes n_bits\n";
        return 1;
    }

    int n_bits = std::stoi(argv[1]);
    gmp_randclass r(gmp_randinit_default);

    signal(SIGINT, sigint);

    for (int i = 0; i < 100000; i++) {
        mpz_class n = r.get_z_bits(n_bits);
        if (n % 2 == 0) {
            continue;
        }
        bool result = gfp._solovay_strassen(n);
        tot++;
        if (result) {
            ok++;
            std::cout << n << "\n";
        }
    }
    return 0;
}
