#pragma once
#include <string>

using namespace std;

class MemberQueueNode
{
private:
	string memberData;

public:
	MemberQueueNode(string dataInput = "") : memberData(dataInput) {}
	~MemberQueueNode() {}

	void insertData(const string dataInput) { memberData = dataInput; }
	string getData() const { return memberData; }
};