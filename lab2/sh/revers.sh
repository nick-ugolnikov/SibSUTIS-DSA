#!/bin/sh

# Использование: reverse.sh <text-file>

INFILE=$1

#
# Выводим файл $INFILE | перемешиваем строки
cat $INFILE | sort -r
