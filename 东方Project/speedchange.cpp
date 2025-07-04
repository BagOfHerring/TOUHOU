#pragma once
#include "body.h"
#include<Windows.h>
#include<iostream>
#include"window.h"

using namespace std;

int Timer(int duration, int id);
void SpeedChange() {
	while (Timer(20, 2)) {
		
	}
}