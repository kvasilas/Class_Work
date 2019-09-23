#!/bin/bash

#addr="www.government.kz"
addr="www.google.com"

date > numbers

for ((i = 0 ; i <1 ; i++)); do
  echo "traceroute $i"
    traceroute $addr >> TraceData
    awk -f trace_parse_time.awk TraceData >> times
    awk -f trace_parse_number.awk TraceData >> numbers
    sleep 15

done
