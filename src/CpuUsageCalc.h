#include <fstream>
#include <string>

using std::ifstream;
using std::string;

static long prevBusy = 0;
static long prevTotal = 0;

float usageCPU()
{

    ifstream file("/proc/stat");
    if (!file)
    {
        return 0.0f;
    }

    string cpu;
    long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    file >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;

    long totalIdle = idle + iowait;
    long totalTime = user + nice + system + totalIdle + irq + softirq + steal + guest + guest_nice;
    long busy = totalTime - totalIdle;

    float percentage = 0.0f;
    long deltaTotal = totalTime - prevTotal;

    if (deltaTotal > 0)                                       // avoid division by zero on first call
        percentage = 100.0f * (busy - prevBusy) / deltaTotal;

    prevBusy = busy;
    prevTotal = totalTime;
    
    file.close();
    return percentage;
}