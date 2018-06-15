#!/bin/bash

datav=`pwd`/data/prometheus
mkdir -p $datav
cp ./prometheus.yml $datav

echo "$datav"
options="-config.file=/prometheus-data/prometheus.yml"
options="$options --storage.local.path=/prometheus-data/data/"

docker run -d -p 19090:9090 -v $datav:/prometheus-data/ prom/prometheus  $options 
# docker run -p 9090:9090  prom/prometheus  
