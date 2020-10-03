#include "param.h"
#include "image.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb/stb_image_resize.h"


#define MAX_HEIGHT 1080
#define MAX_WIDTH 1920

int verifyImage(char *path){
    printf("Verify Image\n");
    int width, height, channels;
    unsigned char *image = stbi_load(path, &width, &height, &channels, 0);


    if( image == NULL){
        printf("Image not found\n");
        return -1;
    }


    if(width < 300 && height < 300){
        printf("So Small\n");
        return -1;
    }

    if(width > MAX_WIDTH && height > MAX_HEIGHT){
        printf("Resizing image\n");
        stbir_resize_uint8(
                image,width,height,0,
                image,MAX_WIDTH,MAX_HEIGHT,0,channels);
        width = MAX_WIDTH;
        height = MAX_HEIGHT;
    }
    stbi_write_png(path,width,height,channels,image,0);
    stbi_image_free(image);
    return 0;
}

int getParams (int argc, char *argv[]){
    char *path = NULL;
    char *topText = NULL;
    char *bottomText = NULL;
    short typeFont = 1;
    short fontSize = 15;

    int option;

    while((option = getopt(argc, argv, "t:b:f:smho")) != -1)
    {
        switch(option)
        {
            case 't':
                topText = optarg;
                break;
            case 'b':
                bottomText = optarg;
                break;
            case 'f':
                switch(*optarg)
                {
                    case '1':
                        typeFont =1;
                        break;
                    case '2':
                        typeFont =2;
                        break;
                    case '3':
                        typeFont =3;
                        break;
                    default:
                        typeFont =1;
                        break;
                }

                break;
            case 's':
                fontSize = 15;
                break;
            case 'm':
                fontSize = 50;
                break;
            case 'h':
                fontSize = 90;
                break;
            case 'o':
                printf("\nPostal Generator V1.0  By Daniel Rojas Rodriguez  October 2020\n");
                printf(" \nCommand: ./image [Image Path]\n");
                printf("Flags:\n");
                printf(" -t [Text]      Write text in top\n");
                printf(" -b [Text]      Write text in bottom\n");
                printf(" -f [1-4]       Chose font to use. 1: Arial 2: Impact 3: Terminal \n");
                printf(" -s             Write small text\n");
                printf(" -m             Write medium text\n");
                printf(" -h             Write Big text\n");
                printf("\n -- Example --\n");
                printf(" ../image \"D:/user/Pictures/image.jpg\" -t \"Bottom Text\" -b \"Top Text\" -m \n");
                return 0;
            case '?':
                return -1;
        }
    }

    if (optind < argc) {
        path = argv[optind];
    }

    return  verifyImage(path) == 0 ? execute(path,topText,bottomText,typeFont,fontSize):-1;
}
