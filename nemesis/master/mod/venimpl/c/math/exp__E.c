/*  -*- Mode: C;  -*-
 * File: exp__E.c
 * Author: James Hall (jch1003@cl.cam.ac.uk)
 * Copyright (C) University of Cambridge Computer Laboratory, 1994
 **~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ** PACKAGE: Nemesis C Library.
 **
 ** FUNCTION: exp__E(x,c)
 **           ASSUMPTION: c << x  SO THAT  fl(x+c)=x.
 **           (c is the correction term for x)
 **           exp__E RETURNS
 **
 **			 /  exp(x+c) - 1 - x ,  1E-19 < |x| < .3465736
 **       exp__E(x,c) = 	| 		     
 **			 \  0 ,  |x| < 1E-19.
 **
 **        DOUBLE PRECISION IEEE 53 bits.
 **        KERNEL FUNCTION OF EXP, EXPM1, POW FUNCTIONS
 **
 ** HISTORY:
 ** Created: Mon Jun 13 11:23:45 1994 (jch1003
 ** Last Edited: Mon Oct 10 12:27:21 1994 By James Hall
 **
    $Log: exp__E.c,v $
    Revision 1.2  1995/02/28 10:10:04  dme
    reinstate copylefts

 * Revision 1.2  1994/11/01  10:34:10  jch1003
 * Fn name changed to UNlibc_exp__E(), naming changes.
 *
 * Revision 1.1  1994/08/22  11:57:38  jch1003
 * Initial revision
 *)
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


/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.
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

/*
 * Method:
 *	1. Rational approximation. Let r=x+c.
 *	   Based on
 *                                   2 * sinh(r/2)     
 *                exp(r) - 1 =   ----------------------   ,
 *                               cosh(r/2) - sinh(r/2)
 *	   exp__E(r) is computed using
 *                   x*x            (x/2)*W - ( Q - ( 2*P  + x*P ) )
 *                   --- + (c + x*[---------------------------------- + c ])
 *                    2                          1 - W
 * 	   where  P := p1*x^2 + p2*x^4,
 *	          Q := q1*x^2 + q2*x^4 (for 56 bits precision, add q3*x^6)
 *	          W := x/2-(Q-x*P),
 *
 *	   (See the listing below for the values of p1,p2,q1,q2,q3. The poly-
 *	    nomials P and Q may be regarded as the approximations to sinh
 *	    and cosh :
 *		sinh(r/2) =  r/2 + r * P  ,  cosh(r/2) =  1 + Q . )
 *
 *         The coefficients were obtained by a special Remez algorithm.
 *
 * Approximation error:
 *
 *   |	exp(x) - 1			   |        2**(-57),  (IEEE double)
 *   | ------------  -  (exp__E(x,0)+x)/x  |  <= 
 *   |	     x			           |	    2**(-69).  (VAX D)
 *
 * Constants:
 * The hexadecimal values are the intended ones for the following constants.
 * The decimal values may be used, provided that the compiler will convert
 * from decimal to binary accurately enough to produce the hexadecimal values
 * shown.
 */

#include <math.h>

static const double p1 = 1.3887401997267371720E-2;
static const double p2 = 3.3044019718331897649E-5;
static const double q1 = 1.1110813732786649355E-1;
static const double q2 = 9.9176615021572857300E-4;


double 
exp__E(double x, double c)

{
	static const double zero=0.0, one=1.0, half=1.0/2.0, small=1.0E-19;
	double z,p,q,xp,xh,w;
	if(copysign(x,one)>small) {
           z = x*x  ;
	   p = z*( p1 +z* p2 );
           q = z*( q1 +z*  q2 );
           xp= x*p     ; 
	   xh= x*half  ;
           w = xh-(q-xp)  ;
	   p = p+p;
	   c += x*((xh*w-(q-(p+xp)))/(one-w)+c);
	   return(z*half+c);
	}
	/* end of |x| > small */

	else {
	    if(x!=zero) 
	      one+small;	/* raise the inexact flag */
	    return(copysign(zero,x));
	}
}

/*
 * end exp_E.c
 */








