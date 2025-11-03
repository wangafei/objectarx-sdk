/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBDATE_H
#define GD_DBDATE_H

#include <ctime>                
#include "gcdb.h"
#include "gcadstrc.h"           
#include "GcDbCore2dDefs.h"     
#include "gcdbport.h"           

#pragma pack(push, 8)

class GcDbDwgFiler;
class GcString;

#if defined(_WIN32) || defined(_WIN64)
typedef struct _SYSTEMTIME SYSTEMTIME;
#elif defined(__linux__)
typedef struct _SYSTEMTIME {
  unsigned short wYear;
  unsigned short wMonth;
  unsigned short wDayOfWeek;
  unsigned short wDay;
  unsigned short wHour;
  unsigned short wMinute;
  unsigned short wSecond;
  unsigned short wMilliseconds;
}SYSTEMTIME;
#else //TODO
#endif

class GCDB_PORT GcDbDate
{
public:
  enum InitialValue {
    kInitZero = 1,
    kInitLocalTime = 2,
    kInitUniversalTime = 3
  };
  GcDbDate();
  GcDbDate(InitialValue i);
  GcDbDate(const GcDbDate&);
  virtual ~GcDbDate();

  const GcDbDate& operator= (const GcDbDate&);

  void  getDate(short& month, short& day, short& year) const;
  GcString getLocalDisplayString() const;
  void  setDate(int month, int day, int year);
  short month() const;
  short day() const;
  short year() const;
  void  setMonth(int);
  void  setDay(int);
  void  setYear(int);

  void  getTime(SYSTEMTIME &st) const;
  void  getTime(std::tm &st) const;
  void  setTime(const std::tm &st);
  void  getTime(time_t &st) const;
  void  setTime(const SYSTEMTIME &st);

  void  getTime(short& hour, short& min, short& sec, short& msec) const;
  void  setTime(int hour, int min, int sec, int msec);

  int  getApproximateTime() const;
  void setApproximateTime(int time);

  short hour() const;
  short minute() const;
  short second() const;
  short millisecond() const;
  void  setHour(int);
  void  setMinute(int);
  void  setSecond(int);
  void  setMillisecond(int);
  void  setToZero();

  void  getLocalTime();
  void  getUniversalTime();

  void localToUniversal();
  void universalToLocal();

  Gsoft::Int32   julianDay() const;
  Gsoft::Int32   msecsPastMidnight() const;
  void   setJulianDay(Gsoft::Int32 julianDay);
  void   setMsecsPastMidnight(Gsoft::Int32 msec);
  void   setJulianDate(Gsoft::Int32 julianDay, Gsoft::Int32 msec);
  double julianFraction() const;
  void   setJulianFraction(double);

  bool operator== (const GcDbDate&) const;
  bool operator > (const GcDbDate&) const;
  bool operator >= (const GcDbDate&) const;
  bool operator < (const GcDbDate&) const;
  bool operator <= (const GcDbDate&) const;

  const GcDbDate operator + (const GcDbDate &date) const;
  const GcDbDate operator - (const GcDbDate &date) const;
  const GcDbDate & operator += (const GcDbDate &date);
  const GcDbDate & operator -= (const GcDbDate &date);

  const GcDbDate& add(const GcDbDate &date);
  const GcDbDate& subtract(const GcDbDate &date);

  Gcad::ErrorStatus dwgOut(GcDbDwgFiler *outFiler) const;
  Gcad::ErrorStatus dwgIn(GcDbDwgFiler *inFiler);

private:
  friend class GcDbImpDate;
  class GcDbImpDate *mpImpDate;
};

inline const GcDbDate GcDbDate::operator + (const GcDbDate & d) const
{
  return GcDbDate(*this) += d;
}

inline const GcDbDate GcDbDate::operator - (const GcDbDate & d) const
{
  return GcDbDate(*this) -= d;
}

inline bool GcDbDate::operator < (const GcDbDate & d) const
{
  return !operator >= (d);
}

inline bool GcDbDate::operator <= (const GcDbDate & d) const
{
  return !operator > (d);
}

inline const GcDbDate & GcDbDate::add(const GcDbDate &date)
{
  return operator += (date);
}

inline const GcDbDate & GcDbDate::subtract(const GcDbDate &date)
{
  return operator -= (date);
}

#pragma pack(pop)

#endif