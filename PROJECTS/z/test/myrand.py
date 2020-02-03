from random import randint
from random import choice
from random import shuffle

LOWER = 'abcdefghijklmnopqrstuvwxyz'
LOWER_NUM = 'abcdefghijklmnopqrstuvwxyz0123456789'
ALPHA_NUM = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'

#############################################################################

def rand_str(max_l, choices=LOWER):
	n = randint(1, max_l)
	ans = ''
	
	for i in xrange(n):
		ans += choice(choices)
		
	return ans

#############################################################################		

# Arreglar

def rand_tree(cant_nodes):
	ans = [0] * cant_nodes
	
	for i in xrange(1, cant_nodes):
		ans[i] = randint(0, i-1)
		
	for i in xrange(len(ans)):
		ans[i] = ans[i] + 1
	ans[0] = 0	
	
	return ans 
	
#############################################################################

