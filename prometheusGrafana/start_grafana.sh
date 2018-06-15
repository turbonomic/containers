#!/bin/bash

echo "[`date`] add data source "

volume=`pwd`/data/grafana
mkdir -p $volume

docker run -d -p 3000:3000 -v $volume:/var/lib/grafana  grafana/grafana

echo "[`date`] access grafana at http://localhost:3000 "
