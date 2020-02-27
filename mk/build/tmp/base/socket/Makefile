#! /usr/bin/make -f

################################################################################
# Copyright (C) 2020	Alejandro Colomar Andrés
# SPDX-License-Identifier:	LGPL-2.0-only
################################################################################
# *AUTHOR*
# FULL NAME	"Alejandro Colomar Andrés"
# EMAIL		"1903716@gmail.com"
################################################################################

################################################################################
# dependencies

OBJ	=								\
	$(CURDIR)/tcp/client.o						\
	$(CURDIR)/tcp/server.o

SRC	=								\
	$(SRC_DIR)/base/socket/tcp/client.c				\
	$(SRC_DIR)/base/socket/tcp/server.c

DEP		= $(OBJ:.o=.d)
BOTH_OBJ	= $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))
BOTH_ASM	= $(subst .a.s,.a.s ,$(join $(OBJ:.o=.a.s),$(OBJ:.o=.so.s)))
NEEDDIR		= $(DEP) $(BOTH_ASM)

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(BOTH_OBJ)
	@:

$(CURDIR)/tcp: $(CURDIR)/%:
	@echo	"	MKDIR	build/tmp/base/socket/$*"
	$(Q)mkdir -p		$(CURDIR)/$*

$(NEEDDIR): $(CURDIR)/tcp/%: | $(CURDIR)/tcp

$(CURDIR)/%.d: $(SRC_DIR)/base/socket/%.c
#	$(Q)mkdir -p		$(@D)/
	@echo	"	CC -M	build/tmp/base/socket/$*.d"
	$(Q)$(CC) $(CFLAGS_A) -MG -MT"$@"				\
			-MT"$(CURDIR)/$*.a.s" -MT"$(CURDIR)/$*.so.s"	\
			-M $< -MF $@
$(CURDIR)/%.a.s: $(SRC_DIR)/base/socket/%.c $(CURDIR)/%.d
#	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/base/socket/$*.a.s"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
$(CURDIR)/%.so.s: $(SRC_DIR)/base/socket/%.c $(CURDIR)/%.d
#	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/base/socket/$*.so.s"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
$(CURDIR)/%.o: $(CURDIR)/%.s
	@echo	"	AS	build/tmp/base/socket/$*.o"
	$(Q)$(AS) $< -o $@

include $(DEP)


PHONY += clean
clean:
	$(Q)rm -rf *.o *.s

################################################################################
# Declare the contents of the PHONY variable as phony.
.PHONY: $(PHONY)


################################################################################
######## End of file ###########################################################
################################################################################
