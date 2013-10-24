# http://stackoverflow.com/questions/7757613/calling-matlab-from-c
# root directory of MATLAB installation
MATLABROOT="/usr/local/matlab/R2009b"

all: engdemo

engdemo:
		g++ ~/tor-cpp-ws/matlab_eng/engdemo.cpp -o engdemo \
				-I${MATLABROOT}/extern/include \
				-L${MATLABROOT}/bin/glnxa64 -leng -lmat -lmx -lut -lmwfl -lboost_date_time -licudata -licuuc -licui18n -licuio -lboost_filesystem -lboost_regex -lhdf5_hl -lhdf5 -lboost_thread-gcc42-mt-1_36 -lboost_signals-gcc42-mt-1_36 -lboost_system-gcc42-mt-1_36

clean:
		rm -f engdemo *.o
