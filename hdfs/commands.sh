#!/bin/sh

echo "print content of Hadoop directory"
hdfs dfs -ls projects


echo "create java directory"
hdfs dfs -mkdir projects/java


echo "copy file from local to hdfs"
hdfs dfs -put ${HOME}/projects/java/myfirst.java projects/java
