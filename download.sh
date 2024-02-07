#!/bin/bash

downloads_path="$HOME/Downloads"
compressed_file="$PWD/compressed.bin"
decoded_file="$PWD/decoded.txt"

if [ ! -e "$downloads_path" ]; then
    downloads_path="$USERPROFILE/Downloads"
fi

if [ -f "$compressed_file" ]; then
    chmod +w "$compressed_file"
    cp "$compressed_file" "$downloads_path/"
    echo "Compressed file downloaded successfully."
fi

if [ -f "$decoded_file" ]; then
    cp "$decoded_file" "$downloads_path/"
    echo "Decoded file downloaded successfully."
fi
