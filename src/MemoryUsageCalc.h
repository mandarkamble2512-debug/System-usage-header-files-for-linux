#include <fstream>
#include <string>
#include <sys/sysinfo.h>
#include <unistd.h>

using std::string;
using std::ifstream;
using std::getline;
using std::stoi;

struct sysinfo info;

long long GetTotalSystemRam()
{
    struct sysinfo info;
    if (sysinfo(&info) != 0) return 0;
    return (long long)info.totalram * info.mem_unit;
}

long long GetCurrentlyUsedRam()
{
    ifstream file("/proc/meminfo");
    string label;
    long long freeMemKb = 0;
    long long totalRam = GetTotalSystemRam();

    // Read the file word by word
    while (file >> label) 
    {
        if (label == "MemAvailable:") 
        {
            if (file >> freeMemKb) 
            {
                break;
            }
        }
    }
    
    // Convert KB to Bytes
    long long freeMemBytes = freeMemKb * 1024LL;
    return totalRam - freeMemBytes;
}

int UsageMemory ()
{
    long long total = GetTotalSystemRam();
    long long used = GetCurrentlyUsedRam();

    if (total == 0) return 0;

    return (int)((used * 100) / total);
}