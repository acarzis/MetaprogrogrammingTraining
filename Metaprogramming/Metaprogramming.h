#pragma once

#include <iostream>

// analog to pow() at compile time
template<int X, int Y> struct power {
    constexpr static const long long value =
        X * power<X, Y - 1>::value;
};

// terminating specialization
template<int X> struct power<X, 0> {
    constexpr static const long long value = 1;
};



// a tuple definition
//    LIMITATION: the below implementation does not support strings. the original code, as taken from the link below, does (as well as index support)  
//                reference:  https://www.codeproject.com/Articles/5297814/Metaprogramming-in-Cplusplus-A-Gentle-Introduction - author:  honey the codewitch  
// 
// the following takes zero or
// more arguments
template <
    // declare a template parameter
    // pack:
    typename... Types>
struct tuple
{
    // our base tuple has no fields and is
    // therefore empty
};



// Declare a specialization for the tuple that
// takes at least one argument. Because this
// specialization exists, it will be chosen
// by the C++ compiler instead of the empty
// tuple struct template because it's more
// specific. The compiler will only fall
// back to the empty definition if there
// are no arguments, since below will
// only match one or more of them:
template <
    // this "peels" the first argument
    // from the parameter pack for
    // processing here:
    typename Type,
    // declare a template parameter
    // pack:
    typename... Types>
struct tuple<Type, Types...>
{
    // our current tuple value
    Type value;
    // here we instantiate a new tuple
    // with one fewer argument - the first
    // type in the list that was passed to
    // us is gone from Types... - it was
    // peeled off into Type.
    tuple<Types...> next;
    // we expand the parameter pack into
    // arguments to our ctor. Note that
    // we passed in Type as the first
    // one. This is because Types...
    // doesn't contain it anymore
    // since it was peeled off
    constexpr inline tuple(
        const Type& value,
        const Types &...next)
        : value(value), next(next...)
    {
    }
};

