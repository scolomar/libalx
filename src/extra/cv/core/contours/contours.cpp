/******************************************************************************
 *	Copyright (C) 2018	Alejandro Colomar Andrés		      *
 *	SPDX-License-Identifier:	LGPL-2.0-only			      *
 ******************************************************************************/


/******************************************************************************
 ******* headers **************************************************************
 ******************************************************************************/
#include "libalx/extra/cv/core/contours/contours.hpp"

#include <cstddef>

#include <memory>
#include <vector>

#include <opencv2/core/types.hpp>

#include "libalx/base/compiler/restrict.hpp"
#include "libalx/base/stdlib/alloc/mallocarrays.hpp"


/******************************************************************************
 ******* macros ***************************************************************
 ******************************************************************************/


/******************************************************************************
 ******* enum / struct / union ************************************************
 ******************************************************************************/


/******************************************************************************
 ******* static prototypes ****************************************************
 ******************************************************************************/


/******************************************************************************
 ******* global functions *****************************************************
 ******************************************************************************/
/* ----- alloc / free */
int	alx::CV::alloc_conts	(class std::vector<
					class std::vector<
					class cv::Point_<
					int>>> **contours)
{
	return	alx_mallocarrays(contours, 1);
}

int	alx_cv_alloc_conts	(void **contours)
{
	return	alx::CV::alloc_conts((class std::vector<
					class std::vector<
					class cv::Point_<int>>> **)contours);
}

void	alx::CV::free_conts	(class std::vector<
					class std::vector<
					class cv::Point_<
					int>>> *contours)
{
	free(contours);
}

void	alx_cv_free_conts	(void *contours)
{
	alx::CV::free_conts((class std::vector<
					class std::vector<
					class cv::Point_<int>>> *)contours);
}

/* ----- init / deinit */
void	alx::CV::init_conts	(class std::vector<
					class std::vector<
					class cv::Point_<int>>> *conts)
{
	new (conts)	std::vector<std::vector<cv::Point_<int>>>();
}

void	alx_cv_init_conts	(void *conts)
{
	return	alx::CV::init_conts((class std::vector<
					class std::vector<
					class cv::Point_<int>>> *)conts);
}

void	alx::CV::deinit_conts	(class std::vector<
					class std::vector<
					class cv::Point_<int>>> *conts)
{
	std::destroy_at(conts);
}

void	alx_cv_deinit_conts	(void *conts)
{
	alx::CV::deinit_conts((class std::vector<
					class std::vector<
					class cv::Point_<int>>> *)conts);
}

/* ----- Extract */
int	alx::CV::extract_conts	(const class std::vector<
					class std::vector<
					class cv::Point_<int>>> *restrict conts,
				 const class std::vector<
					class cv::Point_<int>> **restrict cont,
				 ptrdiff_t *restrict size)
{
	ptrdiff_t	sz;

	sz	= conts->size();
	if (sz <= 0)
		return	-1;
	if (cont)
		*cont	= &(*conts)[0];
	if (size)
		*size	= sz;
	return	0;
}

int	alx_cv_extract_conts	(const void *restrict conts,
				 const void **restrict cont,
				 ptrdiff_t *restrict size)
{
	return	alx::CV::extract_conts((const class std::vector<
						class std::vector<
						class cv::Point_<int>>> *)conts,
					(const class std::vector<
						class cv::Point_<int>> **)cont,
					size);
}

int	alx::CV::extract_conts_cont(const class std::vector<
					class cv::Point_<int>> **restrict cont,
				 const class std::vector<
					class std::vector<
					class cv::Point_<int>>> *restrict conts,
				 ptrdiff_t i)
{

	if (i < 0 || (size_t)i >= conts->size())
		return	-1;
	*cont	= &(*conts)[i];

	return	0;
}

int	alx_cv_extract_conts_cont(const void **restrict cont,
				 const void *restrict conts, ptrdiff_t i)
{
	return	alx::CV::extract_conts_cont((const class std::vector<
						class cv::Point_<int>> **)cont,
					 (const class std::vector<
						class std::vector<
						class cv::Point_<int>>> *)conts,
					 i);
}


/******************************************************************************
 ******* static function definitions ******************************************
 ******************************************************************************/


/******************************************************************************
 ******* end of file **********************************************************
 ******************************************************************************/
