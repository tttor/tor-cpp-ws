# http://stackoverflow.com/questions/7757613/calling-matlab-from-c
# root directory of MATLAB installation
MATLABROOT="/home/tor/MATLAB/R2012a"

all: engdemo

engdemo:
		g++ ./engdemo_tor.cpp -o engdemo \
				-I${MATLABROOT}/extern/include \
				-L${MATLABROOT}/bin/glnxa64 -leng -lmat -lmx -lut -lmwresource_core -lmwi18n -lmwfl -lmwMATLAB_res -lboost_date_time -lboost_system -lboost_thread -licudata -licuuc -licui18n -licuio -lboost_filesystem -lboost_regex -lboost_signals

clean:
		rm -f engdemo *.o
