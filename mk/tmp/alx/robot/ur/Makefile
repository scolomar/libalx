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

MK_DEPS	=								\
	$(MK_TMP_DIR)/alx/robot/ur/Makefile				\
	$(MK_TMP_DIR)/Makefile						\
	$(LIBALX_DIR)/Makefile

MODULES	=								\
	alx/robot/ur/core						\
	alx/robot/ur/io							\
	alx/robot/ur/miscellaneous					\
	alx/robot/ur/move						\
	alx/robot/ur/pose						\
	alx/robot/ur/setup

SRC	= $(MODULES:%=$(SRC_DIR)/%.c)
OBJ	= $(MODULES:%=$(BUILD_TMP_DIR)/%.o)

DEP		= $(OBJ:.o=.d)
BOTH_OBJ	= $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(BOTH_OBJ)
	@:


$(BUILD_TMP_DIR)/%.d: $(SRC_DIR)/%.c $(MK_DEPS)
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC -M	build/tmp/$*.d"
	$(Q)$(CC) $(CFLAGS_A) -MG -MT"$@"				\
			-MT"$(BUILD_TMP_DIR)/$*.a.s"			\
			-MT"$(BUILD_TMP_DIR)/$*.so.s"			\
			-M $< -MF $@
$(BUILD_TMP_DIR)/%.a.s: $(SRC_DIR)/%.c $(BUILD_TMP_DIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/$*.a.s"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
$(BUILD_TMP_DIR)/%.so.s: $(SRC_DIR)/%.c $(BUILD_TMP_DIR)/%.d
	$(Q)mkdir -p		$(@D)/
	@echo	"	CC	build/tmp/$*.so.s"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
$(BUILD_TMP_DIR)/%.o: $(BUILD_TMP_DIR)/%.s
	@echo	"	AS	build/tmp/$*.o"
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

