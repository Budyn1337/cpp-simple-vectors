/*
* @author: Michal Medynski
* @contact: mail: misiek1566@gmail.com
*/
#include "vector1.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"
#include "color.hpp"

//<vec1 typedefs>

template<typename T> using Vec1 = Vector<T, 1>;

using Vec1Byte = Vector<unsigned char, 1>;
using Vec1US = Vector<unsigned short, 1>;
using Vec1UI = Vector<unsigned int, 1>;
using Vec1UL = Vector<unsigned long, 1>;

using Vec1C = Vector<char, 1>;
using Vec1S = Vector<short, 1>;
using Vec1I = Vector<int, 1>;
using Vec1L = Vector<long, 1>;

using Vec1F = Vector<float, 1>;
using Vec1D = Vector<double, 1>;
using Vec1LD = Vector<long double, 1>;

using Vec1B = Vector<bool, 1>;

//</vec1 typedefs>
//<vec2 typedefs>

template<typename T> using Vec2 = Vector<T, 2>;

using Vec2Byte = Vector<unsigned char, 2>;
using Vec2US = Vector<unsigned short, 2>;
using Vec2UI = Vector<unsigned int, 2>;
using Vec2UL = Vector<unsigned long, 2>;

using Vec2C = Vector<char, 2>;
using Vec2S = Vector<short, 2>;
using Vec2I = Vector<int, 2>;
using Vec2L = Vector<long, 2>;

using Vec2F = Vector<float, 2>;
using Vec2D = Vector<double, 2>;
using Vec2LD = Vector<long double, 2>;

using Vec2B = Vector<bool, 2>;

//</vec2 typedefs>
//<vec3 typedefs>

template<typename T> using Vec3 = Vector<T, 3>;

using Vec3Byte = Vector<unsigned char, 3>;
using Vec3US = Vector<unsigned short, 3>;
using Vec3UI = Vector<unsigned int, 3>;
using Vec3UL = Vector<unsigned long, 3>;

using Vec3C = Vector<char, 3>;
using Vec3S = Vector<short, 3>;
using Vec3I = Vector<int, 3>;
using Vec3L = Vector<long, 3>;

using Vec3F = Vector<float, 3>;
using Vec3D = Vector<double, 3>;
using Vec3LD = Vector<long double, 3>;

using Vec3B = Vector<bool, 3>;

//</vec3 typedefs>
//<vec4 typedefs>

template<typename T> using Vec4 = Vector<T, 4>;

using Vec4Byte = Vector<unsigned char, 4>;
using Vec4US = Vector<unsigned short, 4>;
using Vec4UI = Vector<unsigned int, 4>;
using Vec4UL = Vector<unsigned long, 4>;

using Vec4C = Vector<char, 4>;
using Vec4S = Vector<short, 4>;
using Vec4I = Vector<int, 4>;
using Vec4L = Vector<long, 4>;

using Vec4F = Vector<float, 4>;
using Vec4D = Vector<double, 4>;
using Vec4LD = Vector<long double, 4>;

using Vec4B = Vector<bool, 4>;

//</vec4 typedefs>
