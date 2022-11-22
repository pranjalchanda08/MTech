export SYSTEMC_HOME=/usr/local/systemc-2.3.1
g++ -Iinc\
    -I$SYSTEMC_HOME/include -L. \
    -L$SYSTEMC_HOME/lib-linux64 -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 \
    -lsystemc -lm -g -o bin/trivial_proc\
    src/processor.cpp\
    src/processor_run.cpp