default:
	@just --list

build in out:
  zig cc {{ in }} -o {{ out }}

watch in out="tmp":
  #!/usr/bin/env bash

  set -euo pipefail

  filename=$(basename "{{ in }}")
  name=${filename%.*}
  extension=${filename##*.}
  dest="{{ out }}/${name}"

  watchexec --clear --exts c,h \
    "just build {{ in }} ${dest} && echo '' && ./${dest}"
