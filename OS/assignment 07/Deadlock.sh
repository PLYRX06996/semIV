#!/bin/bash

recA=0
recB=0

echo "Starting Deadlock Simulation..."
echo ""

(
    echo "Process 1: Trying to acquire Resource A"
    if [ $recA -eq 0 ]; then
        recA=1
        echo "Process 1: Acquired Resource A"
    fi

    sleep 1

    echo "Process 1: Trying to acquire Resource B"
    if [ $recB -eq 1 ]; then
        echo "Process 1: Waiting for Resource B (Deadlock occurs)"
    fi
) &

(
    echo "Process 2: Trying to acquire Resource B"
    if [ $recB -eq 0 ]; then
        recB=1
        echo "Process 2: Acquired Resource B"
    fi

    sleep 1

    echo "Process 2: Trying to acquire Resource A"
    if [ $recA -eq 1 ]; then
        echo "Process 2: Waiting for Resource A"
    fi
) &

wait

echo ""
echo "Deadlock situation demonstrated!"