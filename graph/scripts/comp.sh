#!/bin/bash
cd ..
gcc -std=c99 -o bin/recommender src/recommender.c src/mergesort.c src/modBfs.c src/linkedList.c src/queue.c src/hashMap.c src/metrics.c