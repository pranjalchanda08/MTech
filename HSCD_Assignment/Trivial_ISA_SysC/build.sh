export SYSTEMC_HOME=/usr/local/systemc-2.3.1
g++ -Icomponents\
    -Icomponents/instruction_register\
    -Icomponents/pipeline_decoder\
    -Icomponents/program_counter\
    -Icomponents/ram\
    -Icomponents/reg_bank\
    -Icomponents/ula\
    -Isrc\
    -I$SYSTEMC_HOME/include -L. \
    -L$SYSTEMC_HOME/lib-linux64 -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 \
    -lsystemc -lm -o sysc_trial\
    src/processor.cpp \
    src/processor_run.cpp \
    components/ula/ula.h \
    components/reg_bank/reg_bank.cpp \
    components/ram/ram.cpp \
    components/program_counter/program_counter.cpp \
    components/pipeline_decoder/pipeline_dec.cpp \
    components/instruction_register/instruction_register.cpp