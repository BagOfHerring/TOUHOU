#pragma once
#include<windows.h>
#include"window.h"
#include"Enemy.h"
//用于debug的特殊线程
void Monitor() {
	while (1) {
		if (boss == nullptr) {
			return;
		}
		Sleep(20);
	}

}