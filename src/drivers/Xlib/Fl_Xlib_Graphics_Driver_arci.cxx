//
// Arc (integer) drawing functions for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-2018 by Bill Spitzak and others.
//
// This library is free software. Distribution and use rights are outlined in
// the file "COPYING" which should have been included with this file.  If this
// file is missing or damaged, see the license at:
//
//     https://www.fltk.org/COPYING.php
//
// Please see the following page on how to report bugs and issues:
//
//     https://www.fltk.org/bugs.php
//

#include <config.h>
#include "Fl_Xlib_Graphics_Driver.H"
#include <FL/fl_draw.H>
#include <FL/platform.H>

/**
  \file Fl_Xlib_Graphics_Driver_arci.cxx
  \brief Utility functions for drawing circles using integers
*/

void Fl_Xlib_Graphics_Driver::arc_unscaled(float x,float y,float w,float h,double a1,double a2) {
  if (w <= 0 || h <= 0) return;
  XDrawArc(fl_display, fl_window, gc_, int(x+offset_x_*scale()), int(y+offset_y_*scale()), int(w-1), int(h-1), int(a1*64),int((a2-a1)*64));
}

void Fl_Xlib_Graphics_Driver::pie_unscaled(float x,float y,float w,float h,double a1,double a2) {
  if (w <= 0 || h <= 0) return;
  x += offset_x_*scale();
  y += offset_y_*scale();
  XDrawArc(fl_display, fl_window, gc_, x,y,w-1,h-1, int(a1*64),int((a2-a1)*64));
  XFillArc(fl_display, fl_window, gc_, x,y,w-1,h-1, int(a1*64),int((a2-a1)*64));
}
