import sys
import glob
import ctypes

argvs = sys.argv
argc = len(argvs)
if (argc != 2):
    print 'Usage: # python %s filename' % argvs[0]
    sys.exit()
lib = ctypes.CDLL('../test/CrossStripesCameraSensor/libcscsensor.dylib')
lib.imageprocessing(ctypes.c_char_p("a"), ctypes.c_char_p("b"))
