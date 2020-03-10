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
	$(CURDIR)/gray.o						\
	$(CURDIR)/lines.o						\
	$(CURDIR)/max.o							\
	$(CURDIR)/mean.o						\
	$(CURDIR)/median.o						\
	$(CURDIR)/skeleton.o

SRC	=								\
	$(SRC_DIR)/extra/cv/alx/gray.cpp				\
	$(SRC_DIR)/extra/cv/alx/lines.cpp				\
	$(SRC_DIR)/extra/cv/alx/max.cpp					\
	$(SRC_DIR)/extra/cv/alx/mean.cpp				\
	$(SRC_DIR)/extra/cv/alx/median.cpp				\
	$(SRC_DIR)/extra/cv/alx/skeleton.cpp

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


$(CURDIR)/%.d: $(SRC_DIR)/extra/cv/alx/%.cpp
	$(Q)mkdir -p		$(@D)/
	@echo	"	CXX -M	build/tmp/extra/cv/alx/$*.d"
	$(Q)$(CXX) $(CXXFLAGS_A) -MG -MT"$@"				\
			-MT"$(CURDIR)/$*.a.s" -MT"$(CURDIR)/$*.so.s"	\
			-M $< -MF $@
$(CURDIR)/%.a.s: $(SRC_DIR)/extra/cv/alx/%.cpp $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CXX	build/tmp/extra/cv/alx/$*.a.s"
	$(Q)$(CXX) $(CXXFLAGS_A) -S $< -o $@
$(CURDIR)/%.so.s: $(SRC_DIR)/extra/cv/alx/%.cpp $(CURDIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CXX	build/tmp/extra/cv/alx/$*.so.s"
	$(Q)$(CXX) $(CXXFLAGS_SO) -S $< -o $@
$(CURDIR)/%.o: $(CURDIR)/%.s
	@echo	"	AS	build/tmp/extra/cv/alx/$*.o"
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
