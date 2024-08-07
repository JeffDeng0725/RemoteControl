
#pragma once

#include "Distrib/include/TangoLSX_API.h"


class CTimer
{
public:
  explicit CTimer( bool bStart = true );

  void    StartTimer();
  __int64 GetMicroSec() const;
  
private:
  __int64 m_nFrequency;
  __int64 m_nStartedCounterValue;
};

extern unsigned g_uTotal;
extern unsigned g_uFailed;


// Helper Macros
#define PRINTFUNC         {std::cout << "TESTFUNCTION:\n" << __FUNCTION__ << "\n" << std::endl;}

#define CALL_TESTFUNC(a)      {a(); std::cout << "\n";}
#define REQUIRE_TESTFUNC(a)   {unsigned uFailed = g_uFailed; a(); std::cout << "\n"; if( uFailed != g_uFailed ){ std::cout << "FATAL - " << __FILE__ << "(" << __LINE__ << "): " << #a << std::endl; std::abort(); }}

#define CHECK(a)              {++g_uTotal; std::cout << ((a) ? "OK    - " : (++g_uFailed, "ERROR - ")) << __FILE__ << "(" << __LINE__ << "): " << #a << std::endl;}
#define CHECK_EQUAL(a,b)      {++g_uTotal; auto pa = a; auto pb = b; std::cout << ((pa == pb) ? "OK    - " : (++g_uFailed, "ERROR - ")) << __FILE__ << "(" << __LINE__ << "): " << #a << " == " << #b << " [" << pa << " == " << pb << "]" << std::endl;}
#define CHECK_LT(a,b)         {++g_uTotal; auto pa = a; auto pb = b; std::cout << ((pa < pb)  ? "OK    - " : (++g_uFailed, "ERROR - ")) << __FILE__ << "(" << __LINE__ << "): " << #a << " < " << #b << " [" << pa << " < " << pb << "]" << std::endl;}
#define CHECK_LTE(a,b)        {++g_uTotal; auto pa = a; auto pb = b; std::cout << ((pa <= pb) ? "OK    - " : (++g_uFailed, "ERROR - ")) << __FILE__ << "(" << __LINE__ << "): " << #a << " <= " << #b << " [" << pa << " <= " << pb << "]" << std::endl;}
#define CHECK_GT(a,b)         {++g_uTotal; auto pa = a; auto pb = b; std::cout << ((pa > pb)  ? "OK    - " : (++g_uFailed, "ERROR - ")) << __FILE__ << "(" << __LINE__ << "): " << #a << " > " << #b << " [" << pa << " > " << pb << "]" << std::endl;}
#define CHECK_GTE(a,b)        {++g_uTotal; auto pa = a; auto pb = b; std::cout << ((pa >= pb) ? "OK    - " : (++g_uFailed, "ERROR - ")) << __FILE__ << "(" << __LINE__ << "): " << #a << " >= " << #b << " [" << pa << " >= " << pb << "]" << std::endl;}
#define CHECK_NE(a,b)         {++g_uTotal; auto pa = a; auto pb = b; std::cout << ((pa != pb) ? "OK    - " : (++g_uFailed, "ERROR - ")) << __FILE__ << "(" << __LINE__ << "): " << #a << " != " << #b << " [" << pa << " != " << pb << "]" << std::endl;}
#define CHECK_CLOSE(a,b,dev)  {++g_uTotal; auto pa = a; auto pb = b; auto pdev = dev; std::cout << ((std::abs(pa-pb) <= (a*dev/100.0)) ? "OK    - " : (++g_uFailed, "ERROR - ")) << __FILE__ << "(" << __LINE__ << "): " << #a << " ~ " << #b << " [" << pa << " ~ " << pb << ", " << dev << "%]" << std::endl;}

#define REQUIRE(a)            {++g_uTotal; bool bOk = (a); std::cout << (bOk ? "OK    - " : (++g_uFailed, "FATAL - ")) << __FILE__ << "(" << __LINE__ << "): " << #a << std::endl; if( !(bOk) ) std::abort();}


void PrintVersionInfo();
void PrintDate();
void PrintPreparations( const char* szInstructions );
void PrintComment( const char* szComment );