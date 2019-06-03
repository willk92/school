#!/bin/bash
# William Kelley
# Search Contents of /var/log/auth.log for root logins(uid=0)
# ITE315-Scripting

grep -w "root" /var/log/auth.log | grep -w "opened"
