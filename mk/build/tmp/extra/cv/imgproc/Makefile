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
	$(CURDIR)/features.o						\
	$(CURDIR)/filter.o						\
	$(CURDIR)/geometric.o						\
	$(CURDIR)/histogram.o						\
	$(CURDIR)/miscellaneous.o					\
	$(CURDIR)/shape.o

SRC	=								\
	$(SRC_DIR)/extra/cv/imgproc/features.cpp			\
	$(SRC_DIR)/extra/cv/imgproc/filter.cpp				\
	$(SRC_DIR)/extra/cv/imgproc/geometric.cpp			\
	$(SRC_DIR)/extra/cv/imgproc/histogram.cpp			\
	$(SRC_DIR)/extra/cv/imgproc/miscellaneous.cpp			\
	$(SRC_DIR)/extra/cv/imgproc/shape.cpp

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
