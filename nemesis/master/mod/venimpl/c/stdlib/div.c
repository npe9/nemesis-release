/*  -*- Mode: C;  -*-
 * File: div.c
 * Author: James Hall (jch1003@cl.cam.ac.uk)
 * Copyright (C) University of Cambridge Computer Laboratory, 1994
 **~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ** PACKAGE: Nemesis C library.
 **
 ** FUNCTION: Return the `div_t' representation of NUMER over DENOM.
 **           Return the `ldiv_t' representation of NUMER over DENOM.  
 **
 ** HISTORY:
 ** Created: Wed May 18 12:48:33 1994 (jch1003)
 ** Last Edited: Tue Sep 13 11:39:14 1994 By James Hall
 **
    $Log: div.c,v $
    Revision 1.2  1995/02/28 10:10:40  dme
    reinstate copylefts

 * Revision 1.2  1994/10/31  15:36:45  jch1003
 * Moved from ../div.c, naming changes.
 *
 * Revision 1.1  1994/08/22  11:15:06  jch1003
 * Initial revision
 *
 **~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

/* Copyright (C) 1991, 1992 Free Software Foundation, Inc.
This file is part of the GNU C Library.

The GNU C Library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public License as
published by the Free Software Foundation; either version 2 of the
License, or (at your option) any later version.

The GNU C Library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with the GNU C Library; see the file COPYING.LIB.  If
not, write to the Free Software Foundation, Inc., 675 Mass Ave,
Cambridge, MA 02139, USA.  */

/*
 * Copyright (c) 1990 Regents of the University of California.
 * All rights reserved.
 *
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * 'The above copyright notice' refers to the standard Gnu copyright.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <nemesis.h>
#include <stdlib.h>
#include <limits.h>

/* The standard leaves result undefined if numer = 0 or denom = 0
   we return values of quot = rem = 0 if numer = 0, and
   quot = rem = INT_MAX (or LONG_MAX) if denom = 0. */

extern div_t
div(int numer, int denom)
{
  div_t result;

  if(numer == 0) {
    result.quot = result.rem = 0;
    return result;
  }

  if(denom == 0) {
    result.quot = result.rem = INT_MAX;
    return result;
  }

  result.quot = numer / denom;
  result.rem = numer % denom;

  /* The ANSI standard says that |QUOT| <= |NUMER / DENOM|, where
     NUMER / DENOM is to be computed in infinite precision.  In
     other words, we should always truncate the quotient towards
     zero, never -infinity.  Machine division and remainer may
     work either way when one or both of NUMER or DENOM is
     negative.  If only one is negative and QUOT has been
     truncated towards -infinity, REM will have the same sign as
     DENOM and the opposite sign of NUMER; if both are negative
     and QUOT has been truncated towards -infinity, REM will be
     positive (will have the opposite sign of NUMER).  These are
     considered `wrong'.  If both are NUM and DENOM are positive,
     RESULT will always be positive.  This all boils down to: if
     NUMER >= 0, but REM < 0, we got the wrong answer.  In that
     case, to get the right answer, add 1 to QUOT and subtract
     DENOM from REM.  */

  if (numer >= 0 && result.rem < 0)
    {
      ++result.quot;
      result.rem -= denom;
    }

  return result;
}


extern ldiv_t
ldiv(long int numer, long int denom)
{
  ldiv_t result;

  if(numer == 0) {
    result.quot = result.rem = 0;
    return result;
  }

  if(denom == 0) {
    result.quot = result.rem = LONG_MAX;
    return result;
  }

  result.quot = numer / denom;
  result.rem = numer % denom;

  if (numer >= 0 && result.rem < 0)
    {
      ++result.quot;
      result.rem -= denom;
    }

  return result;
}

/*
 * end div.
 */
