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

DIRS		=							\
		kawasaki						\
		ur

OBJ		=							\
		ur/ur.o
#		kawasaki/kawasaki.o

KW_KW_INC	=							\
		$(INC_DIR)/libalx/base/stdlib/alloc/callocs.h		\
		$(INC_DIR)/libalx/base/stdlib/alloc/frees.h		\
		$(INC_DIR)/libalx/alx/robot/kawasaki/kawasaki.h
KW_KW_SRC	=							\
		$(SRC_DIR)/alx/robot/kawasaki/kawasaki.c

UR_UR_INC	=							\
		$(INC_DIR)/libalx/base/socket/tcp/client.h		\
		$(INC_DIR)/libalx/base/stdlib/alloc/callocs.h		\
		$(INC_DIR)/libalx/base/stdlib/alloc/frees.h		\
		$(INC_DIR)/libalx/alx/robot/ur/ur.h
UR_UR_SRC	=							\
		$(SRC_DIR)/alx/robot/ur/ur.c

################################################################################
# target: dependencies
#	action

PHONY := all
all: $(DIRS) $(subst .a.o,.a.o ,$(join $(OBJ:.o=.a.o),$(OBJ:.o=.so.o)))


kawasaki:
	@echo	"	MKDIR	build/tmp/alx/robot/$@"
	$(Q)mkdir -p		$@/
ur:
	@echo	"	MKDIR	build/tmp/alx/robot/$@"
	$(Q)mkdir -p		$@/


%.a.s:
	@echo	"	CC	build/tmp/alx/robot/$@"
	$(Q)$(CC) $(CFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CC	build/tmp/alx/robot/$@"
	$(Q)$(CC) $(CFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	build/tmp/alx/robot/$@"
	$(Q)$(AS) $< -o $@


#kawasaki/kawasaki.a.s: $(KW_KW_SRC) $(KW_KW_INC)
#kawasaki/kawasaki.so.s: $(KW_KW_SRC) $(KW_KW_INC)

ur/ur.a.s: $(UR_UR_SRC) $(UR_UR_INC)
ur/ur.so.s: $(UR_UR_SRC) $(UR_UR_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
