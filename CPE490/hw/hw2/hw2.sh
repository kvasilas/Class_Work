#!/bin/bash

addr="www.government.kz"

ping -c 10000 $addr >> RAWDATA

awk -f ping_delay_val.awk RAWDATA >> cut_data

