#ifndef __KONSTANTEN_H__
#define __KONSTANTEN_H__

#include "Box2D\Box2D.h"

#define MATH_PI 3.14159265359f
#define MATH_TO_RADIANS 0.0174532925f

#define PLAYER 1
#define ENEMY 2
#define BULLET 3
#define PLAYER_FOOD 4
#define PLAYER_RIGHT_SIDE 5
#define PLAYER_RIGHT_START_CLIMB 6
#define PLAYER_LEFT_SIDE 7
#define PLAYER_LEFT_START_CLIMB 8
#define CLIMBFIXTURE 9
#define KISTE 10
#define ANKER 11
#define DYNAMIC_KISTE 12
#define ENEMY_FOOT 13

#define BOX2D_STEP 0.015f

#define BOX2D_DEBUG true

//Umrechnung von Box2D Metern (Box2D Einheit) zu CoCos2D Points (Pixeln)
//Minimum: 3.2px/PTM_RATIO = 0.1 Meter
//Maximum: 320px/PTM_RATIO = 10 Meter
#define PTM_RATIO 32.0f

#define GRAVITY_Y 25.0f

//Das hier ist schon mim MapEditor abgestimmt!
#define MIN_KAMERA_POS 0
#define MAX_KAMERA_POS 480
#define MAX_MAP_HEIGHT 1280

//Ja die Speed halt
#define ANKER_SPEED 30.0f

#define NORMALIZE_ANKER_PULL false

#define CAN_JUMP_WHILE_HOOKING true
#define CAN_MOVE_WHILE_HOOKING true
#define CAN_SHOOT_WHILE_HOOKING true

#define PLAYER_SLOW_HOOKING 0.6f

//Bullets

//Wichtig, Gewicht = Kraft die sp�ter auf andere K�rper �bertragen wird
#define BULLET_DENSITY 75.0f

//Ja die Speed halt
#define BULLET_SPEED 35.0f

//In sekunden
#define BULLET_SHOOT_SPEED 0.2f

//So Zeug wie maximale Geschwindigkeit \
//Das man geduckt langsamer l�uft
//Kletter-Geschwindigkeit
#pragma region PLAYER_VARIABLES

#define PLAYER_DENITY 10.0f

//Maximale Geschwindigkeit (Wird mit Gewicht multipliziert)
#define PLAYER_MAX_SPEED 0.6f

//Geschwindigkeits-�nderung, also wie schnell man die Richtung wechselt etc.
#define PLAYER_SPEED_CHANGE 2.0f

//Slow wenn der Spieler sich nicht bewegt (Simuliert Reibung)
#define PLAYER_SLOW_MULTIPLIER 2.5f

//Sprung Kraft des Spielers
#define PLAYER_JUMP_SPEED 0.8f

#define PLAYER_START_JUMP_TIME 0.00f

//Gr��ere Zahl weniger Slow (1.0 = bleibt wie aufm Boden)
#define PLAYER_SLOW_FALLING 0.5f
#define PLAYER_SLOW_FLYING 0.6f

#define PLAYER_SLOW_WHILE_FLYING 0.2f

//Slowness, wenn er abspringt
#define PLAYER_SLOW_ON_JUMP 0.4f

#define PLAYER_JUMP_COOLDOWN 0.4f

//Kletter Geschwindigkeit
#define PLAYER_CLIMBING_SPEED 0.4f

#define PLAYER_CLIMBING_START_JUMP 5.0f

//Wie stark bewegbare Objecte vom Spieler weggedr�ckt werden
#define PLAYER_MAGNETIK_OBJECT_REJECT 5.0f

#pragma endregion

#pragma region PLAYER_FALL_VARIABLES


//Normal Jump 0,45sec

//Fallzeit * this = Zeit in Sekunden f�r den Debuff (Langsamer Laufen)
#define FALL_DEBUF_TIME_MULTIPLIER 0.0f
//MaxSpeed * this = Maximale Geschwindigkeit die der Spieler noch haben kann mit Debuff (Langsamer Laufen)
#define FALL_DEBUF_SPEED_MULTIPLIER 0.4f
//Nicht zu klein einstellen, sonst schwebt der Spieler nur noch rum
#define FALL_MAX_SPEED_WITHOUT_DEBUFF 0.4f

//Fall-Geschwindigkeit ab wann der Spieler schaden bekommt und stehen bleibt
//3 ist ZIEMLICH schnell
#define FALL_MAX_SPEED_WITHOUT_DAMAGE 0.7f
//FallZeit * this = Damage
#define FALL_DAMAGE_MULTIPLIER 2.0f
//Fallzeit * this = Zeit in Sekunden die der Spieler stehen bleibt;
#define FALL_STOP_TIME_MULTIPLIER 0.0f

#pragma endregion

enum EffectSizes {
	IMPULSE_SIZE =          24
};

enum EntityGroups {
	SHIP =				0x0001,
	ASTEROID =			0x0002,
	IMPULSE =			0x0008
};

struct MyContact {
	b2Fixture *fixtureA;
	b2Fixture *fixtureB;
	bool operator==(const MyContact& other) const
	{
		return (fixtureA == other.fixtureA) && (fixtureB == other.fixtureB);
	}
};

//Bullet, HitBody, Point, Force
struct BulletHit {
	b2Fixture *bulletFixture;
	b2Fixture *hitFixture;

	bool operator==(const BulletHit& other) const
	{
		//Just for better readability
		return (\
				bulletFixture == other.bulletFixture) \
			&& (hitFixture == other.hitFixture);
	}
};

class Konstanten{
};

//Create new Animation und speichern in Cache
//Get Animation:
//CCAnimate::create(CCAnimationCache::sharedAnimationCache()->animationByName(NAME))
float registerAction(char *spriteFrames[], float delay, char*name, bool goBack, bool cache){
	Animation * anim;

	cocos2d::Array * array = new cocos2d::Array();
	anim = Animation::create();

	for(int i=0;spriteFrames[i] != NULL; i++){
		if(cache){
			anim->addSpriteFrame(cocos2d::SpriteFrameCache::getInstance()->spriteFrameByName(spriteFrames[i]));
		}else{
			anim->addSpriteFrameWithFileName(spriteFrames[i]);
		}
	}
	
	anim->setDelayPerUnit(delay);
	anim->setRestoreOriginalFrame(goBack);

	AnimationCache::getInstance()->addAnimation(anim,name);

	return anim->getDuration();
}

#endif