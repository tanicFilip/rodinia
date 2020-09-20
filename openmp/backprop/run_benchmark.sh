realSecondsElapsed='0.0'
runs=$1

for i in $(seq 1 $runs);
do
   out="$(time ( ./run ) 2>&1 1>/dev/null )"
   realTime="$(echo $out | sed 's/.*real\s\([^\s]*\).*/\1/')"
   minutes="$(echo $realTime | sed 's/\([^m]*\).*/\1/')"
   seconds="$(echo $realTime | sed 's/\([^m]*\)m\(.*\)/\2/')"
   seconds="$(echo $seconds | tr , .)"
   realSecondsElapsed="$(echo "$realSecondsElapsed + $minutes * 60.0 + $seconds" | bc -l)"
done
echo "Total wall clock run time: $realSecondsElapsed" &> result
avgRuntime="$(echo "$realSecondsElapsed / $runs" | bc -l)"
echo "Average wall clock time of single run: $avgRuntime" &>> result