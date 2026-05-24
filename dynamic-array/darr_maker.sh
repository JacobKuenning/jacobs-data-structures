#! usr/sbin/bash
# This is a shell script for copying the DATATYPE_darr header and source files, replacing the placeholder DATATYPE with your own
# USAGE: bash darr_maker.sh DATATYPE
# This can also be used to create a dynamic array for a builtin type, but you have to remove the struct forward declaration in the header file

DATATYPE=$1

cp DATATYPE_darr.c $DATATYPE"_darr.c"
cp DATATYPE_darr.h $DATATYPE"_darr.h"

sed -i "s/DATATYPE/$DATATYPE/g" $DATATYPE"_darr.c"
sed -i "s/DATATYPE/$DATATYPE/g" $DATATYPE"_darr.h"
