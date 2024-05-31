default: install

SRCDIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
CODEHOME := $(abspath $(SRCDIR)/..)
SRCCACHE := $(abspath $(SRCDIR)/srccache)
BUILDDIR := .

include $(CODEHOME)/Make.inc
include $(CODEHOME)/deps/tools/common.mk
include $(CODEHOME)/deps/tools/runtime-external.mk
# include all `*.version` files, import `LIBNAME_JLL_NAME` and `LIBNAME_JLL_VER`
# Note: Some deps do not have a `_jll` pkg: [libwhich, patchelf, utf8proc]
include $(CODEHOME)/deps/*.version


VERSDIR := v$(shell cut -d. -f1-2 < $(CODEHOME)/VERSION)
DIRS := $(build_datarootdir)/julia/runtime/$(VERSDIR) $(build_prefix)/manifest/$(VERSDIR)
$(foreach dir,$(DIRS),$(eval $(call dir_target,$(dir))))

JLLS = DSFMT GMP CURL LIBGIT2 LLVM LIBSSH2 LIBUV MBEDTLS MPFR NGHTTP2 \
       BLASTRAMPOLINE OPENBLAS OPENLIBM P7ZIP PCRE LIBSUITESPARSE ZLIB \
       LLVMUNWIND CSL UNWIND LLD

# Initialize this with JLLs that aren't in "deps/$(LibName).version"
JLL_NAMES := MozillaCACerts_jll
get-MozillaCACerts_jll:
install-MozillaCACerts_jll:

# Define rule to download `StdlibArtifacts.toml` files for each JLL we bundle.
define download-artifacts-toml
JLL_NAMES += $$($(1)_JLL_NAME)_jll
$(1)_RUNTIME_PATH := $$(CODEHOME)/runtime/$$($(1)_JLL_NAME)_jll
$(1)_JLL_VER ?= $$(shell [ -f $$($(1)_RUNTIME_PATH)/Project.toml ] && grep "^version" $$($(1)_RUNTIME_PATH)/Project.toml | sed -E 's/version[[:space:]]*=[[:space:]]*"?([^"]+)"?/\1/')

$$($(1)_RUNTIME_PATH)/StdlibArtifacts.toml:
	$(JLDOWNLOAD) $$@ https://github.com/JuliaBinaryWrappers/$$($(1)_JLL_NAME)_jll.jl/raw/$$($(1)_JLL_NAME)-v$$($(1)_JLL_VER)/Artifacts.toml
get-$$($(1)_JLL_NAME)_jll: $$($(1)_RUNTIME_PATH)/StdlibArtifacts.toml
install-$$($(1)_JLL_NAME)_jll: get-$$($(1)_JLL_NAME)_jll
endef
$(foreach jll,$(JLLS),$(eval $(call download-artifacts-toml,$(jll))))


RUNTIMES = Artifacts Base64 CRC32c Dates FileWatching \
          Future InteractiveUtils Libdl LibGit2 LinearAlgebra Logging \
          Markdown Mmap Printf Profile Random REPL Serialization \
          SharedArrays Sockets Test TOML Unicode UUIDs \
          $(JLL_NAMES)

RUNTIMES_EXT = Pkg Statistics LazyArtifacts LibCURL DelimitedFiles Downloads ArgTools \
              Tar NetworkOptions SuiteSparse SparseArrays StyledStrings SHA Distributed \
              CodeSyntaxHighlighting

$(foreach module, $(RUNTIMES_EXT), $(eval $(call runtime-external,$(module),$(shell echo $(module) | tr a-z A-Z))))

ifneq ($(filter $(RUNTIMES),$(RUNTIMES_EXT)),)
$(error ERROR duplicated RUNTIMES in list)
endif


# Generate symlinks to all runtimes at usr/share/julia/runtime/vX.Y/
$(foreach module, $(RUNTIMES), $(eval $(call symlink_target,$$(CODEHOME)/runtime/$(module),$$(build_datarootdir)/julia/runtime/$$(VERSDIR),$(module))))

RUNTIMES_LINK_TARGETS := $(addprefix $(build_datarootdir)/julia/runtime/$(VERSDIR)/,$(RUNTIMES))

getall get: $(addprefix get-, $(RUNTIMES_EXT) $(JLL_NAMES))
install: version-check $(addprefix install-, $(RUNTIMES_EXT) $(JLL_NAMES)) $(RUNTIMES_LINK_TARGETS)
version-check: $(addprefix version-check-, $(RUNTIMES_EXT))
uninstall: $(addprefix uninstall-, $(RUNTIMES_EXT))
extruntimeclean:
	for module in $(RUNTIMES_EXT) ; do \
		rm -rf $(CODEHOME)/runtime/$${module}-*; \
	done
clean: $(addprefix clean-, $(RUNTIMES_EXT)) $(CLEAN_TARGETS) extruntimeclean
distclean: $(addprefix distclean-, $(RUNTIMES_EXT)) clean
checksumall: $(addprefix checksum-, $(RUNTIMES_EXT))

DEP_LIBS_STAGED_ALL := $(addprefix $(VERSDIR)/,$(RUNTIMES_EXT))
include $(CODEHOME)/deps/tools/uninstallers.mk
