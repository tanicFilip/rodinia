SHELL=/bin/sh -ue

CFLAGS   += -O0 #-floop-interchange -floop-unroll-and-jam -fpeel-loops -ftree-loop-distribution
CXXFLAGS += -O0	#-floop-interchange -floop-unroll-and-jam -fpeel-loops -ftree-loop-distribution

ifdef OUTPUT
CPPFLAGS += -DOUTPUT
endif

ifdef DEBUG
CFLAGS   += -g
CXXFLAGS += -g
endif

# include Make.user relative to every active Makefile, exactly once
MAKEFILE_DIRS = $(foreach MAKEFILE,$(realpath $(MAKEFILE_LIST)), $(shell dirname $(MAKEFILE)))
$(foreach DIR,$(sort $(MAKEFILE_DIRS)),\
	$(eval -include $(DIR)/Make.user)\
)
