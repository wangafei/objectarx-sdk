/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#define     ASITRYSET   IncreaseGlobalAccount(0); try
#define     ASICATCHALL catch (int ASITRYCODE)
#define     ASITRYDEL   DecreaseGlobalAccount(0);
#define     ASITHROW(x) if( CheckGlobalAccount(0) ) throw((int)(x))
#pragma pack (push, 8)

GCCORE_PORT int IncreaseGlobalAccount(int ind);
GCCORE_PORT int DecreaseGlobalAccount(int ind);
GCCORE_PORT int CheckGlobalAccount(int ind);
#pragma pack (pop)