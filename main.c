//
// main.c
// ImageProcessing
//
//  Created by James Copperthwaite on 08/09/2016.
//  Copyright © 2016 James Copperthwaite. All rights reserved.
//

#include "main.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int
main(void)
{
  int x,y,n;
  unsigned char *data = stbi_load("tiles.bmp", &x, &y, &n, 0);
  struct stat attr;
  printf("Width: %d Height: %d PixelComp: %d\n", x, y, n);

  stbi_image_free(data);
}
