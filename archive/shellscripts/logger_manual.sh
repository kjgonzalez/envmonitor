#!/bin/bash
. /home/pib/envmonitor/venv/bin/activate
python ~/envmonitor/run_log.py --p $1 # required to be given by user
