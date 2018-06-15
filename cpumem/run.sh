#!/bin/bash

img=beekman9527/cpumemload:latest
env="-e RUN_TYPE=cpu -e CPU_PERCENT=50"
docker run -d --cpus="0.1" $env $img 
