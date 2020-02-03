"""

Finds Codes with Tags
Parameters: Start Directory, Search Key

"""

import os, sys
listonly = False
textexts = ['py', 'pyw', 'txt', 'c', 'h', 'cpp', 'htm', 'java', 'cc', 'html']  

#################################################################################################################

def parse_file(fpath, key):
   	try:
	   	f = open(fpath, 'r')
		
		line = 'line'
		c = 0
		
		while True:
			line = f.readline()
			if line == '': 
				break
			if c==0 and not '/*' in line:
				break
			if line.find(key) != -1:
				return True
			if '*/' in line:
				break	 
			c+=1 
		return False
	
		f.close()
	except:	
		f.close() 

#################################################################################################################

def searcher(startdir, searchkey):
    global fcount, vcount
    fcount = vcount = 0
    for (thisDir, dirsHere, filesHere) in os.walk(startdir):
         for fname in filesHere:                                
             fpath = os.path.join(thisDir, fname) 
             visitfile(fpath, searchkey)

#################################################################################################################
             
def visitfile(fpath, searchkey):                                
     try:
		 if (fpath.split('.')[-1]) in textexts:
			 if parse_file(fpath, searchkey):
				 Results.append(fpath)     
     except:
		 print 'Error at ' + fpath

#################################################################################################################

if __name__ == '__main__':
	
   Results = []	
   
   for i in xrange(2, len(sys.argv)):
	   searcher(sys.argv[1], sys.argv[i])
   
   for i in xrange(len(Results)):
	   print str(i+1) + ' --> ' + Results[i].split('/')[-1]
   
   while True:
	   _id = int(raw_input('Index: '))
	   
	   if _id < 1 or _id > len(Results): 
		   print 'Exiting...'
		   break
		   
	   result = ''
	   
	   for c in Results[_id-1]:
		   if c == ' ':
			 result += '\\'
		   
		   result += c
		   	   
	   os.system('geany ' + result + ' &')    
	   