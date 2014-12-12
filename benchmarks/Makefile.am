# Copyright(c)'1994-2009 by The Givaro group
# This file is part of Givaro.
# Givaro is governed by the CeCILL-B license under French law
# and abiding by the rules of distribution of free software.
# see the COPYRIGHT file for more details.

SUBDIRS =
benchmarks: $(BENCHMARKS)

AM_CPPFLAGS=-I$(top_srcdir)

PERFPUBLISHERFILE=benchmarks-report.xml

OPTFLAGS=
OPTLINKS=

AM_CXXFLAGS = @DEFAULT_CFLAGS@
AM_CPPFLAGS += $(OPTFLAGS) $(GMP_CFLAGS) -I$(top_srcdir)/src/kernel/system -I$(top_srcdir)/src/kernel/recint

LDADD = $(OPTLINKS) -L${top_srcdir}/src -L${top_srcdir}/src/.libs -lgivaro $(GMP_LIBS) $(LDFLAGS)
AM_LDFLAGS=-static

BENCHMARKS=				\
	benchmark-recint_exp			\
	benchmark-recint_inv_arazi	\
	benchmark-recint_inv_naive	\
	benchmark-recint_mul

CLEANFILES = $(BENCHMARKS) $(PERFPUBLISHERFILE)

EXTRA_PROGRAMS = $(BENCHMARKS)

benchmark_recint_exp_SOURCES = benchmark-recint_exp.C
benchmark_recint_inv_arazi_SOURCES = benchmark-recint_inv_arazi.C
benchmark_recint_inv_naive_SOURCES = benchmark-recint_inv_naive.C
benchmark_recint_mul_SOURCES = benchmark-recint_mul.C

# Perfpublisher script interaction - AB 2014/11/17
perfpublisher:
	+./perfpublisher.sh "$(PERFPUBLISHERFILE)" "$(BENCHMARKS)" "$(CXX)"
