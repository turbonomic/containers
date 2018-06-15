#!/bin/bash
name="beekman9527/cxy"
SOURCE_COMMIT=94e294850ccdd9422a61ee26cf14fbd694733d35
echo "$SOURCE_COMMIT"

docker build -t $name  --build-arg "SOURCE_COMMIT=$SOURCE_COMMIT" .
