import os
import sys
import time
from ColorPrint import *

#
# Env and folders
#

#
# 1. log=0~5, for eventlog output, Ref: ./framework/SConscript
#        0, Debug; 1, Info; 2, Status; 3, Warning; 4, Warning; 5, Exception; 
# 2. opt=0, default: 2
# 3. nowarn=0, don't show warning when compiling
#
SconsTitle= 'Scons Help:'
SconsHelp = '    1. log=0~5, for eventlog output\n' + \
            '        0, Debug; \n' + \
            '        1, Info; \n' + \
            '        2, Status; \n' + \
            '        3, Warning; \n' + \
            '        4, Warning; (default)\n' + \
            '        5, Exception \n' + \
            '    2. opt=0, optimize, default: 0 \n' + \
            '    3. nowarn=0, disable warning \n'
            
ColorPrint(SconsTitle, nFont_Underline, nFore_Red, nBack_DefaultBack); 
ColorPrint(SconsHelp, nFont_Shine, nFore_Blue, nBack_DefaultBack); 

BinTitle =  'Bin Help:'
BinHelp  =  '    -t unittest     run unit test\n' + \
            '    -i interface    The interface(s) to bind to\n' + \
            '    -? help         Show help file\n' + \
            'e.g: \n' + \
            '    Build/bin/test -t -i 0 \n' + \
            '    OR \n' + \
            '    Build/bin/test -i 0 -t 1 \n'
            
ColorPrint(BinTitle, nFont_Underline, nFore_Red, nBack_DefaultBack); 
ColorPrint(BinHelp, nFont_Shine, nFore_Blue, nBack_DefaultBack); 

# import environment
env = Environment(ENV = os.environ)

# get current path
rootdir = os.getcwd()

buildroot = os.path.join(rootdir, 'Build')
buildbin = os.path.join(buildroot, 'bin')
buildlibs = os.path.join(buildroot, 'libs')

print 'buildroot : ' + buildroot
print 'buildbin : ' + buildbin
print 'buildlibs : ' + buildlibs

# cc_common
if ARGUMENTS.has_key('opt'):
    cc_common = ['-g', '-fno-omit-frame-pointer']
    cc_common.append('-O'+ARGUMENTS.get('opt'))
else:
    cc_common = ['-g', '-fno-omit-frame-pointer']
#    cc_common.append('-O2')
    cc_common.append('-O0')

#warn
if not ARGUMENTS.has_key('nowarn'):
	cc_common.append('-Wall')

# Endian
if sys.byteorder == "little":
    print 'Little endian'
    cc_common.append('-D__LITTLE_ENDIAN__')
else:
    print 'Big endian'
    cc_common.append('-D__BIG_ENDIAN__')

# 32-bits and 64-bits
if sys.maxint >> 33:
    print '64bits'
    cc_common.append('-D__x86_64__')
    cc_common.append('-m64')
else:
    print '32bits'
    cc_common.append('-m32')

env.Append(CCFLAGS = cc_common)
env.Append(CXXFLAGS = cc_common)


#
#
# Compiler
# 

env.Append(CCFLAGS = ['-O0', '-Wall', '-g'])

# add include path
env['CPPPATH'] = [ '.',
                   '#',
                   '#/vendor/xerces/xerces/include/',
                   '#/framework/src',
                   '#/network/src',
                   '#/pcap/src',
                   '#/framework/src/action',
                   '#/testpoint/src',
                   '#/main/src',
                 ]

# compile folder
targets = [
    'framework/src',
    'network/src',
    'pcap/src',
    'pcap/unit',
    'framework/src/action',
    'testpoint/src',
    'main/src'
]

# all libraries
# please be carful the order of the libraries, the basic or framework library 
#  should be behind of others.
env['LIBPATH'] = [
    buildlibs,
    '#/lib',
]

env['MainLibraries'] = [
    'testpoint',
    'frameworkaction',
    'pcap',
    'network',
    'framework',
    'xerces',
 ]

for tgt in targets:
#    print '\n'
    builddir = os.path.join(buildroot, tgt)
    script = os.path.join(builddir, 'SConscript')
#    print 'tgt : ' + tgt
#    print 'builddir : ' + builddir
#    print 'script : ' + script

    config = {}
    config['buildlibs'] = buildlibs
    config['buildbin'] = buildbin
#    print "config['buildlibs']   = "  +  config['buildlibs']
#    print "config['buildbin']   = "  +  config['buildbin']

    #export 
    Export('env config')
    BuildDir(builddir, tgt, duplicate=0)
    SConscript(script)



