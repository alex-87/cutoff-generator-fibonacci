/**
 * Copyright (C) 2020 Alexis LE GOADEC.
 * 
 * This file is part of the CutoffFifonacci project which is licensed under
 * the European Union Public License v1.2.
 * 
 * If a copy of the EUPL v1.2 was not distributed with this software,
 * you can obtain one at : https://joinup.ec.europa.eu/collection/eupl/eupl-text-eupl-12
 */

#ifndef _CUTOFF_FIBONACCI_HPP_
#define _CUTOFF_FIBONACCI_HPP_

#include <gecode/search.hh>
#include <limits>


/**
 * Cutoff generator following the Fibonnaci sequence.
 * To be used within the Gecode::Search::RBS meta-engine.
 */
class CutoffFibonacci : public Gecode::Search::Cutoff {

public:

    /**
     * Constructor
     */
    CutoffFibonacci() :
    Gecode::Search::Cutoff(), a_(0), b_(1), c_(1) { }


public:

    /**
     * To get the current number from sequence.
     * 
     * @return the current number
     */
    unsigned long int operator ()(void) const
    { return c_; }

    /**
     * To increment the cutoff in accordance with
     * the Fibonacci sequence and the current state.
     * 
     * @return the newly generated number
     */
    unsigned long int operator ++(void) {
        if(a_ + b_ < c_ ) {
            c_ = std::numeric_limits<decltype(c_)>::max() - 1;
            return c_;
        }
        c_ = a_ + b_;
        a_ = b_;
        b_ = c_;
        return c_;
    }


protected:

    unsigned long int
    a_, b_, c_;

};


#endif // _CUTOFF_FIBONACCI_HPP_
