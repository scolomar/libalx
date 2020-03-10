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
OBJ	=								\
	$(CURDIR)/features/features.o					\
	$(CURDIR)/filter/filter.o					\
	$(CURDIR)/geometric/geom.o					\
	$(CURDIR)/histogram/hist.o					\
	$(CURDIR)/miscellaneous/misc.o					\
	$(CURDIR)/miscellaneous/threshold.o				\
	$(CURDIR)/shape/contours.o					\
	$(CURDIR)/shape/rect.o

SRC	=								\
	$(SRC_DIR)/extra/cv/imgproc/features/features.cpp		\
	$(SRC_DIR)/extra/cv/imgproc/filter/filter.cpp			\
	$(SRC_DIR)/extra/cv/imgproc/geometric/geom.cpp			\
	$(SRC_DIR)/extra/cv/imgproc/histogram/hist.cpp			\
	$(SRC_DIR)/extra/cv/imgproc/miscellaneous/misc.cpp		\
	$(SRC_DIR)/extra/cv/imgproc/miscellaneous/threshold.cpp		\
	$(SRC_DIR)/extra/cv/imgproc/shape/contours.cpp			\
	$(SRC_DIR)/extra/cv/imgproc/shape/rect.cpp

DEP		= $(OBJ:.o=.d)
BOTH_OBJ	= $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))

################################################################################
# cflags
CXXFLAGS_A	+= `pkg-config --cflags opencv4`
CXXFLAGS_SO	+= `pkg-config --cflags opencv4`

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(BOTH_OBJ)
	@:


$(CURDIR)/%.d: $(SRC_DIR)/extra/cv/imgproc/%.cpp
	$(Q)mkdir -p		$(@D)/
	@echo	"	CXX -M	build/tmp/extra/cv/imgproc/$*.d"
	$(Q)$(CXX) $(CXXFLAGS_A) -MG -MT"$@"				\
			-MT"$(CURDIR)/$*.a.s" -MT"$(CURDIR)/$*.so.s"	\
			-M $< -MF $@
$(CURDIR)/%.a.s: $(SRC_DIR)/extra/cv/imgproc/%.cpp $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CXX	build/tmp/extra/cv/imgproc/$*.a.s"
	$(Q)$(CXX) $(CXXFLAGS_A) -S $< -o $@
$(CURDIR)/%.so.s: $(SRC_DIR)/extra/cv/imgproc/%.cpp $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CXX	build/tmp/extra/cv/imgproc/$*.so.s"
	$(Q)$(CXX) $(CXXFLAGS_SO) -S $< -o $@
$(CURDIR)/%.o: $(CURDIR)/%.s
	@echo	"	AS	build/tmp/extra/cv/imgproc/$*.o"
	$(Q)$(AS) $< -o $@

include $(DEP)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)


################################################################################
######## End of file ###########################################################
################################################################################
