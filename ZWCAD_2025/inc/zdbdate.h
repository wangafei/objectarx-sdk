

#ifndef ZD_DBDATE_H
#define ZD_DBDATE_H

#include <ctime>
#include "zacdb.h"
#include "zacadstrc.h"           
#include "zAcDbCore2dDefs.h"		
#include "zacdbport.h"		

#pragma pack(push, 8)

class ZcDbDwgFiler;
class ZcString;

typedef struct _SYSTEMTIME SYSTEMTIME;

class ZCDBCORE2D_PORT ZcDbDate
{
public:
    enum InitialValue {
        kInitZero          = 1,
        kInitLocalTime     = 2,
        kInitUniversalTime = 3
    };
    ZcDbDate();
    ZcDbDate(InitialValue i);
    ZcDbDate(const ZcDbDate&);
    virtual ~ZcDbDate();

    const ZcDbDate& operator= (const ZcDbDate&);

    void  getDate (short& month, short& day, short& year) const;
	ZcString getLocalDisplayString() const;		
	void  setDate (int month, int day, int year); 
    short month   () const;
    short day     () const;
    short year    () const;
	void  setMonth(int);
	void  setDay  (int);
    void  setYear (int);
	void  getTime (SYSTEMTIME &st) const;		
    void  getTime (std::tm &st) const;	
	void  setTime (const std::tm &st);	
	void  getTime (time_t &st) const;	
	void  setTime (const SYSTEMTIME &st);		
    void  getTime  (short& hour, short& min, short& sec, short& msec) const;
    void  setTime  (int hour, int min, int sec, int msec);	
	
	int getApproximateTime () const;
	void setApproximateTime (int time);
	
    short hour     () const;
    short minute   () const;
    short second   () const;
    short millisecond() const;
	void  setHour  (int);
	void  setMinute(int);
	void  setSecond(int);
    void  setMillisecond(int);
    void  setToZero();

    void  getLocalTime();
    void  getUniversalTime();

    void localToUniversal();
    void universalToLocal();

    ZSoft::Int32   julianDay           () const;
    ZSoft::Int32   msecsPastMidnight   () const;
    void   setJulianDay        (ZSoft::Int32 julianDay);
    void   setMsecsPastMidnight(ZSoft::Int32 msec);
    void   setJulianDate       (ZSoft::Int32 julianDay, ZSoft::Int32 msec);
    double julianFraction      () const;
    void   setJulianFraction   (double);

    bool operator== (const ZcDbDate&) const;
    bool operator > (const ZcDbDate&) const;
    bool operator >= (const ZcDbDate&) const;
    bool operator < (const ZcDbDate&) const;
    bool operator <= (const ZcDbDate&) const;

    const ZcDbDate operator + (const ZcDbDate &date) const;
    const ZcDbDate operator - (const ZcDbDate &date) const;
    const ZcDbDate & operator += (const ZcDbDate &date);
    const ZcDbDate & operator -= (const ZcDbDate &date);

    const ZcDbDate& add      (const ZcDbDate &date);
    const ZcDbDate& subtract (const ZcDbDate &date);

    Zcad::ErrorStatus dwgOut(ZcDbDwgFiler *outFiler) const;
    Zcad::ErrorStatus dwgIn (ZcDbDwgFiler *inFiler);

private:
    friend class ZcDbImpDate;
    class ZcDbImpDate *mpImpDate;
};

inline const ZcDbDate ZcDbDate::operator + (const ZcDbDate & d) const
{
    return ZcDbDate(*this) += d;
}

inline const ZcDbDate ZcDbDate::operator - (const ZcDbDate & d) const
{
    return ZcDbDate(*this) -= d;
}

inline bool ZcDbDate::operator < (const ZcDbDate & d) const
{
    return ! operator >= (d);
}

inline bool ZcDbDate::operator <= (const ZcDbDate & d) const
{
    return ! operator > (d);
}

inline const ZcDbDate & ZcDbDate::add(const ZcDbDate &date)
{
    return operator += (date);
}

inline const ZcDbDate & ZcDbDate::subtract(const ZcDbDate &date)
{
    return operator -= (date);
}

#pragma pack(pop)

#endif

