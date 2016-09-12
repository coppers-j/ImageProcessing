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
  unsigned char *data = stbi_load(filename, &x, &y, &n, 3);

  printf("Width: %d Height: %d PixelComp: %d\n", x, y, n);

  FILE *fp;

  fp = fopen( "file.bmp" , "w" );

  unsigned char o[2];

  fwrite(HEADER_s , 1 , sizeof(HEADER_s) , fp );
  o[0] = x & 0xFF;
  o[1] = (x >> 8) & 0xFF;
  fwrite(o , 1 , sizeof(o) , fp );
  o[0] = y & 0xFF;
  o[1] = (y >> 8) & 0xFF;
  fwrite(o , 1 , sizeof(o) , fp );
  fwrite(HEADER_e , 1 , sizeof(HEADER_e) , fp );
  for(int i=(x*y*3)-1;i>-1;i-=3)
  {
    fprintf(fp, "%c%c%c",data[i], data[i-1], data[i-2]);
  }
  //fwrite(data , 1 , x*y*3 , fp );
  fwrite(BUFF , 1 , sizeof(BUFF) , fp );
  fclose(fp);

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
