#include <cstdint> 
#include <compare>

#define let const auto
#define let_ static const constexpr auto


enum class BoolT : bool
{
    true_ = true, false_ = false
};

let tru = BoolT::true_;
let fals = BoolT::false_;

BoolT operator&&(BoolT x, BoolT y) { return static_cast<BoolT>((x == tru) && (y == tru)); }
decltype(auto) operator||(BoolT x, BoolT y) { return static_cast<BoolT>((x == tru) || (y == tru)); }
decltype(auto) operator<=>(BoolT x, BoolT y) { return ((x == tru) <=> (y == tru)); }


#define iff(cond) if(tru == (cond))
#define forr(x,y,z) for(x; tru == (y); z)
#define whilee(cond) while(tru == (cond))


enum class uint8T : uint8_t {};
using u8 = const uint8T;
using mutu8  = uint8T;


enum class int8T : int8_t {};
using i8 = const int8T;
using muti8  = int8T;


enum class uint16T : uint16_t {};
using u16 = const uint16T;
using mutu16  = uint16T;


enum class int16T : int16_t {};
using i16 = const int16T;
using muti16  = int16T;

enum class uint32T : uint32_t {};
using u32 = const uint32T;
using mutu32  = uint32T;


enum class int32T : int32_t {};
using i32 = const int32T;
using muti32  = int32T;

enum class uint64T : uint64_t {};
using u64 = const uint64T;
using mutu64  = uint64T;


enum class int64T : int64_t {};
using i64 = const int64T;
using muti64  = int64T;

#include <type_traits>

#define plus_op(type) \
decltype(auto) static operator+(type x, type y) \
{ \
    using T = decltype(x); \
    using U = std::underlying_type_t<T>; \
    std::remove_const_t<U> res; \
    __builtin_add_overflow(static_cast<U>(x), static_cast<U>(y), &res); \
    return static_cast<T>(res); \
}

plus_op(u8)
plus_op(i8)
plus_op(u16)
plus_op(i16)
plus_op(u32)
plus_op(i32)
plus_op(i64)
plus_op(u64)


#define minus_op(type) \
decltype(auto) static operator-(type x, type y) \
{ \
    using T = decltype(x); \
    using U = std::underlying_type_t<T>; \
    std::remove_const_t<U> res; \
    __builtin_sub_overflow(static_cast<U>(x), static_cast<U>(y), &res); \
    return static_cast<T>(res); \
}

minus_op(u8)
minus_op(i8)
minus_op(u16)
minus_op(i16)
minus_op(u32)
minus_op(i32)
minus_op(i64)
minus_op(u64)


#define mul_op(type) \
decltype(auto) static inline __attribute__((always_inline)) operator*(type x, type y) \
{ \
    using T = decltype(x); \
    using U = std::underlying_type_t<T>; \
    return static_cast<T>(static_cast<U>(x) * static_cast<U>(y)); \
}

mul_op(i8)
mul_op(u8)
mul_op(i16)
mul_op(u16)
mul_op(i32)
mul_op(u32)
mul_op(i64)
mul_op(u64)


// todo: div_op

#define eq_op(type) \
decltype(auto) static inline __attribute__((always_inline)) operator==(type x, type y) \
{ \
    using T = decltype(x); \
    using U = std::underlying_type_t<T>; \
    return static_cast<U>(x) == static_cast<U>(y) ? tru : fals; \
}


eq_op(i8)
eq_op(u8)
eq_op(i16)
eq_op(u16)
eq_op(i32)
eq_op(u32)
eq_op(i64)
eq_op(u64)

constexpr muti8 operator""_i8(const char* c, std::size_t size)
{
// todo exception werfen wenn out of range
   auto ret = static_cast<muti8>(0);
   for(std::size_t i = 0; i < size; i++)
   {
       ret = ret * static_cast<muti8>(10);
       ret = ret + static_cast<muti8>(c[i]- '0');
   }
   return ret;
}

// natürlich noch für die weiteren Datentypen....
// auch für double denkbar...

int main()
{
    let x = "23"_i8;
    auto y = "42"_i8 + x;
    iff(x == x)
      return 0;
    return static_cast<int>(y);
}
