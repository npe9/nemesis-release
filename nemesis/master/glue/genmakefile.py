# nemmaster genmakefile
#
# Copyright 1998 Dickon Reed
#
# Generate a makefile for a build item

import buildutils, string, sys, gendetails
from nemclasses import *
import treeinfo
import blueprint

MakefileClassNotSupported = "MakefileClassNotSupported"
RequireClassNotSupported = "RequireClassNotSupported"
RequireClassNotFoundd = "RequireClassNotFound"
buildkindmap = {
    'posixprogram' : 'PROGRAM',
    'program' : 'PROGRAM',
    'module' : 'MODULE'
}
BrokenRequirement = "BrokenRequirement"

def genmakefile(item):
    path = item.get_path()
    if not path:
	return
    if item.get_make_flag('custom'):
	return
    cl = item.get_class()

    if cl == 'ntsc' or cl == 'primal' or not cl:
	sys.stderr.write('For item '+item.get_path()+', cannot handle class '+`item.get_class()`+'\n')
	raise MakefileClassNotSupported,cl
    pathsplit = string.split(path, '/')
    rootrelpath = string.join(['..']* len(pathsplit), '/')
    str = """
######################################################################
#                                                                    #
# Makefile autogenerated by glue/genmakefile.py                      #
#                                                                    #
######################################################################

"""
    str = str + '# '+gendetails.gendetails() + '\n'
    str = str + '# directory '+path+'\n\n'
    str = str + '# build item name '+item.get_name()+'\n\n'
    str = str + 'ROOT = ' + rootrelpath + '\n'
    if buildkindmap.has_key(cl):
	str = str + 'CFILES = $(wildcard *.c)\n'
	str = str + 'ASFILES = $(wildcard *.S)\n'
    if cl == 'posixprogram':
	str = str + 'PERSONALITY_LIBS = $(ROOT)/lib/static/posix/libposix.a\n'
    if item.get_make_flag('libdebug'):
	str = str + """
EXTRA_LIBS	+= $(ROOT)/lib/static/debug/libdebug.a
"""
    if item.get_make_flag('libio'):
	str = str + """
EXTRA_LIBS      += $(ROOT)/lib/static/io/libio.a
"""
    if item.get_make_flag('libmesa'):
	str = str + """
LOCAL_INC = -I $(ROOT)/lib/static/mesa/include
EXTRA_LIBS += $(ROOT)/lib/static/mesa/libmesa.a
"""

    if item.get_make_flag('modmesa'):
	str = str + """
LOCAL_INC = -I $(ROOT)/mod/ws/mesa/include
LOCAL_DEF = -DMESA_AS
"""

    if item.get_make_flag('libsocket'):
	str = str + """
EXTRA_LIBS += $(ROOT)/lib/static/socket/libsocket.a
"""
    if item.get_make_flag('libsunrpc'):
	str = str + """
LOCAL_INC	= -I$(ROOT)/lib/static/sunrpc/h
EXTRA_LIBS += $(ROOT)/lib/static/sunrpc/librpc.a
"""
    ######################################################################
    # bonus bits and pieces
    if item.get_make_flag('includedate'):
	str = str + """
LOCAL_OBJS 	= date.gen.o
"""
    # the bin producing line itself
    if buildkindmap.has_key(cl):
	str = str + buildkindmap[cl] + ' = '+item.get_binary_object_name() + '\n\n'

    ######################################################################
    # generate subdirs stuff
    str = str + 'include $(ROOT)/mk/autoconf.mk\n'
    subdirsmap = item.get_subdirs()
    subdirslist = subdirsmap.keys()
    subdirslist.sort()
    for subdir in subdirslist:
	#print path,'has subdirectory',subdir
	subitem = subdirsmap[subdir]
	requires = subitem.options['requires']

	count = 0
        try:
            for require in requires + [subitem.name]:
                if type(require) == type((1,2)):
                    if not blueprint.db.has_key(require[0]):
                        sys.stderr.write('Requirement %s of item %s is not in the database\n'% (require[0], item.name))
                        sys.exit(1)
                    subitem = blueprint.db[require[0]]

                    tail = '_'+subitem.options['type'][require[1]][2]
                else:
                    if not blueprint.db.has_key(require):
                        str = str + '# subdir %s for item %s is not available because requirement %s is missing\n' % (subdir, item.name, require)
                        raise BrokenRequirement
                    subitem = blueprint.db[require]

                    tail = ''
                if subitem.options.has_key('type'):
                    if subitem.options['type'] == 'quad':
                        tail = tail + '_BUILD'
                if subitem.options.has_key('associated_cpp_name'):
                    assoc = subitem.options['associated_cpp_name']
                    str = str + 'ifdef CONFIG_'+assoc+tail+'\n'
                    count = count + 1
                else:
                    str = str + '# also requires build item '+`require`+' but that option is not configurable\n'

            str = str + 'SUBDIRS += '+subdir+'\n'
            for i in range(0,count):
                str = str + 'endif\n'
        except BrokenRequirement:
            pass

    ######################################################################
    # including of other make files
    if item.get_make_flag('localrules'):
	str = str + 'include $(ROOT)/mk/local.rules.mk\n'

    str = str + 'include $(ROOT)/mk/rules.mk\n'

    ######################################################################
    # autogeneration stuff
    if item.get_make_flag('includedate'):
	str = str + """
date.gen.o: FRC
	echo "const char * const cline_date = \\"`date`\\";" > date.gen.c
	$(CC) -c date.gen.c
	$(RM) date.gen.c
"""
    ######################################################################
    # Installation stuff
    if item.get_make_flag('donotinstall'):
	str = str + 'INSTALLNAME = donotinstall\n'
    if item.get_make_flag('install'):
	l = item.get_make_flag('install')
	for installitem in l:
	    str = str + 'ifdef INSTDIR\n'
	    str = str + '  install::\n\tcp -f '+installitem+' $(INSTDIR)\n\n'
	    str = str + '  installmost:: $(INSTDIR)/'+installitem+'\n\n'
	    str = str + '  $(INSTDIR)/'+installitem+': '+installitem+'\n\tcp -f '+installitem+' $(INSTDIR)\n'
	    str = str + 'endif\n'

    
    ######################################################################
    # possibly write out the makefile
    
    buildutils.generate(treeinfo.build_tree_dir+ '/' +path + '/Makefile', str)

    # succeeded
    return 1




