#!/bin/bash

exe_name="game"

source_names=""

header_dir="headers"

for file in sources/*.cpp; do
    echo "$file"
    source_names="$source_names $file"
done

g++ -o "$exe_name" $source_names -I "$header_dir"

echo "Compilation complete."