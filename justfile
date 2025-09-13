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

  echo "Watching {{ in }} for changes..."
  echo "Outputting to {{ out }}"
  echo "Executing ./${dest}"

  watchexec --clear --exts c,h \
    "just build {{ in }} ${dest} && echo '' && ./${dest}"
