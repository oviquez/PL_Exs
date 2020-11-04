#include <stdio.h>
#include <getopt.h>
#include <SFML/Graphics.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb/stb_image_resize.h"


#define MAX_HEIGHT 1080
#define MAX_WIDTH 1920

char *getFont(short type){
    printf("Getting font\n");
    char* fontPath;
    switch (type) {
        case 1:
            fontPath = ("C:\\Windows\\fonts\\arial.ttf");
            break;
        case 2:
            fontPath =("C:\\Windows\\fonts\\impact.ttf");
            break;
        case 3:
            fontPath =("C:\\Windows\\fonts\\INFROMAN.TTF");
            break;
        default:
            fontPath =("C:\\Windows\\fonts\\arial.ttf");
            break;
    }
    return fontPath;
}

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


int getMiddle(int stringLength,short fontSize,int width){
   return (width/2)-(stringLength*(fontSize/2))/2;
}


int writeTextInImage(char *path, char *topText, char *bottomText, short typeFont,short fontSize){
    sfFont* font;
    font = sfFont_createFromFile(getFont(typeFont));
    if (!font){
        printf("Font not found\n");
        return -1;
    }

    sfTexture* texture;
    texture = sfTexture_createFromFile(path, NULL);

    sfVector2u sizeTexture;
    sizeTexture =  sfTexture_getSize(texture);

    sfSprite* sprite;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);



    //text top
    sfText* textTop =  sfText_create();
    sfText_setString(textTop, topText);
    sfText_setFont(textTop, font);
    sfText_setCharacterSize(textTop, fontSize);

    // put the text in middle
    sfVector2f *topVector =NULL;
    topVector = malloc(sizeof(sfVector2f));
    topVector->y = 10;
    topVector->x = getMiddle(strlen(topText),fontSize,sizeTexture.x);
    sfText_setPosition(textTop,*topVector);



    // create bottom text
    sfText* textBottom =  sfText_create();
    sfText_setString(textBottom, bottomText);
    sfText_setFont(textBottom, font);
    sfText_setCharacterSize(textBottom, fontSize);

    // put the text in middle
    sfVector2f *bottomVector =NULL;
    bottomVector = malloc(sizeof(sfVector2f));
    bottomVector->y =  sizeTexture.y-fontSize-15;
    bottomVector->x = getMiddle(strlen(bottomText),fontSize,sizeTexture.x);
    sfText_setPosition(textBottom,*bottomVector);


    printf("Writing Text\n");
    sfRenderTexture *render;
    render = sfRenderTexture_create(sizeTexture.x, sizeTexture.y,0);
    sfRenderTexture_drawSprite(render,sprite,NULL);
    sfRenderTexture_drawText(render,textTop,NULL);
    sfRenderTexture_drawText(render,textBottom,NULL);

    printf("Saving\n");
    sfImage *image =NULL;
    image = sfTexture_copyToImage(sfRenderTexture_getTexture(render));
    sfImage_flipVertically(image);
    sfImage_saveToFile(image,path);

    return 0;
}


int main(int argc, char **argv) {
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
                printf(" \nCommand: ./postal [Image Path]\n");
                printf("Flags:\n");
                printf(" -t [Text]      Write text in top\n");
                printf(" -b [Text]      Write text in bottom\n");
                printf(" -f [1-4]       Chose font to use. 1: Arial 2: Impact 3: Informal Roman \n");
                printf(" -s             Write small text\n");
                printf(" -m             Write medium text\n");
                printf(" -h             Write Big text\n");
                printf("\n -- Example --\n");
                printf(" ../postal \"D:/user/Pictures/image.jpg\" -t \"Bottom Text\" -b \"Top Text\" -m \n");
                return 0;
            case '?':
                return -1;
        }
    }

    if (optind < argc) {
        path = argv[optind];
    }
    if(bottomText == NULL)
        bottomText = "";
    if(topText == NULL)
        topText = "";
    return  verifyImage(path) == 0 ? writeTextInImage(path,topText,bottomText,typeFont,fontSize):-1;
}
