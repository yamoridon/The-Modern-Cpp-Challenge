#!/usr/bin/env bash -eu

PROJECT='The Modern Cpp Challenge.xcodeproj'

TMPFILE=$(mktemp)
brew list llvm > $TMPFILE
CLANG_FORMAT=`cat $TMPFILE | grep clang-format$ | head -1`
CLANG_TIDY=`cat $TMPFILE  | grep clang-tidy$ | head -1`
RUN_CLANG_TIDY=`cat $TMPFILE | grep run-clang-tidy.py$ | head -1`
RUN_CLANG_TIDY_OPTIONS='-checks=cert-*,clang-analyzer-*,cppcoreguidelines-*,misc-*,modernize-*,performance-*,portability-*,readability-* -header-filter=.* -fix'

TMPFILE=$(mktemp)
rm compile_commands.json
xcodebuild -project "$PROJECT" clean | xcpretty
xcodebuild -project "$PROJECT" -alltargets -configuration Release -arch `uname -m` build | \
    xcpretty -r json-compilation-database --output $TMPFILE
cat $TMPFILE | \
    perl -pe "s/(-I|-F|-c | -o | -MF |-iquote |--serialize-diagnostics )(((\\\\\\\\ )|[A-Za-z0-9\/\._-])+)/\$1'\$2'/g;" \
         -pe 's/\\\\=/=/g;' \
         -pe 's/\\\\ / /g;' \
         -pe 's/-gmodules / /g;' \
         -pe 's/-fmodules / /g;' > compile_commands.json
rm $TMPFILE
export PATH=`dirname $CLANG_TIDY`:$PATH
$RUN_CLANG_TIDY $RUN_CLANG_TIDY_OPTIONS
find . \( -name "*.cpp" -o -name "*.h" \) -exec $CLANG_FORMAT -style=Google -i {} \;

