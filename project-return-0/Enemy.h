#pragma once
#include<Siv3D.hpp>


class Enemy {
public:
	Enemy(void);
	~Enemy(void);
	void update(void);
	void draw(void);
<<<<<<< HEAD
	static void OnEnemyFlag(bool next);			//Enemyï¿½Ìƒtï¿½ï¿½ï¿½Oï¿½Ø‚ï¿½Ö‚ï¿½	
	static void Damage(int damage);				//Characterï¿½ï¿½ï¿½ï¿½_ï¿½ï¿½ï¿½[ï¿½Wï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ä‚ï¿½ï¿½éˆï¿½ï¿½
	static void SetEnemyStatus(int HP,String Explain1, String Explain2, String Explain3);	//ï¿½eï¿½Wï¿½ï¿½ï¿½uï¿½ï¿½ï¿½ï¿½HPï¿½Æï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ä‚ï¿½ï¿½éˆï¿½ï¿½
	static void PrintExplanation(void);			//ï¿½Lï¿½ï¿½ï¿½ï¿½ï¿½Nï¿½^ï¿½[ï¿½Ågï¿½ï¿½ï¿½Gï¿½Ìï¿½ï¿½ï¿½\ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½@ï¿½\
	static void GetEnemyName(String name);		//ï¿½ï¿½ï¿½Ì“Gï¿½Ì–ï¿½ï¿½Oï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ä‚ï¿½ï¿½éˆï¿½ï¿½
	static String SetEnemyName(void);			//ï¿½Gï¿½Ì–ï¿½ï¿½Oï¿½ï¿½nï¿½ï¿½ï¿½ï¿½ï¿½ï¿½


	int eneturn = 1;

protected:				//ï¿½pï¿½ï¿½ï¿½pï¿½ÌŠÖï¿½ï¿½Æ‚ï¿½
=======
	static void OnEnemyFlag(bool next);			//Enemy‚Ìƒtƒ‰ƒOØ‚è‘Ö‚¦	
	static void Damage(int damage);				//Character‚©‚çƒ_ƒ[ƒW‚ğ‚à‚ç‚Á‚Ä‚­‚éˆ—
	static void SetEnemyStatus(int HP,String Explain1, String Explain2, String Explain3);	//ŠeƒWƒ‡ƒu‚©‚çHP‚Æà–¾•¶‚ğ‚à‚ç‚Á‚Ä‚­‚éˆ—
	static void PrintExplanation(void);			//ƒLƒƒƒ‰ƒNƒ^[‚Åg‚¤“G‚Ìî•ñ‚ğ•\¦‚·‚é‹@”\
	static void GetEnemyName(String name);		//¡‚Ì“G‚Ì–¼‘O‚ğæ‚Á‚Ä‚­‚éˆ—
	static String SetEnemyName(void);			//“G‚Ì–¼‘O‚ğ“n‚·ˆ—

protected:				//Œp³—p‚ÌŠÖ”‚Æ‚©]
	virtual void jobDraw() = 0;					//EnemyJobs‚Å’è‹`‚·‚é—p‚ÌDraw
	virtual void jobUpdate() = 0;				//EnemyJobs‚Å’è‹`‚·‚é—p‚ÌUpdate

private:
	static String enemyName;
	static int enemyHp;					//“G‚ÌHP
	static String explanation1, explanation2, explanation3;			//à–¾•¶ˆês–ÚA“ñs–ÚAOs–Ú
	static bool EnemyTurnFlag;			//TRUE‚ÌEnemy‚Ìƒ^[ƒ“
>>>>>>> parent of 2edd839... Revert "Merge pull request #3 from hidakahiromu/add/hida"

	virtual void jobDraw() = 0;					//EnemyJobsï¿½Å’ï¿½`ï¿½ï¿½ï¿½ï¿½pï¿½ï¿½Draw
	virtual void jobUpdate() = 0;				//EnemyJobsï¿½Å’ï¿½`ï¿½ï¿½ï¿½ï¿½pï¿½ï¿½Update

private:
	static String enemyName;
	static int enemyHp;					//ï¿½Gï¿½ï¿½HP
	static String explanation1, explanation2, explanation3;			//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½sï¿½ÚAï¿½ï¿½sï¿½ÚAï¿½Oï¿½sï¿½ï¿½
	static bool EnemyTurnFlag;			//TRUEï¿½Ìï¿½Enemyï¿½Ìƒ^ï¿½[ï¿½ï¿½

};