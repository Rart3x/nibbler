#pragma once

//--------------------Colors--------------------//
#define BLUE    "\033[34m"
#define RED     "\033[31m"
#define RESET   "\033[0m"
//--------------------Fonts--------------------//
#define ARIAL   "./requirements/assets/fonts/arial.ttf"
#define SCIENCE "./requirements/assets/fonts/science.ttf"
//--------------------Keys--------------------//
#define UP          65
#define DOWN        66
#define LEFT        67
#define RIGHT       68
//--------------------Librarys--------------------//
#define AUDIO_PATH  "./requirements/libs/Audio.so"
#define GL_PATH     "./requirements/libs/GL.so"
#define NC_PATH     "./requirements/libs/NC.so"
#define SFML_PATH   "./requirements/libs/SFML.so"
//--------------------Librarys codes--------------------//
#define NONE        -1  
#define SFMLCODE    0
#define NCCODE      1
#define GLCODE      2
#define AUDIOCODE  "3"
//--------------------Modes--------------------//
#define MENU        0
#define GAME        1
#define PAUSE       2
#define QUIT        404
//--------------------RGBA--------------------//
#define CYAN    0, 255, 255, 255
#define WHITE   255, 255, 255, 255
#define BLACK   0, 0, 0, 255
//--------------------Sizes--------------------//
#define SQUARE  10
#define WIDTH   1000
#define HEIGHT  1000

#define MAX_W  (WIDTH / SQUARE)
#define MAX_H  (HEIGHT / SQUARE)
//--------------------Songs--------------------//
#define APPLESONG       "./requirements/assets/audios/apple.ogg"
#define BUTTONSONG      "./requirements/assets/audios/button.ogg"
#define POKESONG        "./requirements/assets/audios/pokemon.ogg"
#define POKEROADSONG    "./requirements/assets/audios/pokemon_road.ogg"