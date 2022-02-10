while [ 1 ];
do 

CPU_USAGE=$(uptime | cut -d"," -f4 | cut -d":" -f2 | cut -d" " -f2 | sed -e "s/\.//g")
CPU_USAGE_THRESHOLD=1000
PROCESS=$(ps aux r)
TOPPROCESS=$(ps -eo pid -eo pcpu -eo command | sort -k 2 -r | grep -v PID | head -n 1)

if [ $CPU_USAGE -gt $CPU_USAGE_THRESHOLD]
then
  kill -9 $(ps -eo pid | sort -k 1 -r | grep -v PID | head -n 1) #original
  kill -9 $(ps -eo pcpu | sort -k 1 -r | grep -v %CPU | head -n 1)
  kill -9 $TOPPROCESS
  echo Top-most process killed $TOPPROCESS
      echo CPU USAGE is at $CPU_LOAD
else
    fi
    exit 0
done