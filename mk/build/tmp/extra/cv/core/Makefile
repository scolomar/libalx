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
		array.o							\
		contours.o						\
		img.o							\
		pixel.o							\
		rect.o							\
		roi.o


ARRAY_INC	=							\
		$(INC_DIR)/libalx/base/compiler/restrict.hpp		\
		$(INC_DIR)/libalx/extra/cv/core/array.hpp
ARRAY_SRC	=							\
		$(SRC_DIR)/extra/cv/core/array.cpp

CONT_INC	=							\
		$(INC_DIR)/libalx/base/compiler/restrict.hpp		\
		$(INC_DIR)/libalx/base/stdlib/alloc/mallocarrays.hpp	\
		$(INC_DIR)/libalx/extra/cv/core/contours.hpp
CONT_SRC	=							\
		$(SRC_DIR)/extra/cv/core/contours.cpp

IMG_INC		=							\
		$(INC_DIR)/libalx/base/compiler/restrict.hpp		\
		$(INC_DIR)/libalx/base/stdlib/alloc/mallocarrays.hpp	\
		$(INC_DIR)/libalx/extra/cv/core/img.hpp
IMG_SRC		=							\
		$(SRC_DIR)/extra/cv/core/img.cpp

PIXEL_INC	=							\
		$(INC_DIR)/libalx/base/compiler/restrict.hpp		\
		$(INC_DIR)/libalx/extra/cv/core/pixel.hpp
PIXEL_SRC	=							\
		$(SRC_DIR)/extra/cv/core/pixel.cpp

RECT_INC	=							\
		$(INC_DIR)/libalx/base/compiler/restrict.hpp		\
		$(INC_DIR)/libalx/base/stdlib/alloc/mallocarrays.hpp	\
		$(INC_DIR)/libalx/base/stdlib/swap.hpp			\
		$(INC_DIR)/libalx/extra/cv/core/rect.hpp
RECT_SRC	=							\
		$(SRC_DIR)/extra/cv/core/rect.cpp

ROI_INC		=							\
		$(INC_DIR)/libalx/base/compiler/restrict.hpp		\
		$(INC_DIR)/libalx/extra/cv/core/roi.hpp
ROI_SRC		=							\
		$(SRC_DIR)/extra/cv/core/roi.cpp

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
	@echo	"	CXX	build/tmp/extra/cv/core/$@"
	$(Q)$(CC) $(CXXFLAGS_A) -S $< -o $@
%.so.s:
	@echo	"	CXX	build/tmp/extra/cv/core/$@"
	$(Q)$(CC) $(CXXFLAGS_SO) -S $< -o $@
%.o: %.s
	@echo	"	AS	build/tmp/extra/cv/core/$@"
	$(Q)$(AS) $< -o $@


array.a.s: $(ARRAY_SRC) $(ARRAY_INC)
array.so.s: $(ARRAY_SRC) $(ARRAY_INC)

contours.a.s: $(CONT_SRC) $(CONT_INC)
contours.so.s: $(CONT_SRC) $(CONT_INC)

img.a.s: $(IMG_SRC) $(IMG_INC)
img.so.s: $(IMG_SRC) $(IMG_INC)

pixel.a.s: $(PIXEL_SRC) $(PIXEL_INC)
pixel.so.s: $(PIXEL_SRC) $(PIXEL_INC)

rect.a.s: $(RECT_SRC) $(RECT_INC)
rect.so.s: $(RECT_SRC) $(RECT_INC)

roi.a.s: $(ROI_SRC) $(ROI_INC)
roi.so.s: $(ROI_SRC) $(ROI_INC)


PHONY += clean
clean:
	$(Q)rm -f *.o *.s

################################################################################
# Declare the contents of the .PHONY variable as phony.
.PHONY: $(PHONY)




################################################################################
######## End of file ###########################################################
################################################################################
