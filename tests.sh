#!/bin/bash

EXEC=./so_long
MAP_DIR=./maps1
FAIL_DIR=./maps1/fail_map

VALGRIND="valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --track-origins=yes -q"

echo "===== TEST MAP VALIDES ====="

for file in $MAP_DIR/*
do
echo "----------------------------"
echo "Test : $file"
$VALGRIND $EXEC "$file"
echo ""
done

echo "===== TEST MAP INVALIDES ====="

for file in $FAIL_DIR/*
do
echo "----------------------------"
echo "Test (fail attendu) : $file"
$VALGRIND $EXEC "$file"
echo ""
done

echo "===== FIN DES TESTS ====="
