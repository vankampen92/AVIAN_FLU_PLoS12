/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                           */
/*                  FLOWERING PLANTS - POLINATORS COUPLED MODEL              */
/*	                                                                     */
/*                          (Time dependent phenology)                       */
/*                                                                           */
/*                            David Alonso, 2008 (c)                         */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <nr.h>
#include <nrutil.h>
#include <complex.h>
#include <time.h>
#include <assert.h>
#include <stat.h> 
#include <GSL_stat.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_sort.h>
#include <gsl/gsl_sort_vector.h>
#include <gsl/gsl_permutation.h>
#include <gsl/gsl_odeiv.h>
#if defined CPGPLOT_REPRESENTATION
/* 
 * This header file contains the function prototypes
 * of my hand-made cpgplot-based plotting procedures
 */
#include <cpgplot.h> 
#include <cpgplot_UTL.h>
#endif
