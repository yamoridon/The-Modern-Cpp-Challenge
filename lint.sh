#!/usr/bin/env bash -eu

CLANG_TIDY=/usr/local/opt/llvm/bin/clang-tidy
CLANG_TIDY_OPTIONS='-checks=cppcoreguidelines-*,modernize-*,clang-analyzer-*,portability-*,readability-*'

if [ $# != 1 ]; then
    echo "Usage: lint <Xcode project files>"
    echo "Dependencies: clang-tidy, jq, xcpretty"
    exit 1
fi

PROJECT=$1

TMPFILE=$(mktemp)
rm -f compile_commands.json
xcodebuild -project "$PROJECT" clean
xcodebuild -project "$PROJECT" -alltargets build | \
    xcpretty -r json-compilation-database --output $TMPFILE
cat $TMPFILE | \
    perl -pe "s/(-I|-F|-c | -o | -MF |-iquote |--serialize-diagnostics )(((\\\\\\\\ )|[A-Za-z0-9\/\._-])+)/\$1'\$2'/g;" \
         -pe 's/\\\\=/=/g;' \
         -pe 's/\\\\ / /g;' \
         -pe 's/-gmodules / /g;' \
         -pe 's/-fmodules / /g;' | jq > compile_commands.json
FILES=`cat compile_commands.json | jq '.[].file' | sort | uniq`
IFS="
"
for FILE in $FILES; do
    FILE=`echo $FILE | sed 's/"//g'`
    echo -e "\nLinting $FILE:"
    $CLANG_TIDY $CLANG_TIDY_OPTIONS $FILE
done

