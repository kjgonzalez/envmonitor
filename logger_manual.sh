#!/bin/bash
. /home/pib/programs/temp_humidity/venv/bin/activate
python ~/programs/temp_humidity/run_log.py --p $1 # required to be given by user
