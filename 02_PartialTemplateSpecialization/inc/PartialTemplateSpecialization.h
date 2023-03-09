#pragma once

#include <iostream>
#include <cassert>

#define STATIC_CHECK(expr) { char unnamed[expr? 1 : 0]; }

namespace techniques
{

    namespace compile_time_assertions
    {
        // TODO: needs fixing
        template<
          class To,
          class From
        > To safe_reinterpret_cast(From from)
        {
            STATIC_CHECK(sizeof(From) <= sizeof(To));
            return reinterpret_cast<To>(from);
        };
    }
}