#!/bin/ksh
#
#
# SCRIPT	:	label.sh
# PURPOSE	:	Saving current versions of file with the timestamp extention in src and include directories of the project
#
##############################################################################

TIMESTAMP=$(date +"%m%d%H%M")

PROJECT_DIR=/home/balex02/projects/c++/flowControl

SRC_DIR=${PROJECT_DIR}/src
INC_DIR=${PROJECT_DIR}/include
VC_DIR=${PROJECT_DIR}/vc

# create a verion of source files 
ls ${SRC_DIR} | while read filename
do

	cp ${SRC_DIR}/$filename ${VC_DIR}/$filename.${TIMESTAMP}
done

# create a verion of header files
ls ${INC_DIR} | while read filename
do

        cp ${INC_DIR}/$filename ${VC_DIR}/$filename.${TIMESTAMP}
done


#create a version of makefile

cp ${PROJECT_DIR}/makefile ${VC_DIR}/makefile.${TIMESTAMP}

#create a version of doc file
cp ${PROJECT_DIR}/doc/flowControl.doc  ${VC_DIR}/flowControl.doc.${TIMESTAMP}



#Change permissions 
chmod 400 ${VC_DIR}/*

echo "Files saved with label ${TIMESTAMP}"
