#!/bin/sh

# Usage: ./benchmark.sh <count> <runs> [min] [max]
# Example: ./benchmark.sh 500 10

COUNT=${1:-}
RUNS=${2:-}

if [ -n "${3:-}" ]; then
	MINV=$3
else
	MINV=0
fi

if [ -n "${4:-}" ]; then
	MAXV=$4
else
	MAXV=1000000
fi

if [ "$MINV" -gt "$MAXV" ] 2>/dev/null; then
	echo "Error: min must be <= max" 1>&2
	exit 1
fi

if [ -z "$COUNT" ] || [ -z "$RUNS" ]; then
	echo "Usage: $0 <count> <runs> [min] [max]" 1>&2
	echo "Example: $0 500 10" 1>&2
	exit 1
fi

if [ ! -x ./push_swap ]; then
	echo "Error: ./push_swap not found. Run 'make' first." 1>&2
	exit 1
fi

CHECKER=""
if [ -x ./checker_linux ]; then
	CHECKER="./checker_linux"
elif [ -x /home/synoshah/Downloads/checker_linux ]; then
	CHECKER="/home/synoshah/Downloads/checker_linux"
fi

STRICT=0
STRICT_LABEL=""
if [ "$COUNT" -eq 100 ] 2>/dev/null; then
	STRICT=700
	STRICT_LABEL="<700"
elif [ "$COUNT" -eq 500 ] 2>/dev/null; then
	STRICT=5500
	STRICT_LABEL="<=5500"
fi

SUM=0
PASS_STRICT=0
MIN_MOVES=""
MAX_MOVES=0

I=1
while [ "$I" -le "$RUNS" ]; do
	if [ "$MINV" -lt 0 ] 2>/dev/null; then
		RANGE=$((MAXV - MINV))
		ARG=$(shuf -i 0-"$RANGE" -n "$COUNT" | while read -r n; do printf "%s " $((n + MINV)); done)
	else
		ARG=$(shuf -i "${MINV}-${MAXV}" -n "$COUNT" | tr '\n' ' ')
	fi
	TMP=$(mktemp)
	./push_swap $ARG > "$TMP"
	MOVES=$(wc -l < "$TMP" | tr -d ' ')

	OK="SKIP"
	if [ -n "$CHECKER" ]; then
		OK=$($CHECKER $ARG < "$TMP")
	fi
	
	rm -f "$TMP"

	printf "%02d moves=%s check=%s\n" "$I" "$MOVES" "$OK"

	SUM=$((SUM + MOVES))
	if [ -z "$MIN_MOVES" ] || [ "$MOVES" -lt "$MIN_MOVES" ]; then
		MIN_MOVES=$MOVES
	fi
	if [ "$MOVES" -gt "$MAX_MOVES" ]; then
		MAX_MOVES=$MOVES
	fi
	if [ "$STRICT" -ne 0 ]; then
		if [ "$COUNT" -eq 100 ] && [ "$MOVES" -lt "$STRICT" ]; then
			PASS_STRICT=$((PASS_STRICT + 1))
		elif [ "$COUNT" -eq 500 ] && [ "$MOVES" -le "$STRICT" ]; then
			PASS_STRICT=$((PASS_STRICT + 1))
		fi
	fi

	I=$((I + 1))
done

AVG=$((SUM / RUNS))
echo "---"
echo "count=$COUNT runs=$RUNS avg=$AVG min=$MIN_MOVES max=$MAX_MOVES"
if [ "$STRICT" -ne 0 ]; then
	echo "strict $STRICT_LABEL: $PASS_STRICT/$RUNS"
fi
if [ -z "$CHECKER" ]; then
	echo "note: checker not found/executable; check=SKIP"
fi
