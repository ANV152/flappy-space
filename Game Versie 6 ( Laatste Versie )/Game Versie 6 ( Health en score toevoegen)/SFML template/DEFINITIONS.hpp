#pragma once

#define SCREEN_WIDTH 1240
#define SCREEN_HEIGHT 974

#define SPLASH_STATE_SHOW_TIME 3.0

// -------------------------------------------- SPRITES ---------------------------------------------------//

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/background_FlappySpace.png"

#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/background_space.png"
#define GAME_BACKGROUND_FILEPATH "Resources/res/background_space.png"

#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define GAME_SUBTITLE_FILEPATH "Resources/res/Subtitle.png"
 #define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"

#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/Game_Over_Background.png"
#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"


#define PIPE_UP_FILEPATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/res/PipeDown.png"

#define SCORING_PIPE_FILEPATH "Resources/res/InvisibleScoringPipe.png"

#define LAND_FILEPATH "Resources/res/background_space_ground.png"

#define SPACE_BIR_FRAME_1_FILEPATH "Resources/res/Space-bird-2.png"
#define SPACE_BIR_FRAME_2_FILEPATH "Resources/res/Space-bird-3.png"
#define SPACE_BIR_FRAME_3_FILEPATH "Resources/res/Space-bird-4.png"
//#define BIR_FRAME_4_FILEPATH "Resources/res/bird-04.png"
// 
//Sound effects


#define HIT_SOUND_FILEPATH "Resources/audio/Hit.wav"
#define POINT_SOUND_FILEPATH "Resources/audio/Point.wav"
#define BACKGROUND_MUSIC "Resources/audio/FlappySoundtrack.wav"

#define FIRE_BOOST_FILE_PATH "Resources/res/Fire-jet.png"

#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"

#define ASTEROID1_FILEPATH "Resources/res/Asteroid1.png"
#define ASTEROID2_FILEPATH "Resources/res/Asteroid2.png"

#define BULLET_FILEPATH "Resources/res/Bullet.png"

#define ASTEROID_FIRE_FILEPATH "Resources/res/Fire-Asteroid.png"
#define EXPLOSION_FILEPATH "Resources/res/Explosion.png"

#define GAS_FILEPATH "Resources/res/Gas.png"

#define WAPEN_FILEPATH "Resources/res/geweer.png"
//--------------------------------------- ANIMATION ----------------------------------------------------//
#define BIRD_ANIMATION_DURATION 1.0f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3
#define BIRD_STATE_LEFT 4
#define BIRD_STATE_RIGHT 5

//-------------------------------------- PHYSICS -------------------------------------------------------//
#define GRAVITY 0.04f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f

#define PIPE_MOVEMENT_SPEED 250.0f
#define ASTEROID_SPAWN_FREQUENCY 1.25f
#define GASOLINE_SPAWN_FREQUENCY 2.5f

#define EXPLOSION_DURATION 3.0f
#define EXPLOSION_SOUND_FILEPATH "Resources/audio/explosion.wav"

#define ASTEROID_STATE_EXPLOSION 1
#define ASTEROID_STATE_NORMAL 2


enum GameStates//Dit is voor het tracken van wat gebeurt tijdens de gamestate
{
	eReady,
	ePlaying,
	eGameOver
};
#define FLASH_SPEED 2000.0f

#define TIME_BEFORE_GAMEOVER_SHOW 1.5f
#define SCALE_SPEED 1.65f