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
		features.o						\
		filter.o						\
		geometric.o						\
		histogram.o						\
		miscellaneous.o						\
		shape.o


FEATURES_INC	=							\
		$(INC_DIR)/libalx/extra/cv/imgproc/features.hpp
FEATURES_SRC	=							\
		$(SRC_DIR)/extra/cv/imgproc/features.cpp

FILTER_INC	=							\
		$(INC_DIR)/libalx/extra/cv/imgproc/filter.hpp
FILTER_SRC	=							\
		$(SRC_DIR)/extra/cv/imgproc/filter.cpp

GEOMETRIC_INC	=							\
		$(INC_DIR)/libalx/base/compiler/restrict.hpp		\
		$(INC_DIR)/libalx/extra/cv/imgproc/geometric.hpp
GEOMETRIC_SRC	=							\
		$(SRC_DIR)/extra/cv/imgproc/geometric.cpp

HISTOGRAM_INC	=							\
		$(INC_DIR)/libalx/base/compiler/restrict.hpp		\
		$(INC_DIR)/libalx/extra/cv/imgproc/histogram.hpp
HISTOGRAM_SRC	=							\
		$(SRC_DIR)/extra/cv/imgproc/histogram.cpp

MISC_INC	=							\
		$(INC_DIR)/libalx/extra/cv/imgproc/miscellaneous.hpp
MISC_SRC	=							\
		$(SRC_DIR)/extra/cv/imgproc/miscellaneous.cpp

SHAPE_INC	=							\
		$(INC_DIR)/libalx/base/compiler/restrict.hpp		\
		$(INC_DIR)/libalx/extra/cv/imgproc/shape.hpp
SHAPE_SRC	=							\
		$(SRC_DIR)/extra/cv/imgproc/shape.cpp

################################################################################
# cflags
CXXFLAGS_A	+= `pkg-config --cflags opencv4`
CXXFLAGS_SO	+= `pkg-config --cflags opencv4`

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))
	@:


%.a.s:
	@echo	"	CXX	build/tmp/extra/cv/imgproc/$@"
	$(Q)$(CC) $(CXXFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CXX	build/tmp/extra/cv/imgproc/$@"
	$(Q)$(CC) $(CXXFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	build/tmp/extra/cv/imgproc/$@"
	$(Q)$(AS) $< -o $@


features.a.s: $(FEATURES_SRC) $(FEATURES_INC)
features.so.s: $(FEATURES_SRC) $(FEATURES_INC)

filter.a.s: $(FILTER_SRC) $(FILTER_INC)
filter.so.s: $(FILTER_SRC) $(FILTER_INC)

geometric.a.s: $(GEOMETRIC_SRC) $(GEOMETRIC_INC)
geometric.so.s: $(GEOMETRIC_SRC) $(GEOMETRIC_INC)

histogram.a.s: $(HISTOGRAM_SRC) $(HISTOGRAM_INC)
histogram.so.s: $(HISTOGRAM_SRC) $(HISTOGRAM_INC)

miscellaneous.a.s: $(MISC_SRC) $(MISC_INC)
miscellaneous.so.s: $(MISC_SRC) $(MISC_INC)

shape.a.s: $(SHAPE_SRC) $(SHAPE_INC)
shape.so.s: $(SHAPE_SRC) $(SHAPE_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
