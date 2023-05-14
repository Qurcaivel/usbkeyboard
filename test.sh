#!/usr/bin/env bash

if [ `id -u` -ne 0 ]; then
    echo "You must be a superuser to run this script"
    exit 1
fi

if [[ $# != 1 ]]; then
    echo "usage: ${0} <timeout>"
    exit 1
fi

regex="^[0-9]+$"

if ! [[ "${1}" =~ $regex ]] ; then
   echo "<timeout> must be a positive integer"
   exit 1
fi

./setup.sh; sleep ${1}; ./restore.sh