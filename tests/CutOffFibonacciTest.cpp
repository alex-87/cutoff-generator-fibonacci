/**
 * Copyright (C) 2020 Alexis LE GOADEC.
 * 
 * This file is part of the CutoffFifonacci project which is licensed under
 * the European Union Public License v1.2.
 * 
 * If a copy of the EUPL v1.2 was not distributed with this software,
 * you can obtain one at : https://joinup.ec.europa.eu/collection/eupl/eupl-text-eupl-12
 */

#include "../src/include/CutoffFibonacci.hpp"

#include <criterion/criterion.h>
#include <vector>
#include <limits>
#include <iostream>

Test(Test_Fibonacci, Increment) {

    CutoffFibonacci cof;

    unsigned long int a(0), b(1), c(1);
    std::vector<bool> result;

    for(unsigned int i=0; i<100; i++) {
        result.push_back(cof() == c);
        ++cof;
        if(a + b < c ) {
            c = std::numeric_limits<decltype(c)>::max() - 1;
        } else {
            c = a + b;
            a = b;
            b = c;
        }
    }

    cr_assert( std::count_if(result.begin(), result.end(), [&](auto e) { return e==false; }) == 0);
}


Test(Test_Fibonacci, Increment_limit) {

    CutoffFibonacci cof;

    for(unsigned int i=0; i<500; i++) {
        ++cof;
    }

    cr_assert( cof() == std::numeric_limits<unsigned long int>::max() - 1 );
}
