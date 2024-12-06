#pragma once
#include <iostream>

static const short int max_fps = 90;

static const uint16_t Window_Width	=	800 * 1.35;
static const uint16_t Window_Height =	600 * 1.35;

static const uint16_t Screen_Width = (800 * 1.35) - 50 ;
static const uint16_t Screen_Height = (600 * 1.35) - 50 ;

static const uint8_t Global_Scale = 8;

static const uint8_t Max_FPS = 80;

static const uint16_t Grid_Width = Screen_Width / Global_Scale;
static const uint16_t Grid_Height = Screen_Height / Global_Scale;