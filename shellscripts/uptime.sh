#!/bin/bash
. /home/pib/programs/envmonitor/venv/bin/activate
python ~/programs/envmonitor/run_log.py --p $1 # required to be given by user
