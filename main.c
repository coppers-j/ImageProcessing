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

  printf("Width: %d Height: %d PixelComp: %d\nSIZE: %d\n", x, y, n, sz);
  int count = 0;
  for(int i=0;i<x*y*3;i+=3)
  {
    printf("x:%d y:%d - R:%d G:%d B:%d\n", (i/3)%x, (i/3)/x,
                    data[i], data[i+1], data[i+2]);
  }

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
