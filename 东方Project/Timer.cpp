#pragma once
#include<time.h>
//���ã�����ÿx�����һ���жϣ���ʱ����1��δ������0������ĳ����Ϊÿx��һ��
int Timer(int duration, int id) {

	static int startTime[30];

	int endTime = clock();

	if (endTime - startTime[id] > duration) {

		startTime[id] = endTime;

		return 1;

	}

	return 0;

}