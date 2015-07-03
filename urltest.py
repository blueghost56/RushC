#!/usr/bin/env python
import sys,urllib2

req=urllib2.Request(sys.args[0])
fd=urllib2.urlopen(req)
info=fd.info()
for key,value in info:
	print "%s=%s" % (key,value)
