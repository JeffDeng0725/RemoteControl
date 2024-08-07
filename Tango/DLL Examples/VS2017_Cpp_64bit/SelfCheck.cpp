

#include "stdafx.h"
#include "SelfCheck.h"
#include <iostream>


void TestTimer()
{
  PRINTFUNC
 
  CTimer t1;
  ::Sleep( 250 );
  CHECK_CLOSE( 250000, t1.GetMicroSec(), 10.0 ); // Timer must be within 10% (Sleep itself is very inaccurate)

  CTimer t2( false );
  ::Sleep( 100 );
  t2.StartTimer();
  ::Sleep( 350 );
  CHECK_CLOSE( 350000, t2.GetMicroSec(), 10.0 ); // Timer must be within 10% (Sleep itself is very inaccurate)
}