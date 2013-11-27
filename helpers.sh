. colors.sh

RET_VAL=0

_handle_error()
{
    echo "Error in ${FUNCNAME[1]}:${@}"
    _show_stacktrace

    ERROR_CODE="${1}"
    RET_VAL=$(( ${RET_VAL}|${ERROR_CODE}  ))
    return ${RET_VAL}
}

_show_stacktrace()
{
    depth=$(( ${#FUNCNAME[@]} - 1 ))

    for (( i=0; i<${depth}; i+=1 ))
    do
        n=$(( ${i} + 1 ))
        nn=$(( ${i} + 1 ))
        echo -e "#${i} in ${FUNCNAME[$n]}() \t\tat ${BASH_SOURCE[${nn}]}:${BASH_LINENO[${n}]}"
    done
}


_info_cmake()
{
    echo -e "${G}[info] ${g}${@}${n}"
}

_warning_cmake()
{
    echo -e "${Y}[warning] ${y}${@}${n}"
}

_error_cmake()
{
    rc=$?
    if [[ $rc != 0 ]]
    then
        echo -e "${R}[error]${r} ${@}, error code: ${rc}${n}"
        exit $rc
    fi
}


makeAbsolutePath()
{
    readlink -m $1
}