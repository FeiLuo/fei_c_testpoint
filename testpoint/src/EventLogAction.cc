#include "EventLogAction.h"
#include "EventLog.h"

EventLogAction::EventLogAction()
{
}

EventLogAction::~EventLogAction()
{
}

void EventLogAction::Action()
{
    EventLog::Log(EventLog::Debug, "This is a Debug test!");
    EventLog::Log(EventLog::Info, "This is a Info test!");
    EventLog::Log(EventLog::Status, "This is a Status test!");
    EventLog::Log(EventLog::Warning, "This is a Warning test!");
    EventLog::Log(EventLog::Error, "This is a Error test!");
    EventLog::Log(EventLog::Exception, "This is a Exception test!");
}

