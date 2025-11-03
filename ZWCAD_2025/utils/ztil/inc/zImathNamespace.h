
#ifndef Z_IMATHNAMESPACE_H
#define Z_IMATHNAMESPACE_H

#include "zImathConfig.h"

#ifndef IMATH_NAMESPACE
#    define IMATH_NAMESPACE Imath
#endif

#ifndef IMATH_INTERNAL_NAMESPACE
#    define IMATH_INTERNAL_NAMESPACE IMATH_NAMESPACE
#endif

#ifdef __cplusplus

namespace IMATH_INTERNAL_NAMESPACE
{}
namespace IMATH_NAMESPACE
{
using namespace IMATH_INTERNAL_NAMESPACE;
}

#define IMATH_INTERNAL_NAMESPACE_HEADER_ENTER                                                      \
    namespace IMATH_INTERNAL_NAMESPACE                                                             \
    {
#define IMATH_INTERNAL_NAMESPACE_HEADER_EXIT }

#define IMATH_INTERNAL_NAMESPACE_SOURCE_ENTER                                                      \
    namespace IMATH_INTERNAL_NAMESPACE                                                             \
    {
#define IMATH_INTERNAL_NAMESPACE_SOURCE_EXIT }

#endif

#endif
