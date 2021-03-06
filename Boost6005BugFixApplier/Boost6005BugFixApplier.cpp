// Boost6005BugFixApplier.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "wtypes.h"
#include "Windows.h"

#include <iostream>

bool fixBoostIpcSharedMem6005issue()
{
    bool result = false;

    HANDLE hEventLog = ::RegisterEventSourceA(NULL, "EventLog");
    if (hEventLog)
    {
        const char* msg = "simple boost shared memory fix for 6005";

        if (::ReportEventA(hEventLog, EVENTLOG_INFORMATION_TYPE, 0, 6005, NULL, 1, 0, &msg, NULL))
            result = true;

        ::DeregisterEventSource(hEventLog);
    }

    return result;
}
using namespace std;
int main()
{
    //Powershell command (Admin req.)
    // Write - EventLog - LogName System - Source "EventLog" - EntryType Information - EventId 6005 - Category 0 - Message "The Event log service was started."
    
    cout << "Attempted to apply fix... (0 is a fail, 1 is success)\n";
    bool result = fixBoostIpcSharedMem6005issue();
    cout << result << '\n';
    if (result) {
        cout << "Successfully applied fix! Make sure to restart steamVR completely!\n";
    }
    else {
        cout << "FAILED to apply fix, this MUST be run as Admin!\n";
    }
    cin.ignore();
    cin.get();
    return 0;
}

