#!/bin/sh
cgdb --args ./emmaus --docroot ".;/doc/html,/resources" --approot .  --http-address=0.0.0.0 --http-port=8000 -c emmaus.xml
