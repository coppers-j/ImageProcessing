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
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>


#ifndef _MAIN_H_
#define _MAIN_H_

// bmp
const unsigned char HEADER_s[] = {0x42, 0x4D,0x4C,0x00,0x00,0x00,0x00,0x00,
                        0x00,0x00,0x1A,0x00,0x00,0x00,0x0C,0x00,0x00,0x00};
const unsigned char HEADER_e[] =  {0x01,0x00,0x18,0x00};
const unsigned char BUFF[] = {0x00,0x00};

unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
unsigned char bmppad[3] = {0,0,0};

typedef struct Images{
  int width;
  int height;
  unsigned char **red;
  unsigned char **green;
  unsigned char **blue;
} Image;

//Declarations
void load_image(Image *image, char *filename);
void save_image(Image *image);

#endif
