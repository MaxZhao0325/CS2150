

#include <stdio.h>
#!/bin/bash
echo 'enter the exponent for counter.cpp:'
read value
if ! [[ "$value" = 'quit' ]] ; then
    COUNTER=0
    runtime=0
    while [  $COUNTER -lt 5 ]; do
        echo 'Running iteration '$(($((COUNTER))+1))'...'
        currentruntime=`./a.out "$value" | tail -1`
        echo 'time taken: '$((currentruntime)) 'ms'
        let COUNTER=COUNTER+1
        let runtime=runtime+currentruntime
    done
    echo '5 iterations took '$((runtime)) 'ms'
    echo 'Average time was' $((runtime/5)) 'ms'
fi
