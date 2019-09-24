#!/bin/bash

#addr="www.government.kz"
addr="www.google.com"

date > numbers

for ((i = 0 ; i <72 ; i++)); do
  echo "traceroute $i"
    traceroute $addr >> TraceData
    awk -f trace_parse_time.awk TraceData >> time_split
    awk -f trace_parse_number.awk TraceData >> numbers
    sleep 300

done
