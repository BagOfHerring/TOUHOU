#pragma once
#include"entity.h"
#include<cmath>
#include<Windows.h>
using namespace std;

bool Entity::HitDetect(Entity body1, Entity bullet, double r) const {
	if (pow(body1.GetX() - bullet.GetX(), 2) + pow(body1.GetY() - bullet.GetY(), 2) < pow(body1.GetR() + bullet.GetR() + r, 2))
		return 1;
	else
		return 0;
}
double Entity::GetX() const {
	return x;
}
double Entity::GetY() const {
	return y;
}
double Entity::GetR() const {
	return r;
}
void Entity::UpdateX(double a) {
	x += a;
}
void Entity::UpdateY(double a) {
	y += a;
}
double Entity::GetDx() const {
	return dx;
}
double Entity::GetDy() const {
	return dy;
}
int Entity::GetID() const {
	return id;
}
double Entity::GetT() const {
	return t;
}
double Entity::GetTarX() const {
	return TargetX;
}
double Entity::GetTarY()const {
	return TargetY;
}
void Entity::SetDx(double a) {
	dx = a;
}
void Entity::SetDy(double a) {
	dy = a;
}
void Entity::SetT(double a) {
	t = a;
}
void Entity::move_towards(double a, double b, double s, int T) {
	t = s;
	TargetX = a;
	TargetY = b;
	if (abs(this->GetX() - a) < 1e-5) {
		SetDx(0);
		SetDy(-(double(GetY()) - double(b)) / abs(double(GetY() - b)) * t);
	}

	else {
		double tan = -(double(GetY()) - double(b)) / abs(double(GetX() - a));
		SetDy((tan / sqrt(tan * tan + 1)) * t);
		SetDx((-double(GetX() - a) / abs(GetX() - a) / sqrt(tan * tan + 1)) * t);
	}
}
bool Entity::whether_arrived(double a)const {
	if (pow(this->GetX() - this->GetTarX(), 2) + pow(this->GetY() - this->GetTarY(), 2) > a) {
		return 0;
	}
	else
		return 1;
}
void Entity::move_thread() {
	if (!this->whether_arrived()) {
		this->UpdateX(this->GetDx());
		this->UpdateY(this->GetDy());
	}
}

