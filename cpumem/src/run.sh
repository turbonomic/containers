#!/bin/sh

logfile="run.log"

if [ "X$RUN_TYPE" = "X" ] ; then
    RUN_TYPE="memory"
fi

echo "[`date`] begin to run $RUN_TYPE-test " 
if [ "X$MEMORY_NUM" = "X" ] ; then
    MEMORY_NUM=100
fi

if [ "X$CPU_PERCENT" = "X" ] ; then
    CPU_PERCENT=10
fi


cpubin=cpubin
memorybin=membin

if [ "$RUN_TYPE" = "memory" ] ; then
    gcc nummem.c -o $memorybin
    chmod +x $memorybin
    ./$memorybin $MEMORY_NUM | tee $logfile 
else
    gcc cpu.c -o $cpubin
    chmod +x $cpubin
    ./$cpubin $CPU_PERCENT | tee $logfile
fi

echo "[`date`] end of running"
exit 0

