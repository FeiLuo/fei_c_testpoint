#include "Duration.h"

#define DURATION_GAP_TIME   2
#define AS_MIN(x, y) ((x)<(y) ? (x):(y))
#define AS_MAX(x, y) ((x)>(y) ? (x):(y))


ASDurationNode::ASDurationNode()
: mDurationStartTime(0), 
mDurationEndTime(0)
{
}

ASDurationNode::ASDurationNode(Uint64 startTime, Uint64 endTime)
: mDurationStartTime(startTime),
mDurationEndTime(endTime)
{
}

ASDurationNode::~ASDurationNode()
{
}

ASDurationManager::ASDurationManager()
{
}

ASDurationManager::~ASDurationManager()
{
    mDurationList.Clear();
}

void ASDurationManager::MergeDuration(Uint64 startTime, Uint64 endTime)
{
    if (endTime < startTime)
        return;

    //          |__________|           |____________|              ......
    // 
    // 1.                                           |________|
    //
    // 2.                      |_______|
    // 
    // 3.                    |_____|
    // 
    // 4.                                                |_______|
    // 
    // 5.                                       |______________|
    // 
    // 6.                         |___________|
    // 
    // 7.                                  |_______|
    // 
    // Explain:
    //   1. there is a continued duration at the tail of current duration, it should 
    //      be merged into the current duration
    //   2. there is a continued duration at the head of current duration, it should 
    //      be merged into the current duration, same as 1st.
    //   3. this is a new duration, and it will be processed in the next loop when
    //      processing previous duration
    //   4. this is a new duration, one new duration node should be added after the 
    //      current duration
    //   5 & 6 & 7. 
    //      there is a overlapped duration between the new duration and current duration,
    //      all of them should be merged together.

    ASDurationListIter iter = mDurationList.Begin();
    for(; iter != mDurationList.End(); ++iter)
    {
        ASDurationNode& node = *iter;

        if (startTime >= node.mDurationEndTime)
        {
            // Explain 1
            if ((startTime - node.mDurationEndTime) <= DURATION_GAP_TIME)
            {
                node.mDurationEndTime = endTime;
                return;
            }
            // Explain 4
            else
            {
                mDurationList.InsertAfter(iter, new ASDurationNode(startTime, endTime));
                return;
            }
        }
        else if (endTime <= node.mDurationStartTime)
        {
            // Explain 2
            if ((node.mDurationStartTime - endTime) <= DURATION_GAP_TIME)
            {
                node.mDurationStartTime = startTime;
                return;
            }
            else
            {
                // Explain 3
                continue;
            }
        }
        // Explain 5, 6, 7
        else
        {
            node.mDurationStartTime = AS_MIN(node.mDurationStartTime, startTime);
            node.mDurationEndTime = AS_MAX(node.mDurationEndTime, endTime);
            return;
            }
        }

    // arrive at the begin
    mDurationList.Push_Front(new ASDurationNode(startTime, endTime));
    mCurrentIter = mDurationList.Begin();
    return;
}

bool ASDurationManager::IsTimeInDuration(Uint64 nTime)
{
    // nTime should be in the [startTime, endTime)
    ASDurationListIter iter = mDurationList.End();
    for(; iter != mDurationList.Begin(); --iter)
    {
        ASDurationNode& node = *iter;
        if ((nTime >= node.mDurationStartTime) && (nTime < node.mDurationEndTime))
            return true;
    }
    return false;
}

void ASDurationManager::Print(ostream& os)
{
    ASDurationListIter iter = mDurationList.Begin();
    os << "ASDurationManager Duration List Print:" << endl; 
    for(; iter != mDurationList.End(); ++iter)
    {
        ASDurationNode& node = *iter;
        os  << "[" << node.mDurationStartTime << ","
            << node.mDurationEndTime << "]"
            << endl;
    }
    os << endl;
}

Duration::Duration(void)
{
}

Duration::~Duration(void)
{
}

void Duration::Action()
{
    ASDurationManager manager;
    manager.MergeDuration(10, 20);
    manager.Print();

    manager.MergeDuration(21, 30);
    manager.Print();


}
