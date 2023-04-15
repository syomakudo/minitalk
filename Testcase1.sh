#!/bin/bash

SERVER_PID=`ps | grep "./server" | grep -v "grep" | awk '{print$1}'`
MSG=`python3 -c "print('${1}' * ${2})"`

./client ${SERVER_PID} ${MSG}