#pragma once
#include<time.h>
//作用：控制每x秒进行一次判断，到时返回1，未到返回0，控制某个行为每x秒一次
int Timer(int duration, int id) {

	static int startTime[30];

	int endTime = clock();

	if (endTime - startTime[id] > duration) {

		startTime[id] = endTime;

		return 1;

	}

	return 0;

}