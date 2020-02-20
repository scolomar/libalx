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
OBJ		=							\
		ur.o

UR_INC		=							\
		$(INC_DIR)/libalx/base/socket/tcp/client.h		\
		$(INC_DIR)/libalx/base/stdlib/alloc/callocs.h		\
		$(INC_DIR)/libalx/base/stdlib/alloc/frees.h		\
		$(INC_DIR)/libalx/alx/robot/ur.h
UR_SRC		=							\
		$(SRC_DIR)/alx/robot/ur.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


%.a.s:
	@echo	"	CC	build/tmp/alx/robot/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	build/tmp/alx/robot/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	build/tmp/alx/robot/$@"
	$(Q)$(AS) $< -o $@


ur.a.s: $(UR_SRC) $(UR_INC)
ur.so.s: $(UR_SRC) $(UR_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
