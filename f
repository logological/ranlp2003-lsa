#!/u/psy/bin/ksh
#
# f(x, y) = x*y*(1-|x-y|)
#
# Usage:
#  f.ksh x y

X=$1
Y=$2

F=$(( $X - $Y ))
if [ $(( $F < 0 )) -ne 0 ]
then
    F=$(( -1 * $F ))
fi
F=$(( $X * $Y * (1 - $F) ))

echo $F
