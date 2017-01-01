@echo off
color a
cls
cd..
gcc -D DEBUG -std=c99 -o bin/Drecommender src/recommender.c src/mergesort.c src/modBfs.c src/linkedList.c src/queue.c src/hashMap.c src/metrics.c