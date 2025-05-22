
#!/bin/bash

set -e

if [[ $# -ne 1 ]]; then
  echo "Usage: $0 <file>"
  exit 1
fi

INPUT_FILE="$1"

filesize=$(stat -c%s "$INPUT_FILE")

full_words=$((filesize / 4 * 4))

WORDS=$(od -t u4 -An -N "$full_words" -v "$INPUT_FILE")
CHECKSUM=0
for word in $WORDS; do
  CHECKSUM=$(( (CHECKSUM + word) % 4294967296 ))
done

remain=$((filesize % 4))
if [[ $remain -ne 0 ]]; then
  offset=$full_words
  
  bytes=$(dd if="$INPUT_FILE" bs=1 skip=$offset count=$remain 2>/dev/null | hexdump -v -e '1/1 "%02x"')

  word=0
  for ((i=0; i<remain; i++)); do
    byte_hex="${bytes:$((i*2)):2}"
    byte_val=$((16#$byte_hex))
    word=$((word + (byte_val << (8 * i))))
  done

  CHECKSUM=$(( (CHECKSUM + word) % 4294967296 ))
fi

echo "$CHECKSUM"
