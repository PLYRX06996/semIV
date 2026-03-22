#!/bin/bash

echo "Enter number of processes:"
read n

arri=()
burst=()
rem=()
wt=()
tat=()
rt=()

for ((i=0;i<n;i++))
do
    echo "Process P$i arri Time:"
    read arri[i]
    echo "Process P$i Burst Time:"
    read burst[i]
    rem[i]=${burst[i]}
done

echo "Enter Time Quantum:"
read tq

time=0
comp=0

echo ""
echo "Gantt Chart:"

while [ $comp -lt $n ]
do
    for ((i=0;i<n;i++))
    do
        if [ ${rem[i]} -gt 0 ] && [ ${arri[i]} -le $time ]; then
            echo -n "P$i "

            if [ ${rem[i]} -gt $tq ]; then
                time=$((time + tq))
                rem[i]=$((rem[i] - tq))
            else
                time=$((time + rem[i]))
                wt[i]=$((time - burst[i] - arri[i]))
                tat[i]=$((time - arri[i]))
                rem[i]=0
                comp=$((comp + 1))
            fi
        fi
    done
done

echo ""
echo ""

echo "Process  AT  BT  WT  TAT"
total_wt=0
total_tat=0

for ((i=0;i<n;i++))
do
    echo "P$i      ${arri[i]}   ${burst[i]}   ${wt[i]}   ${tat[i]}"
    total_wt=$((total_wt + wt[i]))
    total_tat=$((total_tat + tat[i]))
done

echo ""
echo "Average Waiting Time = $(echo "scale=2; $total_wt / $n" | bc)"
echo "Average Turnaround Time = $(echo "scale=2; $total_tat / $n" | bc)"