OK="\033[0;32m[OK]\033[0m"
KO="\033[0;31m[KO]\033[0m"
CompileError="\033[0;33m[CompileError]\033[0m"
LEAK="\033[0;33m[LEAK]\033[0m"
SEGV="\033[0;33m[SEGV]\033[0m"
TimeOut="\033[0;33m[TimeOut]\033[0m"
ReadCountError="\033[0;33m[ReadCountError]\033[0m"
MallocErrorSEGV="\033[0;33m[MallocErrorSEGV]\033[0m"
MallocErrorLeak="\033[0;33m[MallocErrorLeak]\033[0m"
StaticError="\033[0;33m[StaticError]\033[0m"

if [ "$1" = "OK" ]; then
    printf "$OK"
elif [ "$1" = "KO" ]; then
    printf "$KO"
elif [ "$1" = "CompileError" ]; then
    printf "$CompileError"
elif [ "$1" = "LEAK" ]; then
    printf "$LEAK"
elif [ "$1" = "SEGV" ]; then
    printf "$SEGV"
elif [ "$1" = "TimeOut" ]; then
    printf "$TimeOut"
elif [ "$1" = "ReadCountError" ]; then
    printf "$ReadCountError"
elif [ "$1" = "MallocErrorSEGV" ]; then
    printf "$MallocErrorSEGV"
elif [ "$1" = "MallocErrorLeak" ]; then
    printf "$MallocErrorLeak"
elif [ "$1" = "StaticError" ]; then
    printf "$StaticError"
fi