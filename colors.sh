#######################################
#echo    including colored output
#######################################
#

# color echos
if [[ -t 1 ]]
then
    # normal
    n='\e[0;0;0m'
    k='\e[0;30m'
    r='\e[0;31m'
    g='\e[0;32m'
    y='\e[0;33m'
    b='\e[0;34m'
    m='\e[0;35m'
    c='\e[0;36m'
    w='\e[0;37m'

    # bright
    N='\e[1m'
    K='\e[1;30m'
    R='\e[1;31m'
    G='\e[1;32m'
    Y='\e[1;33m'
    B='\e[1;34m'
    M='\e[1;35m'
    C='\e[1;36m'
    W='\e[1;37m'
fi
