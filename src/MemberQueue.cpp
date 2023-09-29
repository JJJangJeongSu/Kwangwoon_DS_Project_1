#include "MemberQueue.h"
#include "MemberQueueNode.h"

MemberQueue::MemberQueue()
{
    // Dynamic allocation: Array of MemberQueueNode
    memberContainer = new MemberQueueNode[100];

    // Initial value of Idx's
    frontIdx = 0;
    rearIdx = 0;

    // Initial value of Data
    dataCount = 0;
}
MemberQueue::~MemberQueue()
{
    delete[] memberContainer;
}

bool MemberQueue::empty()
{
    return dataCount == 0;
}
bool MemberQueue::full()
{
    return dataCount == 100;
}
void MemberQueue::push(const string dataInput)
{
    if (full())
        // 나중에 개선 - 직접 에러 출력
        throw "Error: Queue is Full";

    memberContainer[rearIdx].insertData(dataInput);
    // Update dataCount
    dataCount++;
    // Update rearIdx (circular queue)
    rearIdx = (rearIdx + 1) % 100;
}

MemberQueueNode MemberQueue::pop()
{
    if (empty())
        throw "Error: Queue is Empty";

    const string poppedData = memberContainer[frontIdx].getData();
    dataCount--;
    frontIdx = (frontIdx - 1) % 100;
    return MemberQueueNode(poppedData);
}

MemberQueueNode MemberQueue::front()
{
    string frontData = memberContainer[frontIdx].getData();
    return MemberQueueNode(frontData);
}
