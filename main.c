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
load_image(Image *image, char *filename)
{
  //TODO: Free variables once finished
  int x,y,n;
  unsigned char *data = stbi_load(filename, &x, &y, &n, 3);
  image->width = x;
  image->height = y;

  printf("Width: %d Height: %d PixelComp: %d\n", x, y, n);


  //Initialise x length array of arrays
  image->red = (unsigned char **)calloc(x,sizeof(unsigned char*));
  image->blue = (unsigned char **)calloc(x,sizeof(unsigned char*));
  image->green = (unsigned char **)calloc(x,sizeof(unsigned char*));

  //Initialises each element of the array with another array of y length
  for(int i = 0; i < x; i++){
      image->red[i] = (unsigned char *)calloc(y,sizeof(unsigned char));
      image->green[i] = (unsigned char *)calloc(y,sizeof(unsigned char));
      image->blue[i] = (unsigned char *)calloc(y,sizeof(unsigned char));
  }


  int c_x = 0;    //x counter
  int c_y = 0;    //y counter

  //loads image into struct
  for(int iy=(y-1)*3; iy>-1;iy-=3){
    c_x = 0;
    for(int ix=0; ix<(x*3); ix+=3){
      image->red[c_x][c_y] = (unsigned char)data[(iy*x)+ix];
      image->green[c_x][c_y] = (unsigned char)data[(iy*x)+ix+1];
      image->blue[c_x][c_y] = (unsigned char)data[(iy*x)+ix+2];
      c_x++;
    }
    c_y++;
  }

  stbi_image_free(data);
}

void
save_image(Image *image)
{
  FILE *fp;

  //setting the name of the ouput file
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  char outFile[80];
  /*sprintf (outFile, "Output Image %d-%d-%d %d.%d.%d.bmp", tm.tm_year + 1900,
              tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);*/
  sprintf(outFile, "output.bmp");
  //puts(outFile);

  fp = fopen( outFile , "w" );

  unsigned char o[2];

  fwrite(HEADER_s , 1 , sizeof(HEADER_s) , fp );
  o[0] = image->width & 0xFF;
  o[1] = (image->width >> 8) & 0xFF;
  fwrite(o , 1 , sizeof(o) , fp );
  o[0] = image->height & 0xFF;
  o[1] = (image->height >> 8) & 0xFF;
  fwrite(o , 1 , sizeof(o) , fp );
  fwrite(HEADER_e , 1 , sizeof(HEADER_e) , fp );

  for(int j=0; j<image->height;j++){
    for(int i=0; i<image->width; i++){
      fprintf(fp, "%c%c%c",image->blue[i][j], image->green[i][j],
                                              image->red[i][j]);
    }
  }

  fwrite(BUFF , 1 , sizeof(BUFF) , fp );
  fclose(fp);
  printf("Saved file as:%s\n", outFile);
}

int
main(int argc, char **argv)
{
  if (argc==2){
    if( access( argv[1], F_OK ) != -1 ) {
      Image image1;
      load_image(&image1, argv[1]);
      save_image(&image1);
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
