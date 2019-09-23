#!/bin/bash

addr="www.government.kz"


for ((i = 0 ; i <3 ; i++)); do
  echo "traceroute $i"
    traceroute $addr >> TraceData
    awk -f trace_parse_time.awk TraceData > times.txt
    awk -f trace_parse_number.awk TraceData > numbers.txt
    sleep 15

done