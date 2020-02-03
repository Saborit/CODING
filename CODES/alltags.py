import os, sys

tags = {}
textexts = ['py', 'pyw', 'txt', 'c', 'h', 'cpp', 'htm', 'java', 'cc', 'html']

count = 0

#################################################################################################################

def add_tags(line):
	global tags
	
	line = line[:-1]
	
	#~ print line
	
	for c in line:
		if not ('a' <= c <= 'z' or c == '_' or c == ' ' or c == '*'):
			return

	strings = line.split(' ')
	#~ print strings
	for st in strings:
		if st.find('*') == -1 and st != '':
			tags[st] = 0

#################################################################################################################

def parse_file(fpath):
	#~ print fpath
	try:
		f = open(fpath, 'r')
		
		line = 'line'
		c = 0
		while True:
			line = f.readline()
			if line == '': 
				break
			elif c==0 and not '/*' in line:
				break
			elif '*/' in line:
				break
			elif c == 2:
				add_tags(line);    
			c+=1 
	finally:
				f.close()
	
#################################################################################################################

def searcher(startdir):
	for (thisDir, dirsHere, filesHere) in os.walk(startdir):
		for fname in filesHere:                                
			fpath = os.path.join(thisDir, fname) 
			visitfile(fpath)

#################################################################################################################

def visitfile(fpath):                                
	global count 
	try:
		if (fpath.split('.')[-1]) in textexts:
			parse_file(fpath)
			count += 1
	except:
			print 'Error at ' + fpath

#################################################################################################################

searcher(sys.argv[1])

ans = tags.keys()
ans.sort()

for i in ans:
	print i

print 'C++ Files: ' + str(count)
