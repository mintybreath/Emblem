/**
* \file ExpressionBase.h

* Copyright (c) 2016, Kevin Knifsend, https://nullbreak.wordpress.com/

* Permission to use, copy, modify, and/or distribute this software for any
* purpose with or without fee is hereby granted, provided that the above
* copyright notice and this permission notice appear in all copies.

* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
* ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
#pragma once

#include <string>
#include <cmath>

template <class T>
class UnaryOperator
{
    typedef T(Operator)(const T&);
public:
    UnaryOperator(
        Operator op,
        const std::string& rOpenString,
        const std::string& rCloseString)
        : mOperator(op), mOpenString(rOpenString),
          mCloseString(rCloseString)
    {
    }

    T operator()(const T& rValue) const
    {
        return mOperator(rValue);
    }

    static UnaryOperator Sin;
    static UnaryOperator Cos;
    static UnaryOperator Tan;
    static UnaryOperator Identity;

private:
    Operator mOperator;
    std::string mOpenString;
    std::string mCloseString;
};

/** Unary Operators */
template <class T>
T Sin(const T& rA) { return sin(rA); }

template <class T>
T Cos(const T& rA) { return cos(rA); }

template <class T>
T Tan(const T& rA) { return tan(rA); }

template <class T>
T Identity(const T& rA) { return rA; }

template <class T>
UnaryOperator<T> UnaryOperator<T>::Sin(Sin<T>, "sin(", ")");

template <class T>
UnaryOperator<T> UnaryOperator<T>::Cos(Cos<T>, "cos(", ")");

template <class T>
UnaryOperator<T> UnaryOperator<T>::Tan(Tan<T>, "tan(", ")");

template <class T>
UnaryOperator<T> UnaryOperator<T>::Identity(Identity<T>, "", "");