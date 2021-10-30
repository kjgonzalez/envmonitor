#!/bin/bash
# this file sets up the repository after it's been downloaded. 
# RUN IT FROM THE TOP-LEVEL FOLDER OF THIS REPO
python -m venv venv/
. venv/bin/activate
python -m pip install -r setup/requirements.txt
echo "done"
