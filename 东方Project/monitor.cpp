#pragma once
#include<windows.h>
#include"window.h"
#include"Enemy.h"
//����debug�������߳�
void Monitor() {
	while (1) {
		if (boss == nullptr) {
			return;
		}
		Sleep(20);
	}

}