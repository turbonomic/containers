#!/bin/bash

#url=productpage.default:9080/productpage
url=httpbin.default:8000/ip
options="--connect-timeout 10 --max-time 30 -s"

echo "[`date`] begin call"

while true
do
     curl $options $url -o /dev/null 
     curl $options $url -o /dev/null
     sleep 3
done


