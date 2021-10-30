#!/bin/bash
# . /home/$USER/envmonitor/venv/bin/activate
. ~/envmonitor/venv/bin/activate
python ~/envmonitor/uptime.py --period 1800 # default is every 30 minutes

