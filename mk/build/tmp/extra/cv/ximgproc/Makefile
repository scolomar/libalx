#! /usr/bin/make -f

################################################################################
# Copyright (C) 2019	Alejandro Colomar Andrés
# SPDX-License-Identifier:	LGPL-2.0-only
################################################################################
# *AUTHOR*
# FULL NAME	"Alejandro Colomar Andrés"
# EMAIL		"1903716@gmail.com"
################################################################################

################################################################################
# dependencies
OBJ		=							\
		thinning.o


THINNING_INC	=							\
		$(INC_DIR)/libalx/extra/cv/ximgproc/thinning.hpp
THINNING_SRC	=							\
		$(SRC_DIR)/extra/cv/ximgproc/thinning.cpp

################################################################################
# cflags
CXXFLAGS_A	+= `pkg-config --cflags opencv4`
CXXFLAGS_SO	+= `pkg-config --cflags opencv4`

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CXX	build/tmp/extra/cv/ximgproc/$@"
	$(Q)$(CC) $(CXXFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CXX	build/tmp/extra/cv/ximgproc/$@"
	$(Q)$(CC) $(CXXFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	build/tmp/extra/cv/ximgproc/$@"
	$(Q)$(AS) $< -o $@


thinning.a.s: $(THINNING_SRC) $(THINNING_INC)
thinning.so.s: $(THINNING_SRC) $(THINNING_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
