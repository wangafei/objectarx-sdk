#ifndef _ODDBIDOPS_INCLUDED_
#define _ODDBIDOPS_INCLUDED_

class OdDbStub;

TOOLKIT_EXPORT bool c5ObjIdIsLessThan(const OdDbStub * lhs, const OdDbStub * rhs);

TOOLKIT_EXPORT bool c5ObjIdIsGreaterThan(const OdDbStub * lhs, const OdDbStub * rhs);

TOOLKIT_EXPORT bool c5ObjIdLessThanOrEqual(const OdDbStub * lhs, const OdDbStub * rhs);

TOOLKIT_EXPORT bool c5ObjIdGreaterThanOrEqual(const OdDbStub * lhs, const OdDbStub * rhs);

TOOLKIT_EXPORT bool c5ObjIdIsEqualTo(const OdDbStub * lhs, const OdDbStub * rhs);

TOOLKIT_EXPORT bool c4ObjIdIsLessThan(OdULongPtr lhs, OdULongPtr rhs);

TOOLKIT_EXPORT bool c4ObjIdIsGreaterThan(OdULongPtr lhs, OdULongPtr rhs);

TOOLKIT_EXPORT bool c4ObjIdLessThanOrEqual(OdULongPtr lhs, OdULongPtr rhs);

TOOLKIT_EXPORT bool c4ObjIdGreaterThanOrEqual(OdULongPtr lhs, OdULongPtr rhs);

TOOLKIT_EXPORT bool c4ObjIdIsEqualTo(OdULongPtr lhs, OdULongPtr rhs);

TOOLKIT_EXPORT bool c4ObjIdNotEqualTo(OdULongPtr lhs, OdULongPtr rhs);

#endif