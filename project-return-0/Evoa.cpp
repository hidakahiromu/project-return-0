#include"Evoa.h"

Evoa::Evoa(void) {
	GetEnemyName(U"EVOA");
	HP = 100;
	Ex1 = U"AI‚ª©‰ä‚ğ‚¿©•ª‚Ì‘¶İˆÓ‹`‚ğ";
	Ex2 = U"’T‚µ‚Ä‚¢‚é";
	Ex3 = U"‚±‚ÌAI‚Íi‰»‚µ‘±‚¯‚Ä‚¢‚é";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Evoa::~Evoa(void) {

}

void Evoa::jobUpdate(void) {

}

void Evoa::jobDraw(void) {

}