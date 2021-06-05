find . -exec grep '[ \t]*#include[ \t][ \t]*["<][^">][">]' {} ';' \
    | sed 's/^[ \t]*#include[ \t][ \t]*["<]//' \
    | sed 's/[">].*$//' \
    | sort \
    | uniq -c \
    | sort -r -k1 -n \
