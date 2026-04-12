# System-usage-header-files-for-linux
this is  a repository made for developers in linux for finding system usage like CPU, Ram easily without having to code it from start

##For using CpuUsageCalc.h

1) use the function **UsageCPU()** to find the Cpu usage in the system

##For using MemoryUsageCalc.h

1) use GetCurrentlyUsedRam() function to get currently used ram; it returns a long long int type;
2) use GetTotalSystemRam() to get total system ram; it also returns a long long int type;
3) use UsageMemory() function to get total system ram usage in persantage; it just returns a int type;

##How to use 
1) I recommend to download the **.zip** file and manually add the need files in your cmake
2) else just copy and paste the header file next to your main.cpp/main.c and use include key word to include them
