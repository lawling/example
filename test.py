#!/usr/bin/python
import subprocess

for i in range(1,10):
	subprocess.call(['./public%02d.x'%i])

