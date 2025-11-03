#pragma once
#include "stdafx.h"
#include "accmd.h"
#include "dbgrip.h"
#include "dbpl.h"

#define EOK_RETURN(es) { Acad::ErrorStatus status = es; if (status != Acad::eOk) return status; }

const double kPi = 3.141592653589793238462643383279502884197169399375105820974944592;	// PI
const double kHalfPi = kPi / 2;				// 1/2 PI
const double kTwoPi = kPi * 2;				// 2 PI

const double kRad0 = 0.0;					// Radian of the 0 degree
const double kRad1 = kPi / 180.0;			// Radian of the 1 degree
const double kRad45 = kPi / 4.0;			// Radian of the 45 degree
const double kRad90 = kPi / 2;				// Radian of the 90 degree
const double kRad135 = (kPi * 3.0) / 4.0;	// Radian of the 135 degree
const double kRad180 = kPi;					// Radian of the 180 degree
const double kRad225 = (kPi * 5.0) / 4.0;	// Radian of the 225 degree
const double kRad270 = kPi * 1.5;			// Radian of the 270 degree
const double kRad315 = (kPi * 7.0) / 4.0;	// Radian of the 315 degree
const double kRad360 = kPi * 2;				// Radian of the 360 degree

struct AcadColor
{
	// ------------------------------------------------------------------------------------------------------------------------
	// Summary:
	//   Common color values.
	// ------------------------------------------------------------------------------------------------------------------------
	enum Color
	{
		kByBlock = 0,	// byblock
		kRed = 1,	    // red
		kYellow = 2,	// yellow
		kGreen = 3,	    // green
		kCyan = 4,	    // cyan
		kBlue = 5,	    // blue
		kMagenta = 6,	// magenta
		kWhite = 7,	    // white
		kByLayer = 256	// bylayer
	};
};

// ------------------------------------------------------------------------------------------------------------------------
// Summary:
//   Adds an entity to the current space of the specified database and returns the entity ID.
// Parameters:
//   newEnt		- Pointer to the entity to add to the current space.
//   objId      - The entity ID returned after adding successfully.
//   db			- Pointer to the database object to add to.
// Returns:
//   If the addition is successful, Acad::eOk is returned; otherwise, Acad::ErrorStatus error enumeration is returned.
// ------------------------------------------------------------------------------------------------------------------------
Acad::ErrorStatus AddToCurrentSpace(AcDbEntity* newEnt, AcDbObjectId& objId, AcDbDatabase* pDb = NULL);

// ------------------------------------------------------------------------------------------------------------------------
// Summary:
//   Add an entity to the current space of the specified database, close the entity and return the entity ID.
// Parameters:
//   newEnt		- Pointer to the entity to add to the current space.
//   objId      - The entity ID returned after adding successfully.
//   db			- Pointer to the database object to add to.
// Returns:
//   If the addition is successful, Acad::eOk is returned; otherwise, Acad::ErrorStatus error enumeration is returned.
// ------------------------------------------------------------------------------------------------------------------------
Acad::ErrorStatus AddToCurrentSpaceAndClose(AcDbEntity* newEnt, AcDbObjectId& objId, AcDbDatabase* pDb = NULL);

// ------------------------------------------------------------------------------------------------------------------------
// Summary:
//   Add an entity to the current space of the specified database and close the entity.
// Parameters:
//   newEnt		- Pointer to the entity to add to the current space.
//   db			- Pointer to the database object to add to.
// Returns:
//   If the addition is successful, Acad::eOk is returned; otherwise, Acad::ErrorStatus error enumeration is returned.
// ------------------------------------------------------------------------------------------------------------------------
AFX_INLINE Acad::ErrorStatus AddToCurrentSpaceAndClose(AcDbEntity* newEnt, AcDbDatabase* pDb = NULL);

// ------------------------------------------------------------------------------------------------------------------------
// Summary:
//   Add entities to the model space of the specified database.
// Parameters:
//   newEnt		- Pointer to the entity to add to model space.
//   db			- Pointer to the database object to add to.
// Returns:
//   If the addition is successful, Acad::eOk is returned; otherwise, Acad::ErrorStatus error enumeration is returned.
// ------------------------------------------------------------------------------------------------------------------------
Acad::ErrorStatus AddToModelSpace(AcDbEntity* newEnt, AcDbObjectId& objId, AcDbDatabase* pDb = NULL);

// ------------------------------------------------------------------------------------------------------------------------
// Summary:
//   Add an entity to the model space of the specified database, close the entity and return the entity ID.
// Parameters:
//   newEnt		- Pointer to the entity to add to model space.
//   objId      - The entity ID returned after adding successfully.
//   db			- Pointer to the database object to add to.
// Returns:
//   If the addition is successful, Acad::eOk is returned; otherwise, Acad::ErrorStatus error enumeration is returned.
// ------------------------------------------------------------------------------------------------------------------------
Acad::ErrorStatus AddToModelSpaceAndClose(AcDbEntity* newEnt, AcDbObjectId& objId, AcDbDatabase* pDb = NULL);

// ------------------------------------------------------------------------------------------------------------------------
// Summary:
//   Add an entity to the model space of the specified database and close the entity.
// Parameters:
//   newEnt		- Pointer to the entity to add to model space.
//   db			- Pointer to the database object to add to.
// Returns:
//   If the addition is successful, Acad::eOk is returned; otherwise, Acad::ErrorStatus error enumeration is returned.
// ------------------------------------------------------------------------------------------------------------------------

AFX_INLINE Acad::ErrorStatus AddToCurrentSpaceAndClose(AcDbEntity* newEnt, AcDbDatabase* pDb/* = NULL*/)
{
	AcDbObjectId objId;

	return AddToCurrentSpaceAndClose(newEnt, objId, pDb);
}

// ------------------------------------------------------------------------------------------------------------------------
// Summary:
//   Gets the system variable of integer type.
// Parameters:
//   name    - The name of the system variable.
//   value   - The value of the system variable.
// Returns:
//   If the addition is successful, Acad::eOk is returned; otherwise, Acad::ErrorStatus error enumeration is returned.
// ------------------------------------------------------------------------------------------------------------------------
Acad::ErrorStatus GetSysVar(LPCTSTR name, int& value);