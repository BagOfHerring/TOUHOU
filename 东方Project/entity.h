#pragma once

class Entity {
private:
	double x, y;
	double r;
	int id;
	double dx, dy;
	double t = 2;
	double TargetX, TargetY;
public:
	Entity(double x, double y, int id, double dx, double dy, int r) :x(x), y(y), id(id), dx(dx), dy(dy), r(r) {};
	Entity() {};
	~Entity() {};
	double GetX()const;
	double GetY()const;
	double GetR()const;
	double GetDx()const;
	double GetDy()const;
	double GetTarX()const;
	double GetTarY()const;
	double GetT()const;
	int GetID()const;
	void SetDx(double a);
	void SetDy(double a);
	void SetT(double a);
	void UpdateX(double a);
	void UpdateY(double a);
	void move_thread();
	bool whether_arrived(double a = 5)const;
	bool HitDetect(Entity body1, Entity body2, double r = 0)const;
	void move_towards(double x, double y, double s = 2, int T = 10);
};
