/*  -*- Mode: C;  -*-
 * File: strncat.c
 * Author: James Hall (jch1003@cl.cam.ac.uk)
 * Copyright (C) University of Cambridge Computer Laboratory, 1994
 **~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ** PACKAGE: Nemesis C Library
 **
 ** FUNCTION: Concatenate at most n chars of s2 to s1, terminate with '\0'
 **             - return s1
 **
 ** HISTORY:
 ** Created: Fri Apr 22 16:53:56 1994 (jch1003)
 ** Last Edited: Tue Sep 13 10:26:03 1994 By James Hall
 **
    $Log: strncat.c,v $
    Revision 1.2  1995/02/28 10:02:45  dme
    reinstate copylefts

 * Revision 1.1  1995/02/02  11:58:05  dme
 * Initial revision
 *
 * Revision 1.2  1994/10/31  17:55:21  jch1003
 * Moved from ../strncat.c, naming changes.
 *
 * Revision 1.1  1994/08/22  11:32:30  jch1003
 * Initial revision
 *
 **~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

/* Copyright (C) 1992 Free Software Foundation, Inc.
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

#include <nemesis.h>
#include <string.h>
#include <memcopy.h>

/*
 * exports
 */

extern char *strncat(char *s1, const char *s2, size_t n);

extern char *
strncat(char *s1, const char *s2, size_t n)

{
  reg_char c;
  char *s = s1;

  /* Find the end of s1.  */

  do
    c = *s1++;
  while (c != '\0');

  /* Make s1 point before next character, so we can increment
     it while memory is read (wins on pipelined cpus).  */

  s1 -= 2;


  if (n >= 4)

    {
      size_t n4 = n >> 2;
      do {

	  c = *s2++;
	  *++s1 = c;
	  if (c == '\0')
	    return s;
	  c = *s2++;
	  *++s1 = c;
	  if (c == '\0')
	    return s;
	  c = *s2++;
	  *++s1 = c;
	  if (c == '\0')
	    return s;
	  c = *s2++;
	  *++s1 = c;
	  if (c == '\0')
	    return s;

	} while (--n4 > 0);

      n &= 3;
  
  }

  while (n > 0) {

      c = *s2++;
      *++s1 = c;
      if (c == '\0')
	return s;
      n--;

    }

  if (c != '\0')
    *++s1 = '\0';

  return s;
}

/*
 * end strncat.c
 */









