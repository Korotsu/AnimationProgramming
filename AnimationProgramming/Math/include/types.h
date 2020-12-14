#ifndef TYPES_H
#define TYPES_H

#include <cstdint>

namespace BE
{

using u8    = std::uint8_t;
using u16   = std::uint16_t;
using u32   = std::uint32_t;
using u64   = std::uint64_t;
using i8    = std::int8_t;
using i16   = std::int16_t;
using i32   = std::int32_t;
using i64   = std::int64_t;

using i32f  = std::int_fast32_t;
using u32f  = std::uint_fast32_t;

using f32   = float;
union f32u
{
    f32 f;
    int bits;
};

} // End of namespace BE

#endif