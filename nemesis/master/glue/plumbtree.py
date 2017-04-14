#! /usr/bin/env python

# 
# nemmaster plumbtree
#
# (re)plumb a Nemesis build tree, based on the configuration database
#
# actions:
#
# use configutils to get hold of a confdb
#
# write mk/autoconf.mk
# write h/autoconf files
# (re)fill system interface repository

import sys,string, gendetails, marshal, os, posix
from treeinfo import build_tree_dir
import buildutils, configutils, blueprint, sourcemanager

def autoconf_stuff(option, item):
    optionu = string.upper(option)
    hstr = '/* automatically generated */\n'
    hstr = hstr + '/* '+gendetails.gendetails()+' */\n'
    mkstr = ''
    st = {}
    st['hstr'] = hstr
    st['mkstr'] = mkstr
    st['optionu'] = optionu
    def define( st, value, postfix = ''):
	if value:
	    st['hstr'] = st['hstr'] + '#define CONFIG_'+st['optionu']+postfix+' 1\n'
	    st['mkstr'] = st['mkstr'] + 'CONFIG_'+st['optionu']+postfix+'=y\n'
	else:
	    st['hstr'] = st['hstr'] + '#undef CONFIG_'+st['optionu']+postfix+'\n'
	    st['mkstr'] = st['mkstr'] + '#CONFIG_'+st['optionu']+postfix+' is undefined\n'
	    
    v = item.options['value']
    
    # v is now an integer

    index = 0
    t = item.options['type']

    if t == 'bool':
	if v:
	    define(st,1)
	else:
	    define(st,0)
    
    if t == 'quad':
	st['hstr'] = st['hstr'] + '#define CONFIG_'+st['optionu']+'_VALUE '+`v`+'\n'
	if v == 0:
	    define(st,0)
	else:
	    define(st,1)

	for i in range(1,4):
	    define(st, i<=v, '_'+['NONE', 'SUPPORT', 'BUILD', 'NBF'][i])
	
    if type(t) == type([]):
	st['hstr'] = st['hstr'] + '#define CONFIG_'+st['optionu']+'_VALUE '+`v`+'\n'
	for i in range(0, len(t)):
	    (valid, description, value) = t[i]
	    define(st, i == v, '_'+value)
    return (st['hstr'], st['mkstr'])

if not os.path.isdir(build_tree_dir+'/h/autoconf'):
    os.mkdir(build_tree_dir+'/h/autoconf')

ks = []
for item in blueprint.items:
    if item.options.has_key('associated_cpp_name'):
	ks.append( (item, item.options['associated_cpp_name']))
                
fullmkstr = '#autogenerated by '+gendetails.gendetails()+'\n'
for (item,configoption) in ks:
    try:
	(hstr, mkstr) = autoconf_stuff(configoption, item)
	fullmkstr = fullmkstr + mkstr
	buildutils.generate(build_tree_dir+'/h/autoconf/'+string.lower(configoption)+'.h', hstr)
    except KeyError:
	sys.stderr.write('Warning; no blueprint data for '+`configoption`+'\n')

for item in blueprint.items:
    if item.options.has_key('path'):
        if item.options.has_key('makevars'):
            for key in item['makevars'].keys():
                fullmkstr = fullmkstr + key+'_'+item.options['path']+'\t+= '+item['makevars'][key]+'\n'


o = open(build_tree_dir+'/mk/autoconf.mk.d', 'w')
o.write('$(wildcard $(ROOT)/h/autoconf/*.h) :  $(ROOT)/mk/autoconf.mk\n$(ROOT)/mk/autoconf.mk : '+string.join(blueprint.deps, ' ')+'\n\tPYTHONPATH=$(ROOT)/glue python $(ROOT)/glue/plumbtree.py')
o.close()
o = open(build_tree_dir+'/mk/autoconf.mk', 'w')
o.write(fullmkstr)
o.close()