#!/usr/bin/env sh

# Adapted from:
# https://www.reddit.com/r/cmake/comments/1biuopg/crosscompile_from_linux_to_windows/
# NOTE: this requires that you accept the MVSC license!
exec clang-cl --target=x86_64-pc-windows-msvc \
	-vctoolsdir vendored/.xwin-cache/splat/crt \
	-winsdkdir vendored/.xwin-cache/splat/sdk \
	-fuse-ld=lld "$@"
