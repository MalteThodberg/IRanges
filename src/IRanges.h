#include "../inst/include/IRanges_defines.h"
#include <string.h>

#define DEBUG_IRANGES 1

#define INIT_STATIC_SYMBOL(NAME) \
{ \
	if (NAME ## _symbol == NULL) \
		NAME ## _symbol = install(# NAME); \
}


/* sort_utils.c */

void _sort_int_array(
	int *x,
	int x_nelt
);

void _get_int_array_order(
	const int *x,
	int x_nelt,
	int *order
);


/* AEbufs.c */

SEXP debug_AEbufs();

void _IntAE_set_val(
	const IntAE *int_ae,
	int val
);

IntAE _new_IntAE(
	int buflength,
	int nelt,
	int val
);

void _IntAE_insert_at(
	IntAE *int_ae,
	int at,
	int val
);

void _IntAE_append(
	IntAE *int_ae,
	const int *newvals,
	int nnewval
);

void _IntAE_delete_at(
	IntAE *int_ae,
	int at
);

void _IntAE_shift(
	const IntAE *int_ae,
	int shift
);

void _IntAE_sum_and_shift(
	const IntAE *int_ae1,
	const IntAE *int_ae2,
	int shift
);

void _IntAE_append_shifted_vals(
	IntAE *int_ae,
	const int *newvals,
	int nnewval,
	int shift
);

void _IntAE_qsort(IntAE *int_ae);

void _IntAE_delete_adjdups(IntAE *int_ae);

SEXP _IntAE_asINTEGER(const IntAE *int_ae);

IntAE _INTEGER_asIntAE(SEXP x);

IntAE _CHARACTER_asIntAE(
	SEXP x,
	int keyshift
);

IntAEAE _new_IntAEAE(
	int buflength,
	int nelt
);

void _IntAEAE_insert_at(
	IntAEAE *int_aeae,
	int at,
	const IntAE *int_ae
);

void _IntAEAE_eltwise_append(
	const IntAEAE *int_aeae1,
	const IntAEAE *int_aeae2
);

void _IntAEAE_shift(
	const IntAEAE *int_aeae,
	int shift
);

void _IntAEAE_sum_and_shift(
	const IntAEAE *int_aeae1,
	const IntAEAE *int_aeae2,
	int shift
);

SEXP _IntAEAE_asLIST(
	const IntAEAE *int_aeae,
	int mode
);

IntAEAE _LIST_asIntAEAE(SEXP x);

SEXP _IntAEAE_toEnvir(
	const IntAEAE *int_aeae,
	SEXP envir,
	int keyshift
);

RangeAE _new_RangeAE(
	int buflength,
	int nelt
);

void _RangeAE_insert_at(
	RangeAE *range_ae,
	int at,
	int start,
	int width
);

SEXP _RangeAE_asIRanges(const RangeAE *range_ae);

CharAE _new_CharAE(int buflength);

CharAE _new_CharAE_from_string(const char *string);

void _CharAE_insert_at(
	CharAE *char_ae,
	int at,
	char c
);

void _append_string_to_CharAE(
	CharAE *char_ae,
	const char *string
);

SEXP _CharAE_asRAW(const CharAE *char_ae);

SEXP _CharAE_asLOGICAL(const CharAE *char_ae);

CharAEAE _new_CharAEAE(
	int buflength,
	int nelt
);

void _CharAEAE_insert_at(
	CharAEAE *char_aeae,
	int at,
	const CharAE *char_ae
);

void _append_string_to_CharAEAE(
	CharAEAE *char_aeae,
	const char *string
);

SEXP _CharAEAE_asCHARACTER(const CharAEAE *char_aeae);


/* memcpy_utils.c */

SEXP debug_memcpy_utils();

int _IRanges_memcmp(
	const char *a,
	int ia,
	const char *b,
	int ib,
	int n,
	size_t size
);

void _IRanges_memcpy_from_i1i2(
	int i1,
	int i2,
	char *dest,
	size_t dest_nelt,
	const char *src,
	size_t src_nelt,
	size_t size
);

void _IRanges_memcpy_from_subset(
	const int *subset,
	int n,
	char *dest,
	size_t dest_nelt,
	const char *src,
	size_t src_nelt,
	size_t size
);

void _IRanges_memcpy_to_i1i2(
	int i1,
	int i2,
	char *dest,
	size_t dest_nelt,
	const char *src,
	size_t src_nelt,
	size_t size
);

void _IRanges_memcpy_to_subset(
	const int *subset,
	int n,
	char *dest,
	size_t dest_nelt,
	const char *src,
	size_t src_nelt,
	size_t size
);

void _IRanges_charcpy_from_i1i2_with_lkup(
	int i1,
	int i2,
	char *dest,
	int dest_length,
	const char *src,
	int src_length,
	const int *lkup,
	int lkup_length
);

void _IRanges_charcpy_from_subset_with_lkup(
	const int *subset,
	int n,
	char *dest,
	int dest_length,
	const char *src,
	int src_length,
	const int *lkup,
	int lkup_length
);

void _IRanges_charcpy_to_i1i2_with_lkup(
	int i1,
	int i2,
	char *dest,
	int dest_length,
	const char *src,
	int src_length,
	const int *lkup,
	int lkup_length
);

void _IRanges_charcpy_to_subset_with_lkup(
	const int *subset,
	int n,
	char *dest,
	int dest_length,
	const char *src,
	int src_length,
	const int *lkup,
	int lkup_length
);

void _IRanges_reverse_memcpy_from_i1i2(
	int i1,
	int i2,
	char *dest,
	size_t dest_nelt,
	const char *src,
	size_t src_nelt,
	size_t size
);

void _IRanges_reverse_charcpy_from_i1i2_with_lkup(
	int i1,
	int i2,
	char *dest,
	int dest_length,
	const char *src,
	int src_length,
	const int *lkup,
	int lkup_length
);

void _IRanges_memcpy_from_i1i2_to_complex(
	int i1,
	int i2,
	Rcomplex *dest,
	int dest_length,
	const char *src,
	int src_length,
	const Rcomplex *lkup,
	int lkup_length
);


/* SEXP_utils.c */

const char *_get_classname(SEXP x);

SEXP address_asSTRSXP(SEXP s);

SEXP listofvectors_lengths(SEXP x);

SEXP safe_strexplode(SEXP s);

SEXP Integer_diff_with_0(SEXP x);

SEXP Integer_sorted_merge(
	SEXP x,
	SEXP y
);

SEXP findIntervalAndStartFromWidth(
	SEXP x,
	SEXP vec
);


/* Sequence_class.c */

const char *_get_Sequence_elementType(SEXP x);

SEXP vector_seqselect(SEXP x, SEXP start, SEXP width);


/* IRanges_class.c */

SEXP debug_IRanges_class();

SEXP _get_IRanges_start(SEXP x);

SEXP _get_IRanges_width(SEXP x);

SEXP _get_IRanges_names(SEXP x);

int _get_IRanges_length(SEXP x);

cachedIRanges _cache_IRanges(SEXP x);

int _get_cachedIRanges_length(const cachedIRanges *cached_x);

int _get_cachedIRanges_elt_width(
	const cachedIRanges *cached_x,
	int i
);

int _get_cachedIRanges_elt_start(
	const cachedIRanges *cached_x,
	int i
);

int _get_cachedIRanges_elt_end(
	const cachedIRanges *cached_x,
	int i
);

SEXP _get_cachedIRanges_elt_name(
	const cachedIRanges *cached_x,
	int i
);

cachedIRanges _sub_cachedIRanges(
	const cachedIRanges *cached_x,
	int offset,
	int length
);

void _set_IRanges_names(
	SEXP x,
	SEXP names
);

void _copy_IRanges_slots(
	SEXP x,
	SEXP x0
);

SEXP _new_IRanges(
	const char *classname,
	SEXP start,
	SEXP width,
	SEXP names
);

SEXP _alloc_IRanges(
	const char *classname,
	int length
);

SEXP IRanges_from_integer(SEXP x);

SEXP NormalIRanges_from_logical(SEXP x);


/* IRanges_constructor.c */

SEXP solve_user_SEW0(
	SEXP start,
	SEXP end,
	SEXP width
);

SEXP solve_user_SEW(
	SEXP refwidths,
	SEXP start,
	SEXP end,
	SEXP width,
	SEXP translate_negative_coord,
	SEXP allow_nonnarrowing
);


/* IRanges_utils.c */

SEXP debug_IRanges_utils();

SEXP IRanges_reduce(
	SEXP x,
	SEXP with_inframe_start
);


/* coverage */

SEXP IRanges_coverage(
	SEXP x,
	SEXP weight,
	SEXP width
);


/* CompressedIRangesList_class.c */

cachedCompressedIRangesList _cache_CompressedIRangesList(SEXP x);

cachedIRanges _get_cachedCompressedIRangesList_elt(
	const cachedCompressedIRangesList *cached_x,
	int i
);

SEXP CompressedIRangesList_summary(SEXP object);


/* Grouping_class.c */

SEXP debug_Grouping_class();

SEXP _get_H2LGrouping_high2low(SEXP x);

SEXP _get_H2LGrouping_low2high(SEXP x);

SEXP H2LGrouping_members(
	SEXP x,
	SEXP group_ids
);

SEXP H2LGrouping_vmembers(
	SEXP x,
	SEXP group_ids_list
);


/* Ranges_comparison.c */

void _get_Ranges_order(
	int *order,
	int nelt,
	const int *start,
	const int *width,
	int decreasing,
	int base1
);

SEXP Ranges_order(
	SEXP start,
	SEXP width,
	SEXP decreasing
);


/* Rle_class.c */

SEXP Rle_constructor(
	SEXP x,
	SEXP count
);

SEXP Rle_start(SEXP x);

SEXP Rle_end(SEXP x);

SEXP Rle_window_aslist(
	SEXP x,
	SEXP runStart,
	SEXP runEnd,
	SEXP offsetStart,
	SEXP offsetEnd
);

SEXP Rle_window(
	SEXP x,
	SEXP runStart,
	SEXP runEnd,
	SEXP offsetStart,
	SEXP offsetEnd,
	SEXP ans
);


/* Rle_utils.c */
SEXP Rle_rollSum(
	SEXP x,
	SEXP width
);

SEXP Rle_rollQ(
	SEXP x,
	SEXP width,
	SEXP which
);


/* RleViews_utils.c */

SEXP RleViews_viewMins(
	SEXP x,
	SEXP na_rm
);

SEXP RleViews_viewMaxs(
	SEXP x,
	SEXP na_rm
);

SEXP RleViews_viewSums(
	SEXP x,
	SEXP na_rm
);

SEXP RleViews_viewWhichMins(
	SEXP x,
	SEXP na_rm
);

SEXP RleViews_viewWhichMaxs(
	SEXP x,
	SEXP na_rm
);


/* SharedVector_class.c */

SEXP debug_SharedVector_class();

SEXP externalptr_tagtype(SEXP x);

SEXP externalptr_show(SEXP x);

SEXP externalptr_new();

SEXP _get_SharedVector_tag(SEXP x);

int _get_SharedVector_length(SEXP x);

SEXP _new_SharedVector(const char *classname, SEXP tag);

SEXP SharedVector_length(SEXP x);

SEXP _get_SharedVector_Pool_xp_list(SEXP x);


/* SharedRaw_utils.c */

SEXP debug_SharedRaw_utils();

SEXP SharedRaw_new(
	SEXP length,
	SEXP val
);

SEXP SharedRaw_address0(SEXP x);

SEXP SharedRaw_memcmp(
	SEXP x1,
	SEXP start1,
	SEXP x2,
	SEXP start2,
	SEXP width
);

SEXP SharedRaw_memcpy(
	SEXP dest,
	SEXP dest_start,
	SEXP src,
	SEXP src_start,
	SEXP width
);

SEXP SharedRaw_copy_from_i1i2(
	SEXP dest,
	SEXP src,
	SEXP imin,
	SEXP imax
);

SEXP SharedRaw_copy_from_subset(
	SEXP dest,
	SEXP src,
	SEXP subset
);

SEXP SharedRaw_read_chars_from_i1i2(
	SEXP src,
	SEXP imin,
	SEXP imax
);

SEXP SharedRaw_read_chars_from_subset(
	SEXP src,
	SEXP subset
);

SEXP SharedRaw_write_chars_to_i1i2(
	SEXP dest,
	SEXP imin,
	SEXP imax,
	SEXP string
);

SEXP SharedRaw_write_chars_to_subset(
	SEXP dest,
	SEXP subset,
	SEXP string
);

SEXP SharedRaw_read_ints_from_i1i2(
	SEXP src,
	SEXP imin,
	SEXP imax
);

SEXP SharedRaw_read_ints_from_subset(
	SEXP src,
	SEXP subset
);

SEXP SharedRaw_write_ints_to_i1i2(
	SEXP dest,
	SEXP imin,
	SEXP imax,
	SEXP val
);

SEXP SharedRaw_write_ints_to_subset(
	SEXP dest,
	SEXP subset,
	SEXP val
);

SEXP SharedRaw_read_enc_chars_from_i1i2(
	SEXP src,
	SEXP imin,
	SEXP imax,
	SEXP lkup
);

SEXP SharedRaw_read_enc_chars_from_subset(
	SEXP src,
	SEXP subset,
	SEXP lkup
);

SEXP SharedRaw_write_enc_chars_to_i1i2(
	SEXP dest,
	SEXP imin,
	SEXP imax,
	SEXP string,
	SEXP lkup
);

SEXP SharedRaw_write_enc_chars_to_subset(
	SEXP dest,
	SEXP subset,
	SEXP string,
	SEXP lkup
);

SEXP SharedRaw_read_complexes_from_i1i2(
	SEXP src,
	SEXP imin,
	SEXP imax,
	SEXP lkup
);

SEXP SharedRaw_read_complexes_from_subset(
	SEXP src,
	SEXP subset,
	SEXP lkup
);

SEXP SharedRaw_translate_copy_from_i1i2(
	SEXP dest,
	SEXP src,
	SEXP imin,
	SEXP imax,
	SEXP lkup
);

SEXP SharedRaw_translate_copy_from_subset(
	SEXP dest,
	SEXP src,
	SEXP subset,
	SEXP lkup
);

SEXP SharedRaw_reverse_copy_from_i1i2(
	SEXP dest,
	SEXP src,
	SEXP imin,
	SEXP imax
);

SEXP SharedRaw_reverse_translate_copy_from_i1i2(
	SEXP dest,
	SEXP src,
	SEXP imin,
	SEXP imax,
	SEXP lkup
);


/* SharedInteger_utils.c */

SEXP debug_SharedInteger_utils();

SEXP SharedInteger_new(
	SEXP length,
	SEXP val
);

SEXP SharedInteger_get_show_string(SEXP x);

SEXP SharedInteger_memcmp(
	SEXP x1,
	SEXP start1,
	SEXP x2,
	SEXP start2,
	SEXP width
);

SEXP SharedInteger_copy_from_i1i2(
	SEXP dest,
	SEXP src,
	SEXP imin,
	SEXP imax
);

SEXP SharedInteger_copy_from_subset(
	SEXP dest,
	SEXP src,
	SEXP subset
);

SEXP SharedInteger_read_ints_from_i1i2(
	SEXP src,
	SEXP imin,
	SEXP imax
);

SEXP SharedInteger_read_ints_from_subset(
	SEXP src,
	SEXP subset
);

SEXP SharedInteger_write_ints_to_i1i2(
	SEXP dest,
	SEXP imin,
	SEXP imax,
	SEXP val
);

SEXP SharedInteger_write_ints_to_subset(
	SEXP dest,
	SEXP subset,
	SEXP val
);


/* SharedDouble_utils.c */

SEXP debug_SharedDouble_utils();

SEXP SharedDouble_new(
	SEXP length,
	SEXP val
);

SEXP SharedDouble_get_show_string(SEXP x);

SEXP SharedDouble_memcmp(
	SEXP x1,
	SEXP start1,
	SEXP x2,
	SEXP start2,
	SEXP width
);

SEXP SharedDouble_read_nums_from_i1i2(
	SEXP src,
	SEXP imin,
	SEXP imax
);

SEXP SharedDouble_read_nums_from_subset(
	SEXP src,
	SEXP subset
);

SEXP SharedDouble_write_nums_to_i1i2(
	SEXP dest,
	SEXP imin,
	SEXP imax,
	SEXP val
);

SEXP SharedDouble_write_nums_to_subset(
	SEXP dest,
	SEXP subset,
	SEXP val
);


/* XVector_class.c */

SEXP debug_XVector_class();

SEXP _get_XVector_shared(SEXP x);

SEXP _get_XVector_offset(SEXP x);

SEXP _get_XVector_length(SEXP x);

SEXP _get_XVector_tag(SEXP x);

cachedCharSeq _cache_XRaw(SEXP x);

SEXP _new_XVector(
	const char *classname,
	SEXP shared,
	int offset,
	int length
);

SEXP _new_XRaw_from_tag(
	const char *classname,
	SEXP tag
);

SEXP _new_XInteger_from_tag(
	const char *classname,
	SEXP tag
);

SEXP _new_XDouble_from_tag(
	const char *classname,
	SEXP tag
);


/* XVectorList_class.c */

SEXP debug_XVectorList_class();

SEXP _get_XVectorList_pool(SEXP x);

SEXP _get_XVectorList_ranges(SEXP x);

int _get_XVectorList_length(SEXP x);

cachedXVectorList _cache_XVectorList(SEXP x);

int _get_cachedXVectorList_length(const cachedXVectorList *cached_x);

cachedCharSeq _get_cachedXVectorList_elt(
	const cachedXVectorList *cached_x,
	int i
);


/* XIntegerViews_class.c */

SEXP XIntegerViews_slice(
	SEXP xint,
	SEXP lower,
	SEXP upper
);


/* XIntegerViews_utils.c */

SEXP XIntegerViews_viewMins(
	SEXP x,
	SEXP na_rm
);

SEXP XIntegerViews_viewMaxs(
	SEXP x,
	SEXP na_rm
);

SEXP XIntegerViews_viewSums(
	SEXP x,
	SEXP na_rm
);

SEXP XIntegerViews_viewWhichMins(
	SEXP x,
	SEXP na_rm
);

SEXP XIntegerViews_viewWhichMaxs(
	SEXP x,
	SEXP na_rm
);


/* XDoubleViews_class.c */

SEXP XDoubleViews_slice(
	SEXP xdouble,
	SEXP lower,
	SEXP upper,
	SEXP include_lower,
	SEXP include_upper
);
