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
		lines.o							\
		max.o							\
		mean.o							\
		median.o						\
		skeleton.o


LINES_INC	=							\
		$(INC_DIR)/libalx/extra/cv/alx/lines.hpp
LINES_SRC	=							\
		$(SRC_DIR)/extra/cv/alx/lines.cpp

MAX_INC		=							\
		$(INC_DIR)/libalx/base/compiler/restrict.hpp		\
		$(INC_DIR)/libalx/base/compiler/size.hpp		\
		$(INC_DIR)/libalx/extra/cv/alx/max.hpp
MAX_SRC		=							\
		$(SRC_DIR)/extra/cv/alx/max.cpp

MEAN_INC	=							\
		$(INC_DIR)/libalx/extra/gsl/statistics/mean.hpp		\
		$(INC_DIR)/libalx/extra/cv/alx/mean.hpp
MEAN_SRC	=							\
		$(SRC_DIR)/extra/cv/alx/mean.cpp

MEDIAN_INC	=							\
		$(INC_DIR)/libalx/extra/gsl/rstat/median.hpp		\
		$(INC_DIR)/libalx/extra/cv/alx/median.hpp
MEDIAN_SRC	=							\
		$(SRC_DIR)/extra/cv/alx/median.cpp

SKELETON_INC	=							\
		$(INC_DIR)/libalx/base/compiler/size.hpp		\
		$(INC_DIR)/libalx/extra/cv/alx/skeleton.hpp
SKELETON_SRC	=							\
		$(SRC_DIR)/extra/cv/alx/skeleton.cpp

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
	@echo	"	CXX	build/tmp/extra/cv/alx/$@"
	$(Q)$(CC) $(CXXFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CXX	build/tmp/extra/cv/alx/$@"
	$(Q)$(CC) $(CXXFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	build/tmp/extra/cv/alx/$@"
	$(Q)$(AS) $< -o $@


lines.a.s: $(LINES_SRC) $(LINES_INC)
lines.so.s: $(LINES_SRC) $(LINES_INC)

max.a.s: $(MAX_SRC) $(MAX_INC)
max.so.s: $(MAX_SRC) $(MAX_INC)

mean.a.s: $(MEAN_SRC) $(MEAN_INC)
mean.so.s: $(MEAN_SRC) $(MEAN_INC)

median.a.s: $(MEDIAN_SRC) $(MEDIAN_INC)
median.so.s: $(MEDIAN_SRC) $(MEDIAN_INC)

skeleton.a.s: $(SKELETON_SRC) $(SKELETON_INC)
skeleton.so.s: $(SKELETON_SRC) $(SKELETON_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
