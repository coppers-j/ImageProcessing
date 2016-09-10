//
// main.h
// ImageProcessing
//
//  Created by James Copperthwaite on 08/09/2016.
//  Copyright © 2016 James Copperthwaite. All rights reserved.
//
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


#ifndef _MAIN_H_
#define _MAIN_H_

// WINDOWS

struct input{
  int blur;
  int sharpen;
  char *fname;
};

#endif
