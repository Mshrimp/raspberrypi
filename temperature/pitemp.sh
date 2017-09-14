#!/bin/bash

cd /sys/class/thermal/thermal_zone0

while((1))
do
	date
	cat temp
	sleep 2
done
