/************************************************************************\
**                                                                      **
**               OS/2(r) Physical Device Driver Libraries               **
**                         for Watcom C/C++ 10                          **
**                                                                      **
**  COPYRIGHT:                                                          **
**                                                                      **
**    (C) Copyright Advanced Gravis Computer Technology Ltd 1994.       **
**        All Rights Reserved.                                          **
**                                                                      **
**  DISCLAIMER OF WARRANTIES:                                           **
**                                                                      **
**    The following [enclosed] code is provided to you "AS IS",         **
**    without warranty of any kind.  You have a royalty-free right to   **
**    use, modify, reproduce and distribute the following code (and/or  **
**    any modified version) provided that you agree that Advanced       **
**    Gravis has no warranty obligations and shall not be liable for    **
**    any damages arising out of your use of this code, even if they    **
**    have been advised of the possibility of such damages.  This       **
**    Copyright statement and Disclaimer of Warranties may not be       **
**    removed.                                                          **
**                                                                      **
\************************************************************************/


// IOCtl.c
//
// Process device specific I/O commands
//
// History:
//
// Sep 30, 94  David Bollo    Initial version



#include <devdebug.h>
#include <devtype.h>
#include <devrp.h>



// Constant debugging strings (only defined when DEBUG is defined)

#if defined(DEBUG)

static const char* MSG_IOCTL              = "Watcom Sample Device Driver IOCtl";
static const char* MSG_CATEGORY           = " Category = ";
static const char* MSG_FUNCTION           = " Function = ";

#else

#define            MSG_IOCTL              0
#define            MSG_CATEGORY           0
#define            MSG_FUNCTION           0

#endif // DEBUG



// Dispatch IOCtl requests received from the Strategy routine

WORD16 StratIOCtl(RP FAR* _rp)
  {
  RPIOCtl FAR* rp = (RPIOCtl FAR*)_rp;

  // Print a message to the debug terminal saying which IOCtl we just
  // received.  Of course, if DEBUG is not defined, then the following
  // instructions will generate _NO_ code!
  cdbg << SKELETON;
  cdbg << MSG_IOCTL << hex << setw(4);
  cdbg << MSG_CATEGORY << rp->Category;
  cdbg << MSG_FUNCTION << rp->Function;
  cdbg << setw() << setb() << endl;

  return RPDONE | RPERR_COMMAND;
  }
