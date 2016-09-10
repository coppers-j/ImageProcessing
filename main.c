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

void
load_image(char *filename)
{
  int x,y,n;
  unsigned char *data = stbi_load(filename, &x, &y, &n, 0);
  struct stat attr;
  printf("Width: %d Height: %d PixelComp: %d\n", x, y, n);

  stbi_image_free(data);
}

int
main(int argc, char **argv)
{
  if (argc==2){
    if( access( argv[1], F_OK ) != -1 ) {
      load_image(argv[1]);
    } else {
      printf("File %s does not exist\n", argv[1]);
    }
  }else if (argc<2){
    printf("Please input filename e.g ./main image.jpg\n");
  }else{
    printf("Too many input arguments\n");
  }
  return 0;
}
