#pragma once
#include "MemberQueueNode.h"

class MemberQueue
{
private:
	// Points to (index+1) of front item
	int frontIdx;
	// Points to index of rear item
	int rearIdx;

	// Number of Data
	int dataCount;

	// Circular Queue of Fixed Size 100
	MemberQueueNode *memberContainer;

public:
	MemberQueue();
	~MemberQueue();

	bool empty();
	bool full();
	void push(const string dataInput);
	MemberQueueNode pop();
	MemberQueueNode front();
};
