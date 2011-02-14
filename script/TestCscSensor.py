import sys
import glob
import ctypes

argvs = sys.argv
argc = len(argvs)
print argvs
if (argc != 2):
    print 'Usage: # python %s filename' % argvs[0]
    sys.exit()
lib = ctypes.CDLL('../test/CrossStripesCameraSensor/libcscsensor.dylib')
files = glob.glob(argvs[1] + '/*.png')
counter = 0
for f in files:
    writename = 'Result/' + '%05d'%counter + '.png'
    lib.imageprocessing(ctypes.c_char_p(f), ctypes.c_char_p(writename))
    counter += 1
