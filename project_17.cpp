#include <iostream>
#include <ctime>
using namespace std;

class player {
public:
	virtual int attack();
private:
	int damage;
};
int player::attack() {
	int doble_damage = rand() % damage;
	int player_damage = damage + doble_damage;
	return player_damage;
}

class dino :public player {
public: 
	dino(int dino_base_damage);
	~dino();
	int attack();
	int get_health();
private:
	int dino_base_damage;
	
};

int dino::attack() {
	int doble_damage = rand() % dino_base_damage;
	int dino_damage = dino_base_damage + doble_damage;
	return dino_damage;
}

dino::dino(int dino_base_damage = 10) :
	dino_base_damage(dino_base_damage){}

dino::~dino(){
	this->dino_base_damage = 0;

}



class corona :public player {
public:
	corona(int corona_base_damage);
	~corona();
	int attack();
	int get_health();
private:
	int corona_base_damage;
	
};


int corona::attack() {
	int doble_damage = rand() % corona_base_damage;
	int corona_damage = corona_base_damage + doble_damage;
	return corona_damage;
}

corona::corona(int corona_base_damage = 30) :
	corona_base_damage(corona_base_damage){}


corona::~corona() {
	this->corona_base_damage = 0;
}

int main()
{
	dino aaa;
	corona bbb;
	int dino_health = 150;
	int corona_health = 60;
	while (dino_health > 0 && corona_health > 0) { 
		corona_health = corona_health - aaa.attack();
		cin.get(); 
		dino_health = dino_health - bbb.attack(); 
		cout << "Dino's health: " << dino_health << endl;
		cout << "Corona's health: " << corona_health << endl;
	}
}
