
#include "stdafx.h"
#include "Util.h"
#include "Distrib/include/TangoLSX_API.h"
#include <vector>

extern int g_LSID;


CTimer::CTimer( bool bStart )
  : m_nFrequency( 0 ), 
    m_nStartedCounterValue( 0 )
{
  if( bStart )
  {
    StartTimer();
  }
}

void CTimer::StartTimer()
{
  LARGE_INTEGER val;
  if( !m_nFrequency && ::QueryPerformanceFrequency( &val ) )
  {
    m_nFrequency = val.QuadPart;
  }

  if( m_nFrequency && ::QueryPerformanceCounter( &val ) )
  {
    m_nStartedCounterValue = val.QuadPart;
  }
}

__int64 CTimer::GetMicroSec() const
{
  if( m_nFrequency )
  {
    LARGE_INTEGER val;
    if( ::QueryPerformanceCounter( &val ) )
    {
      __int64 lCounterDiff = val.QuadPart - m_nStartedCounterValue;
      return (lCounterDiff * 1000000 / m_nFrequency);
    }
  }
  return 0;
}



void PrintVersionInfo()
{
  std::cout << "VERSION:\n";

  auto szFilename = _T("Tango_DLL.dll");

  DWORD  dwHandle = 0;
  UINT   size     = 0;
  LPBYTE lpBuffer = nullptr;
  DWORD  verSize  = GetFileVersionInfoSize( szFilename, &dwHandle );

  if( verSize )
  {
    std::vector<TCHAR> verData( verSize );

    if( GetFileVersionInfo( szFilename, dwHandle, verSize, &verData[0] ) )
    {
      if( VerQueryValue( &verData[0], _T("\\"), reinterpret_cast<void**>(&lpBuffer), &size ) )
      {
        if( size )
        {
          VS_FIXEDFILEINFO* verInfo = reinterpret_cast<VS_FIXEDFILEINFO*>(lpBuffer);
          if( verInfo->dwSignature == 0xfeef04bd )
          {
            std::cout << "VersionInfo Tango_DLL.dll: " << 
            ((verInfo->dwFileVersionMS >> 16) & 0xffff) << "." << 
            ((verInfo->dwFileVersionMS >>  0) & 0xffff) << "." << 
            ((verInfo->dwFileVersionLS >> 16) & 0xffff) << "." << 
            ((verInfo->dwFileVersionLS >>  0) & 0xffff) << "\n";
          }
        }
      }
    }
  }

  char buf[1024];
  CHECK_EQUAL(LSX_GetDLLVersionString(g_LSID, buf, _countof(buf)),0);
  std::cout << "LSX_GetDLLVersionString: " << buf << "\n";

//  LSX_GetVersionStr( g_LSID, buf, _countof( buf ) );
//  std::cout << "Tango Firmware: " << buf;
//  std::cout << "\n\n";

  CHECK_EQUAL(LSX_GetTangoVersion(g_LSID, buf, _countof(buf)),0); //informativer als GetVersionStr
  std::cout << "Tango Firmware: " << buf;
  std::cout << "\n\n";

  CHECK_EQUAL(LSX_GetStageSN(g_LSID, buf, _countof(buf)), 0);
  std::cout << "Stage SN: " << buf;
  std::cout << "\n\n";

}

void PrintDate()
{
  SYSTEMTIME time;
  GetLocalTime( &time );
  std::cout << "DATE: " << time.wDay << "." << time.wMonth << "." << time.wYear << "\n\n";
}

void PrintPreparations( const char* szInstructions )
{
  std::cout << "PREPARATION:\n" << szInstructions << "\n<ENTER>\n";
  getchar();
}

void PrintComment( const char* szComment )
{
  std::cout << "##### - " << szComment << std::endl;
}

