#!/bin/bash

#addr="www.google.com"
addr="www.government.kz"


for ((i = 0 ; i < 72; i++)); do
  echo "traceroute $i"
    traceroute $addr >> TraceData
    sleep 300
done